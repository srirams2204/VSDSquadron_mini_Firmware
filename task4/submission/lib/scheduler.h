#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef void (*TaskFunction_t)(void);

typedef struct {
    TaskFunction_t taskFunc;  
    uint32_t period_ms;       
    uint32_t last_run;        
} Task_t;

void OS_Init(void);
void OS_AddTask(TaskFunction_t func, uint32_t period);
void OS_Run(void); 
uint32_t OS_GetTick(void); 

#endif