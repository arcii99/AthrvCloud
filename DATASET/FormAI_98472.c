//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define MAX_WEIGHT 50
#define MAX_FLOORS 5

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize variables
    int bags[NUM_BAGS];
    int floors[MAX_FLOORS] = {0};
    int total_weight = 0;

    // Load bags onto conveyor belt
    for (int i = 0; i < NUM_BAGS; i++) {
        // Randomly generate bag weight
        int weight = rand() % MAX_WEIGHT + 1;

        // Add bag weight to total weight
        total_weight += weight;

        // Add bag to conveyor belt
        bags[i] = weight;
    }

    // Print out total weight of bags
    printf("Total weight of bags: %d\n", total_weight);

    // Process bags on conveyor belt
    for (int i = 0; i < NUM_BAGS; i++) {
        // Choose a random floor to send bag to
        int floor = rand() % MAX_FLOORS;

        // Add bag weight to floor total
        floors[floor] += bags[i];

        // Print out movement of bag
        printf("Bag %d: Floor %d --> Baggage Claim\n", i+1, floor+1);
    }

    // Print out total weight processed for each floor
    printf("Total weight per floor:\n");
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("Floor %d: %d\n", i+1, floors[i]);
    }

    // Exit program
    return 0;
}