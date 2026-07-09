/*Installing TFTP Server*/

$ sudo apt update
$ sudo apt install tftpd-hpa


/*Create/Open the file “tftpd-hpa” in the below directory*/

$ sudo vim /etc/default/tftpd-hpa

TFTP_USERNAME="tftp"
TFTP_DIRECTORY="/var/lib/tftpboot"
TFTP_ADDRESS=":69"
TFTP_OPTIONS="--create --secure"

Add this to the file and save.



/*Create a folder /var/lib/tftpboot..*/
Run this commands.

$ sudo mkdir -p /var/lib/tftpboot

$ sudo chown tftp:tftp /var/lib/tftpboot

$ sudo chmod -R 777 /var/lib/tftpboot


/*To start the tftp server...*/

$ sudo systemctl start tftpd-hpa


/*To check the status of tftp server...*/

$ sudo systemctl status tftpd-hpa...
