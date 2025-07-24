//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


int main() {

    int total_memory, free_memory, used_memory, buffers, cached, shared;

    while (true) {
        system("clear"); // Clears the console to show updated RAM usage.

        // Reads the necessary information from the /proc/meminfo file where the system stores RAM usage.
        FILE *meminfo = fopen("/proc/meminfo", "r");
        fscanf(meminfo, "MemTotal: %d kB\n", &total_memory);
        fscanf(meminfo, "MemFree: %d kB\n", &free_memory);
        fscanf(meminfo, "Buffers: %d kB\n", &buffers);
        fscanf(meminfo, "Cached: %d kB\n", &cached);
        fscanf(meminfo, "Shared: %d kB\n", &shared);
        fclose(meminfo);

        // Calculates the used memory from the collected data.
        used_memory = total_memory - free_memory - buffers - cached - shared;

        // Prints out the RAM usage in an immersive way.
        printf("\n\nWelcome to the C RAM Monitor!\n");
        printf("====================================\n");
        printf("Total Memory: %d KB\n", total_memory);
        printf("Used Memory: %d KB\n", used_memory);
        printf("Free Memory: %d KB\n", free_memory);
        printf("Buffers: %d KB\n", buffers);
        printf("Cached: %d KB\n", cached);
        printf("Shared: %d KB\n", shared);
        printf("====================================\n\n");

        sleep(1); // Wait for 1 second before updating the RAM usage again.
    }

    return 0;
}