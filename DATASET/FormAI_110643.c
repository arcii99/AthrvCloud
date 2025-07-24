//FormAI DATASET v1.0 Category: System boot optimizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void boot_optimize(char *boot_drive) {
    printf("Boot optimizing on %s...\n", boot_drive);

    // simulate optimizing process
    int progress = 0;
    while (progress < 100) {
        int increment = rand() % 10 + 1;
        progress += increment;
        printf("Optimizing... %d%%\n", progress);
        sleep(1);
    }

    printf("Boot optimization complete!\n");
}

void main() {
    // get user input for boot drive
    printf("Enter the drive letter of your boot drive: ");
    char boot_drive[2];
    scanf("%s", boot_drive);

    // perform boot optimization
    boot_optimize(boot_drive);
}