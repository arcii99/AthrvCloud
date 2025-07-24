//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Initialize variables
    int usage = 0, prevIdle = 0, currIdle = 0, prevTotal = 0, currTotal = 0;
    char cpu[10];

    // Run infinitely
    while (1) {
        // Open /proc/stat file
        FILE* file = fopen("/proc/stat", "r");

        // Read the first line
        fgets(cpu, sizeof(cpu), file);
        fclose(file);

        // Parse the values
        sscanf(cpu, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %*d %*d %*d %d", &currIdle, &currTotal);

        // Calculate the CPU usage
        if (prevIdle != 0 && prevTotal != 0) {
            int diffIdle = currIdle - prevIdle;
            int diffTotal = currTotal - prevTotal;
            usage = (1000 * (diffTotal - diffIdle)) / diffTotal;
        }

        // Print the usage percentage
        printf("CPU usage: %d.%d%%\n", usage / 10, usage % 10);

        // Sleep for 1 second
        sleep(1);

        // Update the previous values
        prevIdle = currIdle;
        prevTotal = currTotal;
    }

    return 0;
}