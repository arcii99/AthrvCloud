//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_TERMINALS 5

int main() {
    srand(time(NULL)); // Initialize random seed

    int terminal, bagsCount, bagsProcessedCount;
    int bags[MAX_BAGS]; // Array to hold bag arrival times

    // Simulate baggage arrival times
    printf("# Baggage arrival times:\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        int arrivalTime = rand() % 60 + 1; // Random time between 1 and 60 minutes
        bags[i] = arrivalTime;
        printf("Bag%d: %d minutes\n", i + 1, arrivalTime);
    }

    // Simulate baggage handling process
    printf("\n# Baggage handling simulation:\n");
    for (terminal = 1; terminal <= MAX_TERMINALS; terminal++) {
        printf("Terminal %d:\n", terminal);
        bagsProcessedCount = 0;

        // Start processing bags
        for (int i = 0; i < MAX_BAGS; i++) {
            if (bags[i] == -1) continue; // Bag has already been processed
            if (bags[i] <= 5) { // Bag is ready for pickup
                printf("Bag%d processed at Terminal %d\n", i + 1, terminal);
                bags[i] = -1;
                bagsProcessedCount++;
            }
            else if (bags[i] > 5) { // Bag still needs more processing time
                printf("Bag%d still being processed at Terminal %d (%d more minutes)\n", i + 1, terminal, bags[i] - 5);
                bags[i] -= 5;
            }
            if (bagsProcessedCount == MAX_BAGS) break; // All bags have been processed
        }
    }

    printf("\nAll bags have been processed.\n");

    return 0;
}