//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define CPU_CORES 8 // Assuming 8 cores

int main() {
    int cpu_load[CPU_CORES]; // Array to store individual core usage
    srand(time(0)); // Seed random number generator

    while (1) {
        // Generate random CPU usage for each core
        for (int i = 0; i < CPU_CORES; i++) {
            cpu_load[i] = rand() % 101; // Range from 0-100
        }

        // Print current CPU usage
        printf("Current CPU usage:\n");
        for (int i = 0; i < CPU_CORES; i++) {
            printf("Core %d: %d%%\n", i+1, cpu_load[i]);
        }

        // Wait for 1 second before refreshing
        sleep(1);

        // Clear console before refreshing with new data
        system("clear");
    }
    return 0;
}