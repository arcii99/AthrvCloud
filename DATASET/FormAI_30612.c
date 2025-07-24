//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define traffic light states
#define RED 1
#define YELLOW 2
#define GREEN 3

int main()
{
    srand(time(NULL)); // Set random seed
    int lightState = RED; // Initialize traffic light to red

    // Loop through 50 cycles of traffic flow simulation
    for(int i = 0; i < 50; i++)
    {
        // Check traffic light state and adjust accordingly
        if(lightState == RED)
        {
            printf("Cars stop at the red light.\n");
            lightState = GREEN;
        }
        else if(lightState == GREEN)
        {
            printf("Cars move forward on the green light.\n");
            lightState = YELLOW;
        }
        else if(lightState == YELLOW)
        {
            printf("Cars slow down on the yellow light.\n");

            // Randomly decide whether to keep the light yellow or switch to red
            int decision = rand() % 2;
            if(decision == 0)
            {
                printf("Traffic light turns red.\n");
                lightState = RED;
            }
            else
            {
                printf("Traffic light remains yellow.\n");
                lightState = GREEN;
            }
        }

        // Add surreal element: sometimes a giant octopus appears on the road
        int octopus = rand() % 10;
        if(octopus == 0)
        {
            printf("A giant octopus appears on the road and blocks traffic!\n");
        }

        printf("\n"); // Add space between cycles for readability
    }

    return 0;
}