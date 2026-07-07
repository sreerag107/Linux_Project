#include <stdio.h>
#include <stdlib.h>    //exit()
#include <stdint.h>
#include <fcntl.h>    //open sys call
#include <unistd.h>   //write,read
#include <sys/ioctl.h> //ioctl
#include <linux/i2c-dev.h>//i2c api's  

#define LM75_ADDR         0x48

int main () {
int fd; //file descriptior

fd =open("/dev/i2c-2",O_RDWR);
if (fd<0){
perror("I2C OPEN IS NOT COMPLETED");
return -1;
}

/* Attempt to configure this I2C bus to talk to the LM75 sensor. If the setup fails, execute the error-handling code inside the if block.This line is used to prepare an I2C bus to communicate with a specific slave device */

if(ioctl(fd,I2C_SLAVE,LM75_ADDR)<0){

perror("The setting of slave address is not completed");

close(fd);
return -1;
}

uint8_t reg=0x00;

if(write(fd,&reg,1)!=1){
perror("Register write failed");
close(fd);
return -1;

}



uint8_t data[2];


if(read(fd,data,2)!=2){
perror("Read failed");
close(fd);
return -1;

}

uint16_t value=(data[0]<<8)|data[1];

float temp=(value>>5)*0.125;

printf("MSB : %x\n",data[0]);
printf("LSB : %x \n",data[1]);

printf("the combined value: %x\n",value);
printf("The Temperature value is %2f C\n",temp);


close(fd);




return 0;
} 



