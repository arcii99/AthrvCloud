//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize variables for the simulation
    int num_bags = 100;
    int conveyor_speed = 10;
    int conveyor_length = 50;
    int processing_time = 2;
    int min_wait_time = 1;
    int max_wait_time = 5;

    int bags_on_conveyor = 0;
    int bags_processed = 0;
    int bags_lost = 0;

    srand(time(NULL)); // Seed random number generator

    // Begin simulation loop
    for (int i = 0; i < num_bags; i++) {

        // Determine if bag makes it onto conveyor
        int r = rand() % 100;

        if (r < 50) {
            printf("Bag lost in surreal fashion.\n");
            bags_lost++;
            continue;
        }

        // Calculate time for bag to reach end of conveyor
        int conveyor_time = conveyor_length / conveyor_speed;

        // Wait for bag to arrive at end of conveyor
        for (int j = 1; j <= conveyor_time; j++) {
            printf("Waiting for bag to arrive on conveyor: %ds\n", j);
            sleep(1);
        }

        // Random processing time for each bag
        int p_time = rand() % processing_time + 1 + min_wait_time;

        // Process the bag
        for (int k = 1; k <= p_time; k++) {
            printf("Processing the bag: %ds\n", k);
            sleep(1);
        }

        printf("Bag processed and removed from system.\n");

        bags_processed++;

    }

    // Print simulation results
    printf("\nSimulation completed.\n");
    printf("Bags processed: %d\n", bags_processed);
    printf("Bags lost: %d\n", bags_lost);

    return 0;
}