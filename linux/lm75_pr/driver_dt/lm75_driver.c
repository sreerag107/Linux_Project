#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/init.h>
static int lm75_probe(struct i2c_client *client, const struct i2c_device_id *id){
u8 reg=0x00; 
u8 data[2];
u16 value;
int temp;
int ret;
dev_info(&client->dev,
         "addr=0x%x adapter=%d\n",
         client->addr,
         client->adapter->nr);
ret=i2c_master_send(client, &reg, 1);

if(ret!=1){
pr_err("Send data error\n");
return ret;
}

ret=i2c_master_recv(client,data,2);
if(ret!=2){

pr_err("Reading error\n");
return ret;
}
value= (data[0]<<8)|data[1];
temp=(value>>5)*125;

/*res = i2c_smbus_read_word_data(client, 0x00);

if(res<0){

pr_err("data not readed successfuly");
return res;
}
data=(res&0xff)<<8|(res&0xff00)>>8;
temp= (data>>5)*125;
*/
pr_info("LM75 PROBE CALLED \n");

pr_info("The temp data is : %d.%03d C\n",temp/1000,temp%1000);
return 0;
}






static int lm75_remove(struct i2c_client *client){
pr_info("LM75 DEVICE IS REMOVED \n");
return 0;
}

static const struct i2c_device_id lm75_id[]={

{"my_lm75",0},
{}
};

static const struct of_device_id lm75_of_match[]={

{.compatible = "sree,lm75"},
{}

};  
static struct i2c_driver lm75_driv={
.probe=lm75_probe,
.remove=lm75_remove,
.id_table=lm75_id,
.driver={
.name="my_lm75",
.of_match_table=lm75_of_match,
},

};

module_i2c_driver(lm75_driv);


/*static int __init lm75_module_init (void){


pr_info("module loaded\n");
return 0;
}


void lm75_exit(void){


pr_info("module exited \n");
}


module_init(lm75_module_init);
module_exit(lm75_exit);
*/
MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION("LM75 DRIVER");
MODULE_AUTHOR("SREERAG");
