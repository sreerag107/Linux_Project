//Install NFS Server

sudo apt install nfs-kernel-server

//Verify the installation.

sudo systemctl status nfs-kernel-server

Expected output: Active: active (running)


//Create a directory that will contain the Buildroot root filesystem.

sudo mkdir -p /srv/nfs/rootfs


//Open the exports configuration file.

sudo nano /etc/exports

Add the following line.

/srv/nfs/rootfs *(rw,sync,no_subtree_check,no_root_squash)

rw   :				Allow read and write access
sync :				Write changes to disk immediately
no_subtree_check:		Disable subtree verification for better performance
no_root_squash:			Allow the target root user to remain root on the exported filesystem


//Reload the exports table.

sudo exportfs -ra

//Restart the NFS Service

sudo systemctl restart nfs-kernel-server

//Verify the service.

sudo systemctl status nfs-kernel-server

//Enable automatic startup after reboot.

sudo systemctl enable nfs-kernel-server






