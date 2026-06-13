
Pseudo Character Driver

A Linux Character Device Driver implemented as a Loadable Kernel Module (LKM).

Features

* Dynamic device number allocation
* Character device registration (`cdev`)
* Automatic device node creation
* Read, Write, Open, Release operations
* `llseek` support
* Proper driver cleanup

## Device

```text
/dev/pcd_dev_v2
```

## Build

```bash
make
```

## Load Driver

```bash
sudo insmod psuedo.ko
```

## Remove Driver

```bash
sudo rmmod psuedo
```

## Tested On

* Ubuntu Linux
* BeagleBone Black
* Linux Kernel 5.10.168-ti-rt-r76
