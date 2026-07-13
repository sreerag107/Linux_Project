# STM32F407 FreeRTOS Manual Integration

A FreeRTOS project demonstrating **manual integration of the FreeRTOS kernel** on the **STM32F407 Discovery Board** using **STM32CubeIDE**.

Unlike CubeMX-generated FreeRTOS projects, this project manually integrates the FreeRTOS kernel and Cortex-M4F port, providing a deeper understanding of how the scheduler, tasks, and kernel interact with the STM32 hardware.

---

## Features

- Manual FreeRTOS Kernel Integration
- Native FreeRTOS API (No CMSIS-RTOS Wrapper)
- Cortex-M4F FreeRTOS Port
- FreeRTOS V11.3.0
- STM32 HAL Driver
- Dual LED Multitasking Demo
- Heap_4 Memory Management
- STM32CubeIDE Project

---

## Hardware

- STM32F407 Discovery Board (STM32F407VG)

---

## Software

- STM32CubeIDE
- STM32 HAL
- FreeRTOS Kernel V11.3.0

---

## Project Structure

```
.
├── Core/
├── Drivers/
├── USB_HOST/
├── rtos/
│   ├── include/
│   ├── portable/
│   │   ├── GCC/
│   │   │   └── ARM_CM4F/
│   │   └── MemMang/
│   ├── tasks.c
│   ├── queue.c
│   ├── list.c
│   ├── timers.c
│   ├── event_groups.c
│   ├── stream_buffer.c
│   └── FreeRTOSConfig.h
└── README.md
```

---

## Current Demo

The scheduler creates two independent FreeRTOS tasks.

| Task | LED | Delay |
|------|-----|------:|
| GreenLedTask | PD12 (Green) | 500 ms |
| OrangeLedTask | PD13 (Orange) | 200 ms |

Each task executes independently using `vTaskDelay()` demonstrating preemptive multitasking.

---

## FreeRTOS Components Used

- Task Management
- Scheduler
- Heap_4 Memory Allocator
- Cortex-M4F Port Layer

---

## Manual Integration Highlights

The project demonstrates manual integration of:

- FreeRTOS Kernel Source
- ARM Cortex-M4F Port
- Heap Management
- FreeRTOSConfig.h
- Include Path Configuration
- Interrupt Handler Integration
- Scheduler Startup

No CubeMX FreeRTOS middleware was used.

---

## Build

Open the project in STM32CubeIDE and build using:

```
Project → Build Project
```

Flash the firmware to the STM32F407 Discovery board.

---

## Learning Objectives

This project was created to understand:

- FreeRTOS Kernel Architecture
- Cortex-M Context Switching
- Task Scheduling
- Manual RTOS Integration
- Embedded Multitasking

---

## Roadmap

Upcoming features:

- [ ] Queue
- [ ] Binary Semaphore
- [ ] Mutex
- [ ] Counting Semaphore
- [ ] Event Groups
- [ ] Software Timers
- [ ] LM75 I2C Driver
- [ ] Temperature Monitoring Application
- [ ] UART Logging
- [ ] System Architecture Diagram

---

## License

This project is intended for educational purposes.
