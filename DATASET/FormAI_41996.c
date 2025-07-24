//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 1000   // Maximum number of baggage that can be handled
#define MAX_TIME 60        // Maximum time of simulation in minutes
#define BAGGAGE_SIZE 50    // Maximum weight of a single piece of baggage in lbs
#define TRUCK_CAPACITY 500 // Maximum weight a baggage truck can carry in lbs

int main()
{
    int baggage[MAX_BAGGAGE]; // Array for storing baggage weights
    int num_bags = 0;         // Number of bags in system
    int curr_time = 0;        // Current time in simulation
    int i;                    // Loop variable

    // Seed random number generator
    srand(time(NULL));

    // Initialize baggage array to random weights
    for (i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i] = rand() % BAGGAGE_SIZE + 1;
    }

    // Run simulation
    while (curr_time < MAX_TIME) {
        // Print current time
        printf("Time: %d\n", curr_time);

        // Check if there is any baggage to process
        if (num_bags == 0) {
            printf("No baggage to process.\n");
        }
        else {
            // Calculate number of trucks needed to transport baggage
            int num_trucks = num_bags / TRUCK_CAPACITY + 1;

            // Print number of trucks needed
            printf("Number of trucks needed: %d\n", num_trucks);

            // Load baggage onto trucks
            int truck_capacity = 0;
            for (i = 0; i < num_bags; i++) {
                // Check if current bag can fit on truck
                if (truck_capacity + baggage[i] <= TRUCK_CAPACITY) {
                    // Add bag to truck and remove from system
                    truck_capacity += baggage[i];
                    num_bags--;
                }
                else {
                    // Move on to next truck
                    printf("Truck is full. Moving on to next truck.\n");
                    truck_capacity = 0;
                    num_trucks--;
                }

                // Check if all trucks are full
                if (num_trucks == 0) {
                    break;
                }
            }
        }

        // Generate new random baggage weights
        for (i = 0; i < MAX_BAGGAGE; i++) {
            baggage[i] = rand() % BAGGAGE_SIZE + 1;
        }

        // Wait for one minute
        printf("Press Enter to continue...\n");
        fflush(stdin);
        getchar();

        // Increment time
        curr_time++;
    }

    return 0;
}