//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_BAGS 100
#define NUM_CONVEYORS 5

// Function to simulate the loading of bags onto the conveyor belts
void load_bags_to_conveyors(int conveyors[], int bags[]) {
    int i, j;
    for(i = 0; i < NUM_BAGS; i++) {
        j = rand()%NUM_CONVEYORS;
        conveyors[j] += bags[i];
        printf("Bag %d loaded onto Conveyor %d\n", i+1, j+1);
    }
}

// Function to simulate the unloading of bags from the conveyor belts to the planes
void unload_bags_to_planes(int conveyors[]) {
    int i;
    for(i = 0; i < NUM_CONVEYORS; i++) {
        printf("Conveyor %d unloading...\n", i+1);
        conveyors[i] = 0;
    }
    printf("All bags unloaded to planes\n");
}

// Driver program to test the simulation
int main() {
    srand(time(NULL));
    int conveyors[NUM_CONVEYORS] = {0};
    int bags[NUM_BAGS];

    // Initialize bags with random weights
    int i;
    for(i = 0; i < NUM_BAGS; i++) {
        bags[i] = rand()%50 + 1;
    }

    // Load bags onto conveyor belts and print status
    load_bags_to_conveyors(conveyors, bags);
    printf("\nConveyors status:\n");
    for(i = 0; i < NUM_CONVEYORS; i++) {
        printf("Conveyor %d: %d kg\n", i+1, conveyors[i]);
    }

    // Unload bags from conveyor belts to planes and print status
    printf("\n");
    unload_bags_to_planes(conveyors);
    printf("\nConveyors status:\n");
    for(i = 0; i < NUM_CONVEYORS; i++) {
        printf("Conveyor %d: %d kg\n", i+1, conveyors[i]);
    }

    return 0;
}