# Task 4 – Evidence of Execution

**Platform:** VSDSquadron Mini (CH32V003 RISC-V)

---

## UART Evidence

### Serial Terminal Configuration

| Parameter | Value |
|----------|-------|
| Tool | VS Code Serial Monitor |
| Baud Rate | 9600 |
| Data Bits | 8 |
| Stop Bits | 1 |
| Parity | None |

---

## RTOS Task Verification – UART Logs

The following screenshot demonstrates the **Cooperative Scheduler** in action.  
You can observe the interleaved execution of three independent tasks:

- LED Blink  
- System Status  
- Button Input  

All tasks execute at their respective deterministic intervals.

**Observation:**

<center>
<img src="../pics/mini-rtos-serial.png" alt="Mini-RTOS Serial Output" width="900">
</center>

---

## Hardware Evidence – System Setup

To verify the multi-driver integration, the board was configured with:

- External LED on **PD6**  
- Push-button on **PD4**  

**Setup Image:**

<center>
<img src="../pics/task4_setup.jpeg" alt="Task 4 Hardware Setup" width="900">
</center>

---

## Explanation

The Mini-RTOS uses a **tick-based cooperative scheduler** to manage multiple drivers  
(GPIO, UART, and Timer) simultaneously.

---

## Workflow

### 1. Task Registration

```c
OS_Init();

OS_AddTask(Task_Input, 1000);  // Polling Button every 1s
OS_AddTask(Task_Blink, 3000);  // Toggling LED every 3s
OS_AddTask(Task_Status, 5000); // System Report every 5s
```

- **Task A (Blink):** Manages the LED state machine.  
- **Task B (Status):** Formats and sends system health data over UART.  
- **Task C (Input):** Reads the GPIO state of the physical push-button.  

---

### 2. Scheduler Execution

The `OS_Run()` engine increments system ticks and compares them against  
each task's requested period.

Tasks are executed **sequentially** only when their specific time interval  
has elapsed, ensuring deterministic behavior.

---

## Verification Summary

This evidence confirms that:

- The Cooperative Scheduler correctly switches between multiple tasks without a hardware OS.  
- Multi-driver integration (GPIO + UART + Timer) is successful.  
- Input events (button presses) are detected and logged via UART in real-time.  
- The firmware demonstrates clean API boundaries and modular architecture.  