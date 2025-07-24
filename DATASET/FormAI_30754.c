//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_TIME 10

int main()
{
    int bags_processed = 0;
    double avg_time = 0.0;
    int bags[MAX_BAGS] = {0}; // Initialize all bags to not being processed
    int current_bag, arrival_time, departure_time;

    srand(time(NULL)); // Seed the random number generator

    // Run the simulation for a fixed number of iterations
    for (int i = 0; i < MAX_TIME; i++)
    {
        // Generate random arrivals and departures
        current_bag = rand() % MAX_BAGS;
        arrival_time = rand() % 10;
        departure_time = rand() % 10;

        // If the bag is already being processed, skip it
        if (bags[current_bag] != 0)
        {
            continue;
        }

        // Otherwise, mark the bag as being processed and add the processing time to the average
        bags[current_bag] = 1;
        bags_processed++;
        avg_time = ((avg_time * (bags_processed - 1)) + (arrival_time + departure_time)) / bags_processed;

        // Wait for the baggage to be processed
        printf("Bag %d arriving at time %d\n", current_bag, i);
        for (int j = 0; j < arrival_time; j++)
        {
            printf("Processing bag %d... (%d/%d)\n", current_bag, j, arrival_time);
        }

        printf("Bag %d departing at time %d\n", current_bag, i);
        for (int j = 0; j < departure_time; j++)
        {
            printf("Processing bag %d... (%d/%d)\n", current_bag, j, departure_time);
        }

        // Mark the bag as no longer being processed
        bags[current_bag] = 0;

    }

    printf("\n\nSimulation complete.\n");
    printf("Total bags processed: %d\n", bags_processed);
    printf("Average bag processing time: %.2lf\n", avg_time);

    return 0;
}