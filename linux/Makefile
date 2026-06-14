obj-m := gpio_sysfs.o
ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
#set KERN_DIR to linux source location 
KERN_BOARD = /home/sreerag/bbwork/linux-5.10.168-ti-rt-r76/
HOST_KERN = /lib/modules/$(shell uname -r)/build/

all:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_BOARD) M=$(PWD) modules
clean:
	make -C $(HOST_KERN) M=$(PWD) clean
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_BOARD) M=$(PWD) clean
help:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_BOARD) M=$(PWD) help
host:
	make -C $(HOST_KERN) M=$(PWD) modules
