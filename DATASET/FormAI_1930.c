//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>

int main() {
  printf("Wow, I can't believe it's already time to run some system administration code!\n");
  printf("Let's spin up a new virtual machine\n");
  system("virt-install --name=myvm --ram=2048 --vcpus=2 --disk path=/var/lib/libvirt/images/myvm.img,size=20 --graphics none --location=http://mirror.centos.org/centos/7/os/x86_64/ --extra-args='console=ttyS0'");
  printf("Alright, the virtual machine is up and running. Let's check its network interfaces.\n");
  system("virsh domiflist myvm");
  printf("Looks like everything is in order. Let's now create a new user account on the virtual machine.\n");
  system("virsh console myvm");
  system("sudo useradd -m testuser");
  system("sudo passwd testuser");
  printf("Great, we now have a new user account on the virtual machine. Let's disconnect from the console and take a snapshot of the virtual machine.\n");
  system("^]");
  system("virsh snapshot-create-as myvm myvm-snapshot");
  printf("Perfect, the snapshot has been created. Time to shut down and delete the virtual machine.\n");
  system("virsh shutdown myvm");
  system("virsh undefine myvm");
  printf("All done! That was fun, huh?\n");
  return 0;
}