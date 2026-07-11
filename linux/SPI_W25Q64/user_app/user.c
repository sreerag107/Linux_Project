#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>




int main () {

int fd;

fd=open("/dev/spidev0.0",O_RDWR);

if(fd<0){

perror("error in opening ");
return -1;
}

uint8_t mode = SPI_MODE_0;  		//cpol,cpha ==0;

if(ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0)
{
    perror("Mode error");
    return -1;
}

uint8_t bits=8;

if(ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0)
{
    perror("Bits error");
    return -1;
}



uint32_t speed = 100000;



if(ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0)
{
    perror("Speed error");
    return -1;
}

uint8_t tx_buff[4]={0x9f,0x00,0x00,0x00};  //  jedic manu id,memm id,capacity so dummy bytes need to be transferd.
uint8_t rx_buff[4] = {0};

struct spi_ioc_transfer tx = {
.len=sizeof(tx_buff),
.tx_buf=(unsigned long)tx_buff,
.rx_buf=(unsigned long)rx_buff,
.speed_hz=speed,
.bits_per_word=bits,

};


int ret=ioctl(fd, SPI_IOC_MESSAGE(1), &tx);
printf("ret= %d\n",ret);
if(ret<0){
perror("Error transmitting instruction");
return -1;
}


printf("RX: %02X %02X %02X %02X\n",
       rx_buff[0], rx_buff[1], rx_buff[2], rx_buff[3]);


close(fd);
return 0;
}

