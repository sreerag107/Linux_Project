# STM32 FreeRTOS Temperature Monitoring System

A real-time temperature monitoring application developed on the **STM32F407 Discovery** board using **FreeRTOS** and the **LM75 I2C Temperature Sensor**. The project demonstrates task scheduling, inter-task communication using queues, and modular driver development.

---

## Features

- FreeRTOS kernel manually integrated into STM32CubeIDE project
- LM75 temperature sensor driver using I2C
- Periodic temperature acquisition
- Inter-task communication using FreeRTOS Queues
- Three independent FreeRTOS tasks
- LED indication for task execution
- Modular driver architecture

---

## Hardware Used

- STM32F407 Discovery Board
- LM75 Temperature Sensor Module
- USB ST-Link
- STM32CubeIDE

---

## Software Used

- STM32CubeIDE
- STM32 HAL Driver
- FreeRTOS V11.3.0
- ARM GCC Toolchain

---

## Project Architecture

```
                 +----------------+
                 | LM75 Sensor    |
                 +-------+--------+
                         |
                    I2C Communication
                         |
                         ▼
              +----------------------+
              | Temperature Task     |
              | Reads every 1 second |
              +----------+-----------+
                         |
                     Queue 1
                         |
                         ▼
                 +---------------+
                 | Log Task      |
                 | Receives Temp |
                 +-------+-------+
                         |
                     Queue 2
                         |
                         ▼
                 +---------------+
                 | Alarm Task    |
                 | Checks Limit  |
                 +---------------+
```

---

## FreeRTOS Tasks

### Temperature Task

Priority: **2**

Responsibilities:

- Read LM75 temperature every second
- Send temperature to Queue1
- Toggle Orange LED (PD13)

---

### Log Task

Priority: **2**

Responsibilities:

- Receive temperature from Queue1
- Forward temperature to Queue2
- Toggle Red LED (PD14)

---

### Alarm Task

Priority: **2**

Responsibilities:

- Receive temperature from Queue2
- Compare with threshold
- Turn ON Green LED (PD15) when temperature exceeds the configured limit

---

## Queue Communication

```
TemperatureTask
       |
       ▼
    Queue1
       |
       ▼
    LogTask
       |
       ▼
    Queue2
       |
       ▼
    AlarmTask
```

---

## Project Folder Structure

```
.
├── Core
│   ├── Inc
│   └── Src
├── Drivers
├── Middlewares
│   └── FreeRTOS
├── README.md
└── STM32CubeIDE Project Files
```

---

## Learning Outcomes

This project demonstrates practical knowledge of:

- FreeRTOS Task Creation
- Scheduler
- Task Priorities
- Blocking Delays (`vTaskDelay`)
- Queue Creation
- Queue Send
- Queue Receive
- Producer-Consumer Architecture
- STM32 HAL I2C Driver
- Modular Embedded Software Design

---

## LED Indications

| LED | Purpose |
|-----|---------|
| Orange (PD13) | Temperature Task Running |
| Red (PD14) | Log Task Running |
| Green (PD15) | Temperature Above Threshold |

---

## Temperature Flow

```
LM75
   │
   ▼
Temperature Read
   │
   ▼
Queue1
   │
   ▼
Log Task
   │
   ▼
Queue2
   │
   ▼
Alarm Task
   │
   ▼
Alarm Decision
```

---

## Future Improvements

- UART logging
- LCD/OLED temperature display
- Binary Semaphore synchronization
- Mutex protection
- Software Timers
- Event Groups
- Task Notifications
- SD Card data logging
- Temperature history storage

---

## Author

**Sreerag K S**

Embedded Systems Engineer

GitHub:
https://github.com/sreerag107
