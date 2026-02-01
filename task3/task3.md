# Task 3 – PWM Driver Library + Application Demo

**Platform:** VSDSquadron Mini (CH32V003 RISC-V)

---

## Overview

This task implements a reusable **software-based PWM (Pulse Width Modulation) driver library** for the VSDSquadron Mini board.  
The driver can generate PWM signals on **any GPIO pin**, with configurable frequency and duty cycle.

A demo application showcases real-time PWM control using **UART commands**.

---

## Implemented Library

**Library Name:** `pwm_driver`

The PWM driver maintains internal state for:

- Frequency
- Duty cycle
- Start/Stop control

It uses a heartbeat-based update model and hardware timer support.

---

## Library Files

```
lib/
├── pwm.h
├── pwm.c
├── timer.h   (Dependency for timing)
└── timer.c
```

---

## PWM Driver APIs

| API Function | Description |
|-------------|-------------|
| `PWM_Init(GPIO_TypeDef* port, uint8_t pin, uint16_t period_us)` | Initializes the PWM pin and sets the signal period (frequency). |
| `PWM_Set_Duty(uint8_t duty)` | Updates the signal duty cycle (0–100%). |
| `PWM_Start(void)` | Enables signal generation. |
| `PWM_Stop(void)` | Disables signal generation (forces pin LOW). |
| `PWM_Update(void)` | Heartbeat function. Must be called in the main loop to generate the PWM waveform. |

---

## Demo Application

**File:** `app/main.c`

### Features Demonstrated

- PWM initialization at **500 Hz** (2000 µs period)
- UART-based command interface
- Dynamic duty cycle updates
- Start/Stop control logic

---

## Application Behavior

### Startup
- Prints a banner on the Serial Monitor:
  ```
  UART PWM Controller
  ```

### Heartbeat
- Continuously generates a PWM signal on **PD3**
- Fades an external LED based on duty cycle

### UART Commands

| Command | Action |
|--------|--------|
| `0` – `100` | Set LED brightness percentage |
| `S` | Stop PWM (LED OFF) |
| `G` | Resume PWM (LED ON) |

### Feedback
- Echoes the current brightness or status back to the terminal.

---

## How to Build and Flash

1. Open the PlatformIO project in **VS Code**
2. Build the firmware  
   *(Click the ✔️ Checkmark icon)*
3. Connect the VSDSquadron Mini via USB
4. Upload the firmware  
   *(Click the ➡️ Arrow icon)*
5. Open the Serial Monitor  
   *(Click the 🔌 Plug icon)*

### Serial Monitor Settings

- **Baud Rate:** `9600`  
- **Filters:** `Echo`, `Send on Enter`

---

## Hardware Configuration

| Parameter | Value |
|----------|-------|
| PWM Output Pin | PD3 (External LED) |
| UART TX Pin | PD5 |
| UART RX Pin | PD6 |
| Baud Rate | 9600 |
| PWM Frequency | 500 Hz |

---

## Summary

This task demonstrates:

- A clean, **state-based PWM driver library**
- Proper **separation of concerns** (Driver vs Application)
- **Real-time control** using UART
- **Precise timing** using hardware timers for software PWM
- **Verified execution** on real CH32V003 hardware

This forms a solid reusable foundation for future motor control, LED dimming, and embedded control applications.
