//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Romeo and Juliet
/* Romeo and Juliet: A Boot Optimizer Love Story */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Enter boot device to optimize:");
    char device[50];
    scanf("%s", device);

    printf("\nThou art the device I seek, %s\n", device);

    printf("Allow me to check the device partitioning, my dearest.\n");
    printf("Verily, the partitioning table shall be fine-tuned to our heart's desire.\n");

    char command[200];
    sprintf(command, "fdisk /dev/%s", device);
    system(command);

    printf("Now, my love, let us optimize the file system for speedy booting.\n");
    printf("I shall summon the tune2fs utility to perform the task with utmost care.\n");

    char confirm[5];
    printf("Do you grant me permission to proceed, my love? (Y/N)");
    scanf("%s", confirm);

    if (strcmp(confirm, "Y") != 0) {
        printf("\nAlas! Why doth thou hinder our progress, my love?\n");
        printf("I shall take my leave, with sorrow in my heart.\n");
        return 0;
    }

    sprintf(command, "tune2fs -O ^has_journal /dev/%s1", device);
    system(command);

    printf("Eureka! Our device is now optimized for swift and seamless booting.\n");
    printf("I shall now forever cherish the memories of this moment, my love.\n");
    printf("Let us restart the system and bask in its newfound splendor.\n");

    sprintf(command, "shutdown -r now");
    system(command);

    return 0;
}