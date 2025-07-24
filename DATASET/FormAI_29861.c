//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    unsigned int maxRams, freeRams, usedRams;

    // Get the initial value of free RAM
    FILE* fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error reading memory info");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "MemAvailable: %u kB", &freeRams);
    fclose(fp);

    // Set the maximum RAM limit based on the available RAM
    maxRams = freeRams / 2;

    printf("RAM usage monitor starting...\n");

    while (1) {
        // Get the current value of free RAM
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            perror("Error reading memory info");
            exit(EXIT_FAILURE);
        }
        fscanf(fp, "MemAvailable: %u kB", &freeRams);
        fclose(fp);

        // Calculate the used RAM and print the results
        usedRams = maxRams - freeRams;
        printf("Current RAM usage: %u kB out of %u kB\n", usedRams, maxRams);

        // Wait for 10 seconds before checking the RAM usage again
        sleep(10);
    }

    return 0;
}