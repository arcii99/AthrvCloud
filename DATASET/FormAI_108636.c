//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_BAGS 100
#define MAX_WEIGHT 50
#define MAX_CAPACITY 200
#define MAX_DELAY 10

int main() {
    int bag_weights[NUM_BAGS];
    int total_weight = 0;
    bool capacity_full = false;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random baggage weights
    for (int i = 0; i < NUM_BAGS; i++) {
        bag_weights[i] = rand() % MAX_WEIGHT;
        total_weight += bag_weights[i];
    }

    // Simulate baggage handling process
    for (int i = 0; i < NUM_BAGS; i++) {
        // Check if the capacity is full
        if (total_weight > MAX_CAPACITY) {
            capacity_full = true;
            break;
        }

        // Delay
        int delay = rand() % MAX_DELAY;
        sleep(delay);

        // Add baggage weight to total
        total_weight += bag_weights[i];
    }

    // Check if any luggage was left behind
    if (capacity_full) {
        printf("WARNING: Maximum capacity reached. Some luggage may have been left behind.\n");
        // Code to handle left behind luggage
    } else {
        printf("All luggage loaded successfully.\n");
    }

    return 0;
}