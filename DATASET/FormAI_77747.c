//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("C RAM Usage Monitor\n");
    printf("-------------------\n");

    while(1) {
        // Open the file containing the system memory information
        FILE* memFile = fopen("/proc/meminfo", "r");
        if (memFile == NULL) {
            printf("Error: Could not open /proc/meminfo\n");
            exit(1);
        }

        // Parse the file to extract relevant data
        char line[256];
        int totalMem = 0;
        int freeMem = 0;
        while (fgets(line, sizeof(line), memFile)) {
            sscanf(line, "MemTotal: %d kB", &totalMem);
            sscanf(line, "MemFree: %d kB", &freeMem);
        }
        fclose(memFile);

        // Calculate memory usage
        int usedMem = totalMem - freeMem;
        double percentageUsed = ((double) usedMem / (double) totalMem) * 100;

        // Print out results
        printf("Total Memory: %d kB\n", totalMem);
        printf("Free Memory: %d kB\n", freeMem);
        printf("Used Memory: %d kB\n", usedMem);
        printf("Memory Usage: %.2f%%\n", percentageUsed);

        // Wait for a second before checking again
        sleep(1);
    }

    return 0;
}