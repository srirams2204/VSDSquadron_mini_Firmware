# API Reference Guide

## Scheduler APIs

### OS_Init()
**Description:** Initializes the hardware timer and resets the system tick counter.  
**Constraints:** Must be called before adding tasks.

### OS_AddTask(TaskFunction_t func, uint32_t period_ms)
**Description:** Registers a task for periodic execution.  
**Parameters:**  
- func: Task function pointer  
- period_ms: Execution interval  
**Example:**
```c
OS_AddTask(Task_Blink, 500);
```

### OS_Run()
**Description:** Core scheduler engine.