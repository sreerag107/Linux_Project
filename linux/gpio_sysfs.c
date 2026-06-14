# include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/of.h>
#include <linux/kernel.h>
#include <linux/of_device.h>
#include <linux/gpio/consumer.h>
#include <linux/init.h>
#include <linux/string.h>



struct gpio_dev_data{
	char label[30];
	struct gpio_desc *gpio_desc;
};

struct gpio_drv_data{
	int total_devices;
	struct class *class;
	struct device **device;
	struct gpio_dev_data *gpio_dev_data;

};

struct gpio_drv_data gpio_drv_data;

ssize_t direction_show(struct device *dev, struct device_attribute *attr, char *buf){

struct gpio_dev_data *dev_data = dev_get_drvdata(dev);
char *direc;
int dir;
dir = gpiod_get_direction(dev_data->gpio_desc);

if (dir<0){
return dir;

}

direc = (dir ==0)? "out":"in";
return sprintf(buf,"%s\n",direc);

}


ssize_t direction_store(struct device *dev, struct device_attribute *attr,
                        const char *buf, size_t count){


struct gpio_dev_data *dev_data = dev_get_drvdata(dev);
int ret;
if (sysfs_streq(buf,"in")){
ret=gpiod_direction_input(dev_data->gpio_desc);
}
else if (sysfs_streq(buf,"out")){
ret=gpiod_direction_output(dev_data->gpio_desc,0);
}

else{
 ret = -EINVAL;
}

return ret ? ret : count;




}


ssize_t value_show(struct device *dev, struct device_attribute *attr,
                        char *buf){
struct gpio_dev_data *dev_data = dev_get_drvdata(dev);
int value;
	value = gpiod_get_value(dev_data->gpio_desc);
        return sprintf(buf,"%d\n",value);
}





ssize_t value_store(struct device *dev, struct device_attribute *attr,
                        const char *buf, size_t count){
struct gpio_dev_data *dev_data = dev_get_drvdata(dev);
 int ret;
        long value;

        ret = kstrtol(buf,0,&value);
        if(ret)
                return ret;

        gpiod_set_value(dev_data->gpio_desc,value);

        return count;

}


ssize_t label_show(struct device *dev, struct device_attribute *attr,
                        char *buf){

struct gpio_dev_data *dev_data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", dev_data->label);

}




static DEVICE_ATTR_RW(direction);
static DEVICE_ATTR_RW(value);
static DEVICE_ATTR_RO(label);



static struct attribute *gpio_attrs[]={

&dev_attr_direction.attr,
&dev_attr_value.attr,
&dev_attr_label.attr,
NULL


};

static struct attribute_group gpio_attr_group = {
.attrs = gpio_attrs


};


const static struct attribute_group *gpio_attr_groups[] = {
&gpio_attr_group,
NULL


};

int gpio_sys_probe (struct platform_device *pdev){
int ret;
const char *name;	
	
struct device *dev = &pdev->dev;
struct device_node *parent = pdev->dev.of_node; // parent device bb-gpio-sys{  }
struct device_node *child = NULL; // which will populated with each child.
struct gpio_dev_data *dev_data;
int i =0;
gpio_drv_data.total_devices = of_get_child_count(parent);
      if(!gpio_drv_data.total_devices){
                dev_err(dev,"No devices found\n");
                return -EINVAL;
        }

gpio_drv_data.device = devm_kzalloc(dev, sizeof(struct device *) * gpio_drv_data.total_devices , GFP_KERNEL);
      
      for_each_available_child_of_node(parent,child){

	dev_data = devm_kzalloc(dev,sizeof(*dev_data),GFP_KERNEL);

	if(!dev_data){
	pr_err("cannot allocate memmory\n");
	return -ENOMEM;

}

if (of_property_read_string(child,"label",&name)){

	dev_warn(dev,"missing label info\n");

}
else{

	strcpy(dev_data->label,name);


}
dev_data->gpio_desc=devm_fwnode_get_gpiod_from_child(dev,"bb",&child->fwnode,GPIOD_ASIS,dev_data->label);
	if(IS_ERR(dev_data->gpio_desc)){
	ret=PTR_ERR(dev_data->gpio_desc);
	return ret;

	}
	ret=gpiod_direction_output(dev_data->gpio_desc,0);
	if(ret){
	dev_err(dev,"gpio direction error\n");
	return ret;
	}
	
gpio_drv_data.device[i]=device_create_with_groups(gpio_drv_data.class,dev,0,dev_data,gpio_attr_groups,dev_data->label);

if (IS_ERR(gpio_drv_data.device[i])){
	dev_err(dev,"error creationg device file\n");
	return PTR_ERR(gpio_drv_data.device[i]);

}

i++;
}




return 0;
}
int gpio_sys_remove(struct platform_device *pdata){
 
int i;
 dev_info(&pdata->dev,"Remove called\n");

      for(i = 0 ; i < gpio_drv_data.total_devices ; i++){
                device_unregister(gpio_drv_data.device[i]);
     
     
      }
        return 0;

}

struct of_device_id gpio_device_match[] = {
	{.compatible = "org,bb-gpio-sys"},
	{}
};

struct platform_driver gpio_plat = {
.probe =gpio_sys_probe,
.remove=gpio_sys_remove,
.driver={
.name = "bb-gpio",
.of_match_table = of_match_ptr(gpio_device_match),
}
};

static int __init gpio_sys_init(void){

/*class_create*/

gpio_drv_data.class=class_create(THIS_MODULE,"my_gpios");
if(IS_ERR(gpio_drv_data.class)){
pr_err("error creating class\n");
return PTR_ERR(gpio_drv_data.class);
}
platform_driver_register(&gpio_plat);
pr_info("module loaded successfuly\n");

return 0;
}



static void __exit gpio_sys_exit (void){

platform_driver_unregister(&gpio_plat);
class_destroy(gpio_drv_data.class);




}

module_init(gpio_sys_init);

module_exit(gpio_sys_exit);



MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION("GPIO SYSFS DEVICE");
MODULE_AUTHOR("SREERAG");





