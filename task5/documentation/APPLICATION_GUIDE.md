# Application Logic Guide

## Tasks
- Task A: LED toggle every 3000 ms
- Task B: UART telemetry every 5000 ms
- Task C: Button polling every 1000 ms

## Edge Cases
- UART buffer prevents overflow
- 32-bit tick counter handles overflow safely
