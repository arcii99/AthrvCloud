//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message
    printf("Welcome to the Crazy Traffic Light Controller. Let's make things interesting!\n\n");

    // Setting up the initial variables
    char lights[3] = {'R', 'Y', 'G'};
    int current_light = 0;

    // Starting the loop to control the traffic lights
    while(1)
    {
        // Display the current light
        printf("Current Light: %c\n\n", lights[current_light]);

        // Set a random delay before switching the light
        srand(time(NULL));
        int delay = rand() % 10 + 1;
        printf("Waiting for %d seconds...\n\n", delay);
        sleep(delay);

        // Switch to the next light
        current_light++;
        if(current_light > 2)
        {
            current_light = 0;
        }
    }

    // We should never reach here! But just in case...
    return 0;
}