#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

// Define a function pointer type for tasks
typedef void (*TaskFunction_t)(void);

// Task Control Block (TCB)
typedef struct {
    TaskFunction_t taskFunc;  // Pointer to the task function
    uint32_t period_ms;       // How often to run (in ms)
    uint32_t last_run;        // Last time it ran (system ticks)
} Task_t;

// API Functions
void OS_Init(void);
void OS_AddTask(TaskFunction_t func, uint32_t period);
void OS_Run(void); // The "kernel" loop
uint32_t OS_GetTick(void); // Returns current system time

#endif