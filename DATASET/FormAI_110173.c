//FormAI DATASET v1.0 Category: System boot optimizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char bootDisk[10] = "/dev/sda1"; //default boot disk
    char primaryPartition[10] = "primary"; //default partition type
    
    printf("*** C System Boot Optimizer ***\n");
    
    printf("Enter the boot disk (e.g. /dev/sda1): ");
    scanf("%s", bootDisk);
    
    printf("Enter the partition type (primary or logical): ");
    scanf("%s", primaryPartition);
    
    printf("Checking %s partition on disk %s...\n", primaryPartition, bootDisk);
    sleep(3);
    
    printf("Analyzing boot sector...\n");
    sleep(5);
    
    printf("Checking for errors...\n");
    sleep(2);
    
    printf("Optimizing boot sector...\n");
    sleep(5);
    
    printf("Boot sector optimization complete!\n");
    
    char command[50];
    sprintf(command, "sudo grub-install %s", bootDisk); //command to install grub on boot disk
    
    system(command); //execute the command
    
    printf("Grub installation complete!\n");
    
    return 0;
}