#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/init.h>
#include <linux/mod_devicetable.h>


int read_jedec (struct spi_device *spi){
u8 cmd=0x9f;
u8 rx[3];
int ret;
ret=spi_write_then_read(spi, &cmd, 1, rx, 3);
if(ret<0){

dev_err(&spi->dev,"JEDEC FAILED\n");
return ret;
}
dev_info(&spi->dev,"Manu id : %#2X\n",rx[0]);
dev_info(&spi->dev,"Memm    : %#2X\n",rx[1]);
dev_info(&spi->dev,"Capcity : %#2X\n",rx[2]);

return 0;

}



int read_status_reg (struct spi_device *spi){
u8 cmd=0x05;
u8 rx;
int ret;
ret=spi_write_then_read(spi, &cmd, 1, &rx, 1);
if(ret<0){

dev_err(&spi->dev,"READ_STATUS_REG_FAILED\n");
return ret;
}
dev_info(&spi->dev,"STATUS REG : %#2X\n",rx);
return 0;

}




static int spi_probe(struct spi_device *spi){
int ret;
dev_info(&spi->dev, "Mode      : %u\n", spi->mode);
dev_info(&spi->dev, "Speed     : %u Hz\n", spi->max_speed_hz);
dev_info(&spi->dev, "Chip Select: %u\n", spi->chip_select);

/* To Change the parameters
spi_setup(spi);
*/

ret=read_jedec(spi);
if(ret<0){

return ret;
}


ret=read_status_reg(spi);

if(ret<0){

return ret;
}






dev_info(&spi->dev, "W25Q64 Probe called\n");
return 0;
}


static int spi_remove(struct spi_device *spi){





dev_info(&spi->dev, "W25Q64 Removed\n");
return 0;
}


static const struct of_device_id spi_w25q64_of[] = {
    { .compatible = "sree,w25q" },
    { }
};



static struct spi_driver spi_w25q64 ={
.probe=spi_probe,
.remove=spi_remove,
.driver={
.name="spi_w25q64",
.of_match_table=spi_w25q64_of,

},





};



module_spi_driver(spi_w25q64);  // it expands to module init and exit


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SREERAG K S");
MODULE_DESCRIPTION("W25q64 SPI DRIVER"); 
