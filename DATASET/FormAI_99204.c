//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define MEM_INFO_PATH "/proc/meminfo"

void monitorRAMUsage() {
    int memTotal, memFree, memAvailable, buffers, cached, swapCached, swapTotal, swapFree, bytesRead, memUsed, swapUsed;
    char buffer[256];
    const char* pattern = "MemTotal:";
    FILE* file;

    while (1) {
        file = fopen(MEM_INFO_PATH, "r");
        if (file == NULL) {
            fprintf(stderr, "Cannot open %s\n", MEM_INFO_PATH);
            exit(EXIT_FAILURE);
        }

        // Get total physical memory
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strstr(buffer, pattern)) {
                sscanf(buffer, "%*s %d", &memTotal);
                break;
            }
        }

        // Get memory details
        bytesRead = fscanf(file, "MemFree: %d kB\nBuffers: %d kB\nCached: %d kB\nMemAvailable: %d kB",
                          &memFree, &buffers, &cached, &memAvailable);
        if (bytesRead != 4) {
            fprintf(stderr, "Could not read required data from %s\n", MEM_INFO_PATH);
            exit(EXIT_FAILURE);
        }

        // Calculate RAM usage
        memUsed = memTotal - memFree - buffers - cached;

        // Get swap details
        bytesRead = fscanf(file, "SwapCached: %d kB\nSwapTotal: %d kB\nSwapFree: %d kB\n",
                          &swapCached, &swapTotal, &swapFree);
        if (bytesRead != 3) {
            fprintf(stderr, "Could not read required data from %s\n", MEM_INFO_PATH);
            exit(EXIT_FAILURE);
        }

        // Calculate swap usage
        swapUsed = swapTotal - swapFree;

        // Print status
        printf("RAM usage: %.2f%% (%d MB) | Swap usage: %.2f%% (%d MB)\n",
               (double) memUsed / memTotal * 100, memUsed / 1024,
               (double) swapUsed / swapTotal * 100, swapUsed / 1024);

        fclose(file);
        sleep(5);
    }
}

int main() {
    printf("Starting RAM usage monitor\n");

    monitorRAMUsage();

    return 0;
}