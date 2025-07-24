//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
/* This program simulates a baggage handling system at an airport, taking inspiration from Ada Lovelace's analytical approach to computing. */

#include <stdio.h>
#include <stdlib.h>

#define NUM_BAGS 100  // The number of bags to simulate

int main(void) {
    int i, j;  // Loop counters
    int bag_destinations[NUM_BAGS];  // Array of bag destinations
    int conveyor_belts[3][10];  // Array of conveyor belts

    // Initialize bag destinations
    for(i = 0; i < NUM_BAGS; i++) {
        bag_destinations[i] = rand() % 3;  // Randomly assign destinations
    }

    // Initialize conveyor belts
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 10; j++) {
            conveyor_belts[i][j] = -1;  // -1 indicates an empty slot
        }
    }

    // Simulate baggage handling
    for(i = 0; i < NUM_BAGS; i++) {
        int destination = bag_destinations[i];  // Destination of the bag
        int belt_num = rand() % 3;  // Randomly select a conveyor belt
        int empty_slot = -1;  // Index of the first empty slot on the belt

        // Find the first empty slot on the selected belt
        for(j = 0; j < 10; j++) {
            if(conveyor_belts[belt_num][j] == -1) {
                empty_slot = j;
                break;
            }
        }

        if(empty_slot >= 0) {
            conveyor_belts[belt_num][empty_slot] = destination;  // Add the bag to the belt
            printf("Bag %d added to conveyor belt %d\n", i, belt_num);
        } else {
            printf("No empty slots on conveyor belt %d\n", belt_num);
            break;  // Stop adding bags if there are no empty slots
        }
    }

    // Print the final state of the conveyor belts
    printf("Final state of conveyor belts:\n");
    for(i = 0; i < 3; i++) {
        printf("Conveyor belt %d:", i);
        for(j = 0; j < 10; j++) {
            if(conveyor_belts[i][j] >= 0) {
                printf(" %d", conveyor_belts[i][j]);
            } else {
                printf(" -");
            }
        }
        printf("\n");
    }

    return 0;
}