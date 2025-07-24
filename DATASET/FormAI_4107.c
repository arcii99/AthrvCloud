//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum capacity of the conveyor belt
#define CONVEYOR_BELT_MAX_CAPACITY 10

// Define the maximum number of bags to be processed
#define MAX_BAGS_TO_BE_PROCESSED 50

int main()
{
    int conveyor_belt[CONVEYOR_BELT_MAX_CAPACITY]; // define the conveyor belt
    int num_bags_processed = 0; // initialize the number of bags processed
    srand(time(NULL)); // seed the random number generator

    // Keep processing bags until we reach the maximum number of bags to be processed
    while (num_bags_processed < MAX_BAGS_TO_BE_PROCESSED)
    {
        // Check if the conveyor belt is full
        if (conveyor_belt[CONVEYOR_BELT_MAX_CAPACITY-1] != 0)
        {
            // If the conveyor belt is full, wait for some time until some space becomes available
            printf("Conveyor belt is full. Waiting for some space...\n");
            sleep(5); // wait for five seconds before checking again
        }
        else
        {
            // If the conveyor belt is not full, add a new bag randomly
            int new_bag = rand() % 100; // generate a random number between 0 and 99
            conveyor_belt[0] = new_bag; // add the new bag to the beginning of the conveyor belt
            printf("New bag added to the conveyor belt: %d\n", new_bag);

            // Shift the bags on the conveyor belt one position to the right
            for (int i = CONVEYOR_BELT_MAX_CAPACITY-1; i > 0; i--)
            {
                conveyor_belt[i] = conveyor_belt[i-1];
            }
            conveyor_belt[0] = 0; // clear the first position on the conveyor belt

            // Increment the number of bags processed
            num_bags_processed++;
        }
    }

    printf("All bags have been processed. Exiting...\n");

    return 0;
}