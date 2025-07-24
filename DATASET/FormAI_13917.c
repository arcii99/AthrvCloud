//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100  // number of bags to simulate
#define NUM_CONVEYORS 10  // number of conveyor belts in the system
#define CONVEYOR_CAPACITY 50  // maximum number of bags each conveyor can hold

// Struct for simulating bags
typedef struct {
    int id;  // unique ID for each bag
    int time_arrival;  // time at which the bag arrives at the system
    int time_departure;  // time at which the bag leaves the system
} Bag;

// Function to initialize a Bag
Bag initBag(int id, int time_arrival) {
    Bag bag;
    bag.id = id;
    bag.time_arrival = time_arrival;
    bag.time_departure = -1;  // not yet departed
    return bag;
}

// Function to simulate the airport baggage handling system
void simulateBaggageHandling() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize bags
    Bag bags[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i] = initBag(i, rand() % 60);  // assume bags arrive randomly within first hour
    }

    // Initialize conveyors and their current number of bags
    int conveyors[NUM_CONVEYORS] = {0}; 

    // Simulation loop
    for (int t = 0; t < 60; t++) {  // assume simulation runs for one hour
        // Check for bags that have arrived at this time
        for (int i = 0; i < NUM_BAGS; i++) {
            if (bags[i].time_arrival == t) {
                // Assign bag to a conveyor with available space
                int conveyor_assigned = -1;
                for (int j = 0; j < NUM_CONVEYORS; j++) {
                    if (conveyors[j] < CONVEYOR_CAPACITY) {
                        conveyor_assigned = j;
                        conveyors[j]++;
                        break;
                    }
                }
                
                // Print simulation output
                printf("Bag %d assigned to Conveyor %d at time %d.\n", bags[i].id, conveyor_assigned, t);
            }
        }

        // Check for bags that have departed at this time
        for (int i = 0; i < NUM_BAGS; i++) {
            if (bags[i].time_departure == -1 && t >= bags[i].time_arrival + 5) {  // assume bags take 5 minutes to process
                // Find conveyor that bag is on and remove it
                for (int j = 0; j < NUM_CONVEYORS; j++) {
                    if (conveyors[j] > 0) {
                        conveyors[j]--;
                        bags[i].time_departure = t;
                        printf("Bag %d departed from Conveyor %d at time %d.\n", bags[i].id, j, t);
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    simulateBaggageHandling();
    return 0;
}