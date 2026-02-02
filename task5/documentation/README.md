# Mini-RTOS Cooperative Scheduler

## Project Summary
This project implements a lightweight, deterministic **Mini-RTOS** kernel for the VSDSquadron Mini (CH32V003 RISC-V).  
It manages three concurrent application tasks—LED control, system telemetry, and input polling—using a cooperative, tick-based scheduler.

## Target Hardware
- VSDSquadron Mini (CH32V003 RISC-V)

## Supported Drivers
- GPIO
- UART
- Timer

## Folder Structure
```plaintext
task5/
└── documentation/
    ├── README.md
    ├── API_REFERENCE.md
    ├── ARCHITECTURE.md
    ├── APPLICATION_GUIDE.md
    ├── DEMO_GUIDE.md
    └── CHANGELOG.md
```

## Quick Start
```bash
cd task5/documentation
pio run
pio run --target upload
pio device monitor -b 9600
```