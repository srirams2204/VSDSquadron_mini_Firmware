#include "scheduler.h"
#include "timer.h" 

#define MAX_TASKS 5
static Task_t taskList[MAX_TASKS];
static uint8_t taskCount = 0;
static volatile uint32_t system_ticks = 0;

void OS_Tick(void) {
    system_ticks++;
}

void OS_Init(void) {
    Timer_Init(); 
    taskCount = 0;
    system_ticks = 0;
}

void OS_AddTask(TaskFunction_t func, uint32_t period) {
    if (taskCount < MAX_TASKS) {
        taskList[taskCount].taskFunc = func;
        taskList[taskCount].period_ms = period;
        taskList[taskCount].last_run = 0;
        taskCount++;
    }
}

void OS_Run(void) {
    Delay_ms(1); 
    system_ticks++; 

    for (int i = 0; i < taskCount; i++) {
        uint32_t current_time = system_ticks;
        if ((current_time - taskList[i].last_run) >= taskList[i].period_ms) {
            taskList[i].taskFunc(); // Execute Task
            taskList[i].last_run = current_time;
        }
    }
}

uint32_t OS_GetTick(void) {
    return system_ticks;
}