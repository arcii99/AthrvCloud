//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define CONVEYOR_SIZE 50 // Conveyor maximum capacity
#define NUM_BAGS 200 // Total number of bags to be processed

typedef struct {
    int id;
    int weight;
} Bag;

int main() {
    Bag conveyor[CONVEYOR_SIZE];
    int in = 0;
    int out = 0;
    int numProcessed = 0;
    int totalWeight = 0;
    int numLost = 0;

    for (int i = 0; i < NUM_BAGS; i++) {
        // Generate random bag weight
        int weight = rand() % 50 + 1;

        // Add bag to conveyor
        if ((in + 1) % CONVEYOR_SIZE == out) { // Conveyor is full
            printf("Conveyor full. Bag lost with weight %d\n", weight);
            numLost++;
        } else { // Add bag to conveyor
            Bag bag;
            bag.id = i;
            bag.weight = weight;
            totalWeight += weight;
            conveyor[in] = bag;
            in = (in + 1) % CONVEYOR_SIZE;
        }

        // Process bag from conveyor
        if (out != in) { // Conveyor is not empty
            Bag bag = conveyor[out];
            totalWeight -= bag.weight;
            out = (out + 1) % CONVEYOR_SIZE;
            numProcessed++;
        }
    }

    // Print out simulation results
    printf("Simulation complete.\n");
    printf("Total bags processed: %d\n", numProcessed);
    printf("Total bags lost: %d\n", numLost);
    printf("Average bag weight: %d\n", totalWeight / numProcessed);

    return 0;
}