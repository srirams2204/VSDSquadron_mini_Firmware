# System Architecture

## Design Overview
The firmware uses a layered architecture separating drivers, kernel, and application.

<center><img src="../../pics/firmware_stack.svg" width="500"></center>

## Control Flow
- Hardware timer generates 1ms tick
- Scheduler evaluates tasks
- Tasks execute sequentially

## Design Choice
Cooperative scheduling ensures determinism and minimal RAM usage.