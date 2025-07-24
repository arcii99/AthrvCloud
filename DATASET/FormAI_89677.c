//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARRIAGES 20 // Maximum number of carriages in the simulation
#define MAX_ROUNDS 100 // Maximum number of simulation rounds

int main()
{
    // Set up random seed
    srand(time(NULL));

    // Initialize variables
    int carriages[MAX_CARRIAGES]; // Array representing the carriages on the road
    int num_carriages = 5; // Number of initial carriages
    int round = 0; // Current simulation round

    // Generate initial carriages randomly
    printf("Creating initial carriages...\n");
    for (int i = 0; i < num_carriages; i++) {
        carriages[i] = rand() % 2; // 0 represents empty carriage, 1 represents carriage with a person
    }

    // Simulation loop
    while (round < MAX_ROUNDS) {
        printf("Round %d...\n", round);

        // Determine which carriages will enter the road in this round
        int new_carriages = rand() % 4; // Maximum of 3 new carriages per round
        for (int i = num_carriages; i < num_carriages + new_carriages; i++) {
            carriages[i] = rand() % 2; // Same as generating initial carriages
        }
        num_carriages += new_carriages;

        // Print the current state of the road
        printf("Current road: ");
        for (int i = 0; i < num_carriages; i++) {
            printf("%d ", carriages[i]);
        }
        printf("\n");

        // Simulate traffic flow
        for (int i = 0; i < num_carriages - 1; i++) {
            if (carriages[i] == 1 && carriages[i+1] == 0) {
                // Carriage with a person requests to change lanes
                if (rand() % 2 == 0) {
                    // Decision is to switch lanes
                    carriages[i] = 0;
                    carriages[i+1] = 1;
                    printf("Person in carriage %d is changing lanes\n", i+1);
                } else {
                    // Decision is not to switch lanes
                    printf("Person in carriage %d is staying in lane\n", i+1);
                }
            }
        }

        // Increment round counter
        round++;
    }

    printf("End of simulation\n");
    return 0;
}