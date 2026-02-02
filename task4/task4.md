# Task 4 – Mini-RTOS (Cooperative Scheduler)

**Platform:** VSDSquadron Mini (CH32V003 RISC-V)

---

## Overview

Task 4 is the capstone project involving the integration of multiple drivers into a  
**Mini-RTOS (Cooperative Scheduler)**.

This project implements a **tick-based kernel** that allows multiple *tasks* to run on the  
VSDSquadron Mini board with clear deterministic behavior.

**Project-8: Mini-RTOS Implementation**  
**Drivers Used:** UART, GPIO, Timer

---

## Firmware Architecture

The system follows a layered architecture as shown in the stack diagram below:

<center>
<img src="../pics/firmware_stack.svg" alt="Firmware Stack Diagram" width="500">
</center>

---

## Implemented Tasks

| Task | Period | Action |
|------|--------|--------|
| Task A | 3000 ms | Toggles LED state (GPIO Output) |
| Task B | 5000 ms | Prints system heartbeat and OS ticks over UART |
| Task C | 1000 ms | Polls physical push-button state (GPIO Input) |

---

## Scheduler APIs

| API Function | Description |
|-------------|-------------|
| `OS_Init()` | Initializes the system timer and clears the task list. |
| `OS_AddTask(func, period)` | Registers a new task with a specific execution interval. |
| `OS_Run()` | The core scheduler engine that manages task switching. |
| `OS_GetTick()` | Returns the total system uptime in milliseconds. |

---

## Folder Structure

The project follows a strictly modular structure to separate the RTOS kernel from the application logic.

```plaintext
vsdsquadron-mini-core/
└── task4/
    └── submission/
        ├── lib/
        │   ├── gpio.c/h       # GPIO Driver
        │   ├── uart.c/h       # UART Driver
        │   ├── timer.c/h      # Timer Driver
        │   └── scheduler.c/h  # RTOS Kernel
        ├── app/
        │   └── main.c         # Application Tasks
        ├── README.md
        └── evidence.md
```

---

## Summary

This capstone project successfully demonstrates:

- Implementation of a **Cooperative Scheduler**  
- Deterministic task switching based on a hardware timer tick  
- Integration of **multiple drivers** (UART, GPIO, Timer)  
- A clean, modular firmware design with **no direct register access in `main.c`**  