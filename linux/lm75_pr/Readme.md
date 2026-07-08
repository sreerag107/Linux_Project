# LM75 Temperature Sensor Linux I2C Driver

## Overview

This project demonstrates the development of a Linux I2C device driver for the **LM75BD Temperature Sensor** on the **BeagleBone Black**.

The project was developed from scratch to understand the Linux I2C subsystem, Device Tree, driver binding, and communication between the Linux kernel and I2C peripherals.

The driver communicates with the LM75 sensor, reads the temperature register, converts the raw data into Celsius, and prints the temperature during driver probe.

---

## Hardware Used

- BeagleBone Black Rev C
- LM75BD Temperature Sensor
- Ubuntu Linux Host PC
- Buildroot Toolchain
- TFTP Server To Boot Kernel and DTB.
- NFS For Root Filesystem

---

## Software Environment

| Component | Version |
|----------|----------|
| Linux Kernel | 5.10.168-ti-rt-r76 |
| Buildroot | 2025.05 |
| Architecture | ARM |
| Compiler | arm-linux-gnueabihf-gcc |

---

## Project Structure

```
lm75_pr/
│
├── user_pr/
│   ├── lm75_read.c
│   └── Makefile
│
├── driver/
│   ├── lm75_driver.c
│   └── Makefile
│
├── driver_dt/
│   ├── lm75_driver.c
│   ├── bbb_my_dts.dtsi
│   └── Makefile
│
└── README.md
```

---

# Project Workflow

```
            LM75 Sensor
                 │
                 │ I2C
                 ▼
        BeagleBone Black
                 │
                 ▼
         Linux I2C Controller
                 │
                 ▼
          Linux I2C Core
                 │
                 ▼
          LM75 Driver (probe)
                 │
                 ▼
      Read Temperature Register
                 │
                 ▼
         Convert to Celsius
                 │
                 ▼
          Print Temperature
```

---

# Features

- Linux I2C Device Driver
- Device Tree Support
- Automatic Driver Binding
- Temperature Register Read
- Raw Data Conversion
- Buildroot Cross Compilation
- Tested on Real Hardware

---

# Device Tree Node

```dts
&i2c2 {

    status = "okay";

    lm75@48 {

        compatible = "sree,lm75";
        reg = <0x48>;

    };
};
```

---

# Driver Matching

The driver supports both:

### Manual Device Creation

```
echo my_lm75 0x48 > /sys/bus/i2c/devices/i2c-2/new_device
```

using

```c
static const struct i2c_device_id lm75_id[];
```

---

### Device Tree

using

```c
static const struct of_device_id lm75_of_match[];
```

which automatically creates the I2C client during boot.

---

# Temperature Read Flow

```
probe()

↓

Send Register Address (0x00)

↓

Read Two Bytes

↓

Combine MSB and LSB

↓

Convert Raw Data

↓

Temperature (°C)
```

---

# Building the Driver

```bash
export ARCH=arm
export CROSS_COMPILE=/path/to/arm-linux-gnueabihf-

make
```

---

# Loading the Driver

```bash
insmod lm75_driver.ko
```

Kernel Output

```
my_lm75 2-0048: addr=0x48 adapter=2

LM75 PROBE CALLED

The temp data is : 28.625 C
```

---

# Hardware Bring-up and Validation

Before developing the Linux driver, the hardware and I2C communication were verified step by step.

## Hardware Connections

| LM75BD Pin | BeagleBone Black |
|------------|------------------|
| VCC | 3.3V |
| GND | GND |
| SDA | I2C2_SDA |
| SCL | I2C2_SCL |

---

## Hardware Debugging

The following checks were performed before software development:

### Voltage Verification

Measured using a Digital Multimeter.
VCC : 3.3V
GND : 0V
SCL : 3.3V 
SDA : 3.3V
---

### Continuity / Resistance Checks

The following measurements were performed to verify the module and wiring.

- SDA ↔ VCC
- SCL ↔ VCC
- SDA ↔ GND
- SCL ↔ GND
- VCC ↔ GND

These tests helped verify pull-up resistors and ensure there were no shorts on the I2C bus.

---

### Hardware Troubleshooting Performed

During development the following hardware issues were investigated:

- Verified LM75 wiring multiple times.
- Tested two different LM75 sensor modules.
- Checked BeagleBone Black I2C pin configuration.
- Verified power supply voltage.
- Measured SDA/SCL idle voltage.
- Checked pull-up resistors.
- Used a multimeter to verify board connections.
- Verified I2C communication after replacing the sensor module.

---

# I2C Bus Validation

Available I2C buses were verified.

```bash
i2cdetect -l
```

Expected output

```
i2c-0
i2c-2
```

---

The sensor was detected using

```bash
i2cdetect -y 2
```

Example

```
40: -- -- -- -- -- -- -- -- 48 -- -- -- -- -- -- --
```

showing the LM75 at address **0x48**.

---

# Register Verification

Temperature register was verified before driver development.

```bash
i2cget -y 2 0x48 0x00 w
```

Example

```
0x401d
```

This confirmed successful communication with the sensor.

---

The raw I2C transaction was also verified using

```bash
i2ctransfer -y 2 w1@0x48 0x00 r2
```

Example

```
0x1d 0x60
```

This verified that the sensor correctly returned two bytes from the temperature register.

---

# Userspace Validation

Before writing the kernel driver, a userspace application was developed.

The application performs

- open()
- ioctl(I2C_SLAVE)
- write()
- read()

to communicate with the LM75 sensor.

This confirmed correct communication before moving into kernel-space driver development.

---

# Linux Concepts Covered

- Linux Kernel Modules
- I2C Subsystem
- I2C Driver Registration
- I2C Client
- Probe / Remove
- Device Tree
- OF Match Table
- MODULE_DEVICE_TABLE()
- Buildroot
- Cross Compilation
- TFTP Boot
- NFS Root Filesystem

---

# Future Improvements

- Read Configuration Register
- Support THYST Register
- Support TOS Register
- Improve Error Handling
- Upstream Kernel Coding Style

---

# Challenges Faced

During development, the following issues were encountered and resolved:

- Incorrect LM75 module initially purchased.
- Intermittent I2C communication.
- SMBus read helper returning `-EREMOTEIO`.
- GLIBC version mismatch while running userspace application.
- Cross-compilation toolchain setup.
- Buildroot root filesystem configuration.
- TFTP boot configuration.
- NFS root filesystem setup.
- Incorrect TFTP directory caused an outdated Device Tree Blob (DTB) to be loaded.
- Device Tree debugging using `/proc/device-tree`.
- Driver matching using both `i2c_device_id` and `of_match_table`.


# Learning Outcome

This project helped in understanding:

- Linux I2C Driver Architecture
- How to test I2C device when arrived 
- Device Tree Based Driver Binding
- Communication with I2C Hardware
- Kernel Driver Development
- Embedded Linux Boot Flow
- Cross Compilation and Deployment
- Hardware Debugging on BeagleBone Black

---

## Author

**Sreerag K S**

Embedded Software Engineer

GitHub: https://github.com/sreerag107
