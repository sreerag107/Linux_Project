# Embedded Linux Boot using Buildroot, U-Boot, TFTP and NFS on BeagleBone Black

## Overview

This repository demonstrates the complete Embedded Linux boot process on the **BeagleBone Black (AM335x)** using a custom Linux system built from source.

The project covers the complete workflow starting from building the root filesystem using **Buildroot**, compiling the **Linux Kernel**, configuring **U-Boot**, loading the kernel and Device Tree using **TFTP**, and mounting the Buildroot root filesystem using **NFS**.

The objective of this project is to understand every stage of the Embedded Linux boot process and create a reproducible Linux development environment.

---

# Hardware

- BeagleBone Black Rev C
- Ubuntu Linux Host PC
- MicroSD Card
- Ethernet Cable

---

# Software

- Ubuntu Linux
- Buildroot 2025.05
- Linux Kernel 5.10.168-ti-rt-r76
- U-Boot 2022.04
- BusyBox
- TFTP Server (tftpd-hpa)
- NFS Server
- ARM Cross Compiler

---

# Boot Architecture

```
                Ubuntu Host PC
+------------------------------------------------+

 Buildroot RootFS ---------------> NFS Server

 Linux Kernel (uImage) ----------> TFTP Server

 Device Tree (.dtb) -------------> TFTP Server

+------------------------------------------------+
                    |
                    |
                Ethernet
                    |
                    |
+------------------------------------------------+

             BeagleBone Black

 ROM Boot Loader

        ↓

 MLO (SPL)

        ↓

 U-Boot

        ↓

 Download Kernel using TFTP

        ↓

 Download Device Tree using TFTP

        ↓

 Boot Linux Kernel

        ↓

 Mount Buildroot RootFS using NFS

        ↓

 BusyBox Login

+------------------------------------------------+
```

---

# Boot Sequence

1. Power ON BeagleBone Black.
2. ROM Boot Loader loads **MLO (SPL)** from the SD Card.
3. SPL initializes DDR memory.
4. SPL loads **U-Boot** from the SD Card.
5. U-Boot looks for uEnv.tx.
6. U-Boot downloads:
   - Linux Kernel (`uImage`)
   - Device Tree (`am335x-boneblack.dtb`)
   using the **TFTP server**.
7. Linux kernel starts execution.
8. Linux kernel mounts the **Buildroot Root Filesystem** using **NFS**.
9. BusyBox initializes the userspace.
10. Linux login prompt appears.

---

# Project Workflow

```
Buildroot

↓

Generate Root Filesystem

↓

Compile Linux Kernel

↓

Generate uImage + Device Tree

↓

Copy Kernel & DTB to TFTP Directory

↓

Extract Buildroot RootFS

↓

Export RootFS using NFS

↓

Configure U-Boot

↓

Boot BeagleBone Black

↓

Linux Login
```

---

# Repository Structure

```
Linux_Project

│── boot/
│      ├── tftp.md
│      ├── nfs.md
│      ├── uEnv.txt
│      └── Boot Logs
│
│── buildroot/
│
│── kernel/
│
│── screenshots/
│
└── README.md
```

---

# Project Features

- Build Custom Linux Root Filesystem using Buildroot
- Linux Kernel Cross Compilation
- Device Tree Compilation
- U-Boot Configuration using uEnv.txt
- TFTP Boot
- NFS Root Filesystem
- Embedded Linux Network Boot
- BusyBox Root Filesystem
- Static Ethernet Configuration
- BeagleBone Black Bring-up

---

# Documents

## TFTP Configuration

This document explains

- Installing TFTP Server
- TFTP Configuration
- Kernel Copy
- Device Tree Copy
- U-Boot TFTP Boot

See:

```
boot/tftp.md
```

---

## NFS Configuration

This document explains

- Installing NFS Server
- Extracting Buildroot RootFS
- Export Configuration
- Root Filesystem Mount
- Verification

See:

```
boot/nfs.md
```

---

# Tools Used

- Buildroot
- U-Boot
- Linux Kernel
- BusyBox
- GCC ARM Cross Compiler
- tftpd-hpa
- nfs-kernel-server
- Git
- Ubuntu Linux

---

# Skills Demonstrated

- Embedded Linux
- Linux Boot Process
- Buildroot
- ARM Cross Compilation
- Linux Kernel Compilation
- U-Boot
- Device Tree
- BusyBox
- TFTP
- NFS
- Embedded Ethernet Networking
- Linux System Bring-up

---

# Learning Outcome

Through this project I learned:

- Complete Embedded Linux boot sequence
- Buildroot root filesystem generation
- Linux kernel compilation
- Device Tree generation
- U-Boot configuration
- Network boot using TFTP
- Root filesystem mounting using NFS
- Linux boot debugging
- Embedded networking
- Host-target communication

---

# References

- Buildroot Documentation
- Linux Kernel Documentation
- U-Boot Documentation
- BusyBox Documentation
- BeagleBone Black System Reference Manual

---

# Author

**Sreerag K S**

Embedded Systems Engineer

GitHub:
https://github.com/sreerag107
