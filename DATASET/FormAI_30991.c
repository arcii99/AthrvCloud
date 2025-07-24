//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

int main() {
    printf("Welcome to the Happy C RAM Usage Monitor!\n\n");

    printf("Preparing to monitor RAM usage...\n");

    for (int i = 1; i <= 10; i++) {
        printf("\nStarting monitoring cycle %i of 10\n", i);

        struct sysinfo sys_info;
        if (sysinfo(&sys_info) != 0) {
            printf("An error occurred while monitoring RAM usage. Exiting program.\n");
            exit(1);
        }

        unsigned long total_ram = sys_info.totalram / 1024;
        unsigned long used_ram = (sys_info.totalram - sys_info.freeram) / 1024;
        unsigned long free_ram = sys_info.freeram / 1024;

        printf("Total RAM: %lu kB\n", total_ram);
        printf("Used RAM: %lu kB\n", used_ram);
        printf("Free RAM: %lu kB\n", free_ram);

        printf("\n");

        sleep(2);
    }

    printf("\nMonitoring complete! Thank you for using the Happy C RAM Usage Monitor!\n");

    return 0;
}