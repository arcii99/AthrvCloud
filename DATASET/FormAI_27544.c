//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define SLEEP_TIME 5 // Sleep time in seconds.

// Function to get current RAM usage in percent.
int getRAMUsage() {
    struct sysinfo info;
    if(sysinfo(&info) != 0) {
        fprintf(stderr, "Error: Cannot get system information.\n");
        return -1;
    }

    unsigned long long total_ram = info.totalram * info.mem_unit;
    unsigned long long free_ram = info.freeram * info.mem_unit;
    unsigned long long used_ram = total_ram - free_ram;

    return (int) (used_ram * 100 / total_ram);
}

int main() {
    while(true) {
        int ram_usage = getRAMUsage();
        if(ram_usage == -1) {
            printf("Exiting program.\n");
            exit(1);
        }

        printf("RAM usage: %d%%\n", ram_usage);
        sleep(SLEEP_TIME);
    }

    return 0;
}