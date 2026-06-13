/* header file for module_init,exit*/
#include <linux/module.h>

/* header file for module_init,exit*/
#include <linux/fs.h>

#include <linux/cdev.h>

#include <linux/device.h>


#include <linux/uaccess.h>

/*includind printk command*/
#include <linux/kernel.h>

#include <linux/export.h>


/*psuedo_char_device*/

#define DEVICE_MEM        512

char device[DEVICE_MEM];





/*driver system call handling or file handling implementation*/




static loff_t pcd_llseek (struct file *filp, loff_t off, int whence){
switch (whence)

{

case SEEK_SET:
if((off>DEVICE_MEM)||(off<0)){
	return -EINVAL;
}
filp->f_pos=off;
break;
case SEEK_CUR:
filp->f_pos=filp->f_pos+off;
break;
case SEEK_END:
filp->f_pos=DEVICE_MEM+off;
break;
default:
return -EINVAL;

}

return filp->f_pos;

}
static ssize_t pcd_read (struct file *filp, char __user *buffer, size_t count, loff_t *f_pos){
int ret;
if (*f_pos >=DEVICE_MEM){
return 0;
}
if((*f_pos+count)>DEVICE_MEM){
	count=DEVICE_MEM-*f_pos;

}
ret=copy_to_user(buffer,&device[*f_pos],count);
if(ret){
return -EFAULT;
}

if(*f_pos>=DEVICE_MEM){
return 0;
}
*f_pos+=count;

pr_info("%zu number is copied to the device\n",count);
return count;


}
static ssize_t pcd_write (struct file *filp, const char __user *buffer, size_t count, loff_t *f_pos){
int ret;
if((*f_pos+count)>DEVICE_MEM){
	count=DEVICE_MEM-*f_pos;

}
if(!count){
return 0;
}
ret=copy_from_user(&device[*f_pos],buffer,count);
if(ret){
return -EFAULT;
}
*f_pos+=count;
pr_info("%zu number is writed in the device\n",count);
return count;

}

static int pcd_open (struct inode *inode, struct file *filp){
pr_info("module was successfully open\n");
return 0;
}
static int pcd_release (struct inode *inode, struct file *filp){

pr_info("module was realesed successfully\n");


return 0;
}




dev_t device_number;
struct cdev pcd_cdev;
struct class *pcd_class;
struct device *pcd_device;

struct file_operations pcd_fops={
	.llseek=pcd_llseek,
	.read=pcd_read,
	.open=pcd_open,
	.write=pcd_write,
	.release=pcd_release,
	.owner=THIS_MODULE

};






static int __init pcd_init (void){

int ret;
/*devicenumber creation*/
ret=alloc_chrdev_region(&device_number,0,1,"pcd_device_number");
if(ret<0){

goto err;

}
pr_info("device number created major,minor is %d,%d\n",MAJOR(device_number),MINOR(device_number));


/*char_Device_init&add*/

cdev_init(&pcd_cdev, &pcd_fops);


pcd_cdev.owner=THIS_MODULE;
ret=cdev_add(&pcd_cdev,device_number,1);

if(ret<0){
goto unallocdev;
}


/*class and device file create*/

pcd_class=class_create(THIS_MODULE,"pcd_class_v2");
if(IS_ERR(pcd_class)){
ret=PTR_ERR(pcd_class);
goto cdevdel;

}

pcd_device=device_create(pcd_class, NULL, device_number, NULL, "pcd_dev_v2");
if(IS_ERR(pcd_device)){
ret=PTR_ERR(pcd_device);
goto classdestroy;

}




pr_info("module_init_successful\n");

return 0;

classdestroy:
  pr_info("device file cannot be populated in sysfs\n");
	class_destroy(pcd_class);	
cdevdel:
	pr_info("class cannot be populated in sysfs\n");
	cdev_del(&pcd_cdev);
unallocdev:
	pr_info("char device cannot be registerd with VFS\n");
	unregister_chrdev_region(device_number,1);
err:
	pr_info("device number can't be allocated\n");
	
	pr_info("module cannot be initisalied \n");
	return ret;

}


static void __exit pcd_exit (void){

device_destroy(pcd_class,device_number);
class_destroy(pcd_class);
cdev_del(&pcd_cdev);
unregister_chrdev_region(device_number,1);

pr_info("module_unloaded_successful\n");
}

module_init(pcd_init);

module_exit(pcd_exit);


MODULE_DESCRIPTION("PSUEDO_CHAR_DEVICE");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SREERAG");
MODULE_INFO(BBB,"REV C");


