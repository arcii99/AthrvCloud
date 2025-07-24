//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

// Function to randomly generate the number of bags for each passenger
int generate_bags() {
    int num_bags = rand() % 6; // Randomly generates a number between 0 and 5
    return num_bags;
}

// Function to initialize the baggage for all flights
void init_baggage(int baggage[][MAX_BAGS]) {
    int i, j;
    for (i = 0; i < MAX_FLIGHTS; i++) {
        for (j = 0; j < MAX_BAGS; j++) {
            baggage[i][j] = -1; // Initializes each slot in the 2D array to -1
        }
    }
}

int main() {
    int baggage[MAX_FLIGHTS][MAX_BAGS];
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the baggage for all flights
    init_baggage(baggage);

    // Generate baggage for each passenger and add it to the appropriate flight
    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d:\n", i+1);
        for (j = 0; j < MAX_BAGS; j++) {
            int num_bags = generate_bags();
            if (num_bags > 0) {
                baggage[i][j] = num_bags; // Add the baggage to the flight
                printf("Passenger %d has %d bags\n", j+1, num_bags);
            }
        }
        printf("\n");
    }

    // Print out the baggage for each flight
    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d:\n", i+1);
        for (j = 0; j < MAX_BAGS; j++) {
            if (baggage[i][j] > 0) {
                printf("Passenger %d has %d bags\n", j+1, baggage[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}