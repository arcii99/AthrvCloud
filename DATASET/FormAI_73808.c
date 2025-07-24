//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define MB 1048576 // 1 MB = 1048576 bytes

int main() {
    printf("Welcome to the C RAM usage monitor!\n");

    struct sysinfo info;
    unsigned long long totalMem = 0;
    unsigned long long freeMem = 0;
    unsigned long long usedMem = 0;
    unsigned long long buffers = 0;
    unsigned long long cached = 0;

    while (1) {
        if (sysinfo(&info) != 0) {
            printf("Error: Could not retrieve system information.\n");
            exit(1);
        }

        totalMem = info.totalram * (unsigned long long)info.mem_unit;
        freeMem = info.freeram * (unsigned long long)info.mem_unit;
        buffers = info.bufferram * (unsigned long long)info.mem_unit;
        cached = info.sharedram * (unsigned long long)info.mem_unit;
        usedMem = totalMem - freeMem - buffers - cached;

        printf("Total Memory:\t%llu MB\n", totalMem/MB);
        printf("Used Memory:\t%llu MB\n", usedMem/MB);
        printf("Free Memory:\t%llu MB\n", freeMem/MB);
        printf("Buffers:\t%llu MB\n", buffers/MB);
        printf("Cached:\t\t%llu MB\n", cached/MB);

        sleep(5); // wait for 5 seconds before refreshing the memory usage
        system("clear"); // clears the screen for better readability
    }

    return 0;
}