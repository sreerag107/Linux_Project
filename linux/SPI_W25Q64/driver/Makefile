obj-m+=spi_w25q64.o
Kernel:=/home/sreerag/bbwork/linux-5.10.168-ti-rt-r76
PWD:=$(shell pwd)
ARCH:=arm
CROSS_COMPILE:=/home/sreerag/bbwork/buildroot-2025.05/output/host/bin/arm-linux-gnueabihf-


all:
	$(MAKE) -C $(Kernel) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules


clean:
	$(MAKE) -C $(Kernel) M=$(PWD) clean
 
 
