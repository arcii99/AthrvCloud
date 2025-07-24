//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define INTERVAL 1

void printMemoryUsage() {
    struct sysinfo info;
    sysinfo(&info);

    // Calculate memory usage statistics
    long long totalRam = info.totalram / 1024 / 1024;
    long long usedRam = (info.totalram - info.freeram) / 1024 / 1024;
    long long freeRam = info.freeram / 1024 / 1024;
    long long bufferRam = info.bufferram / 1024 / 1024;
    long long cachedRam = info.sharedram / 1024 / 1024;

    // Print out memory usage statistics
    printf("Total RAM: %lld MB\n", totalRam);
    printf("Used RAM: %lld MB\n", usedRam);
    printf("Free RAM: %lld MB\n", freeRam);
    printf("Buffered RAM: %lld MB\n", bufferRam);
    printf("Cached RAM: %lld MB\n", cachedRam);

    // Calculate percentage of total RAM used
    double percentUsed = ((double)usedRam / (double)totalRam) * 100.0;

    // Print percentage of total RAM used
    printf("RAM usage: %.2f%%\n", percentUsed);
}

int main() {
    // Loop indefinitely
    while (1) {
        // Clear the console
        system("clear");

        // Print memory usage statistics
        printMemoryUsage();

        // Wait for specified interval
        sleep(INTERVAL);
    }

    return 0;
}