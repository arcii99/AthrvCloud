//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h> // For system memory information

int main() {
    struct sysinfo memInfo; // Create a struct to hold memory information
    sysinfo(&memInfo);      // Populate the struct with system memory info

    // Calculate RAM usage statistics
    long long totalRam = memInfo.totalram / 1024 / 1024;
    long long freeRam = memInfo.freeram / 1024 / 1024;
    long long usedRam = totalRam - freeRam;
    int percentageUsed = (int)((double)usedRam / totalRam * 100);

    // Print the RAM usage statistics
    printf("Total RAM: %lld MB\n", totalRam);
    printf("Free RAM: %lld MB\n", freeRam);
    printf("Used RAM: %lld MB\n", usedRam);
    printf("Percentage Used: %d%%\n", percentageUsed);

    return 0;
}