GPIO Sysfs Driver using Device Tree

## Overview

This project implements a Linux Platform Driver for BeagleBone Black using the Device Tree framework and GPIO Descriptor API. The driver dynamically discovers GPIO devices from child nodes in the Device Tree and exposes them through sysfs interfaces.

## Features

* Linux Platform Driver
* Device Tree Support
* GPIO Descriptor API (gpiod)
* Dynamic GPIO Discovery
* Sysfs Interface
* Read/Write GPIO Value
* Configure GPIO Direction
* Device Label Support

## Project Structure

```
gpiosysfs/
├── gpio_sysfs.c
├── bbb_my_dts.dtsi
├── Makefile
└── README.md
```

## Device Tree Example

```dts
bb_gpio_dev {
    compatible = "org,bb-gpio-sys";

    gpio0 {
        label = "gpio2.2";
        bb-gpios = <&gpio2 2 GPIO_ACTIVE_HIGH>;
    };

    gpio1 {
        label = "userled0-gpio1.21";
        bb-gpios = <&gpio1 21 GPIO_ACTIVE_HIGH>;
    };
};
```

## Build

```bash
make
```

## Load Driver

```bash
insmod gpio_sysfs.ko
```

## Check Driver

```bash
dmesg | tail
```

## Sysfs Interface

```bash
ls /sys/class/my_gpios/
```

Example:

```bash
cat /sys/class/my_gpios/gpio2.2/label
cat /sys/class/my_gpios/gpio2.2/direction
cat /sys/class/my_gpios/gpio2.2/value
```

Set Direction:

```bash
echo out > /sys/class/my_gpios/gpio2.2/direction
```

Set Value:

```bash
echo 1 > /sys/class/my_gpios/gpio2.2/value
echo 0 > /sys/class/my_gpios/gpio2.2/value
```

## Kernel Version

Tested on Linux 5.10.x for BeagleBone Black.

## Author

Sreerag KS

