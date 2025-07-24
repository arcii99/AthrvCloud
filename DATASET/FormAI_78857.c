//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Airport Baggage Handling Simulation!\n");

    // Set up variables for the simulation
    int total_waiting_time = 0;
    int total_bags_processed = 0;
    int max_waiting_time = 0;
    srand(time(NULL));

    // Simulation loop runs five times
    for (int i = 0; i < 5; i++) {

        printf("\nRunning simulation %d...\n", i + 1);

        // Generate random number of bags between 1 and 10
        int num_bags = rand() % 10 + 1;
        printf("Processing %d bags...\n", num_bags);

        // Set up variables for this simulation run
        int waiting_time = 0;
        int bags_processed = 0;

        // Loop through bags
        for (int j = 0; j < num_bags; j++) {

            // Generate random processing time between 1 and 5 seconds
            int processing_time = rand() % 5 + 1;

            // Add processing time to waiting time
            waiting_time += processing_time;

            // Print message for this bag
            printf("Processing bag %d (time: %d seconds)...\n", j + 1, processing_time);

            // Increment counter for bags processed
            bags_processed++;
        }

        // Print results for this simulation run
        printf("\nBags processed: %d\n", bags_processed);
        printf("Total waiting time: %d seconds\n", waiting_time);

        // Add results for this simulation run to total results
        total_bags_processed += bags_processed;
        total_waiting_time += waiting_time;

        // Keep track of the maximum waiting time
        if (waiting_time > max_waiting_time) {
            max_waiting_time = waiting_time;
        }
    }

    // Print total results for all simulation runs
    printf("\nOverall results:\n");
    printf("Total bags processed: %d\n", total_bags_processed);
    printf("Average waiting time: %d seconds\n", total_waiting_time / 5);
    printf("Maximum waiting time: %d seconds\n", max_waiting_time);

    return 0;
}