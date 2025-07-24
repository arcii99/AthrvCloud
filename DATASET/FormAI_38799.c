//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGGAGE 50 // Total number of baggage
#define NUM_CONVEYORS 5 // Number of conveyors

// Enum for specifying the conveyors
enum Conveyors {
    Conveyor1, Conveyor2, Conveyor3, Conveyor4, Conveyor5
};

// Struct for baggage
typedef struct Baggage {
    int id;
    enum Conveyors conveyor;
} Baggage;

// Function for generating random conveyor number
int getRandomConveyor() {
    return rand() % NUM_CONVEYORS;
}

int main() {
    srand(time(NULL)); // For generating random numbers

    // Initializing an array of baggage
    Baggage baggage[NUM_BAGGAGE];
    for(int i = 0; i < NUM_BAGGAGE; i++) {
        baggage[i].id = i+1;
        baggage[i].conveyor = (enum Conveyors) getRandomConveyor();
    }

    // Printing out the initial conveyor numbers for each baggage
    printf("Initial Baggage Distribution:\n");
    for(int i = 0; i < NUM_BAGGAGE; i++) {
        printf("Baggage %d: Conveyor %d\n", baggage[i].id, baggage[i].conveyor+1);
    }

    // Simulating the baggage handling
    for(int i = 0; i < NUM_BAGGAGE; i++) {
        /* 
         * Write your simulation code here
         * You can use the 'baggage[i].conveyor' to perform different operations on conveyors
         * For example, you can move the baggage from one conveyor to another, or wait if the
         * conveyor is busy, etc.
         */
    }

    printf("\nSimulation completed successfully!\n");

    return 0;
}