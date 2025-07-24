//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Number of baggage handlers
    const int NUM_HANDLERS = 5;

    // Number of bags to handle
    const int NUM_BAGS = 30;

    // Time interval to simulate (in seconds)
    const int TIME_INTERVAL = 10;

    // Seed for generating random numbers
    srand(time(NULL));

    int bags_processed = 0;
    int handler_num, bag_weight, bag_destination, bag_delay;

    // Initialize array of destinations
    const char* DESTINATIONS[] = {"New York", "Los Angeles", "Miami", "Chicago", "Denver"};

    printf("Starting Baggage Handling Simulation...\n\n");

    while(bags_processed < NUM_BAGS) {

        // Randomly select a baggage handler
        handler_num = rand() % NUM_HANDLERS;

        // Randomly generate bag data
        bag_weight = rand() % 51 + 50;
        bag_destination = rand() % 5;
        bag_delay = rand() % 6;

        printf("Baggage Handler %d is handling a bag weighing %d pounds for destination %s with a delay of %d seconds...\n",
                handler_num, bag_weight, DESTINATIONS[bag_destination], bag_delay);

        // Wait for delay time
        for(int i = 0; i < bag_delay; i++) {
            printf("...");
            fflush(stdout);
            sleep(1);
        }

        printf("\nBag has been loaded onto airplane.\n\n");

        bags_processed++;
        sleep(TIME_INTERVAL);
    }

    printf("All bags have been processed. Simulation complete.\n");

    return 0;
}