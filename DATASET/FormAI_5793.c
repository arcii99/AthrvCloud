//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    srand(time(NULL)); // initializing the random seed

    for(i=0; i<10; i++) // simulating the traffic light for 10 times
    {
        printf("Traffic Light Simulation: %d\n", i+1);
        int r = rand() % 3; // generating a random number between 0 and 2

        // switch statement to determine the traffic light status
        switch (r) {
            case 0:
                printf("The traffic light is red.\n");
                printf("Stop!\n");
                break;
            case 1:
                printf("The traffic light is yellow.\n");
                printf("Slow down.\n");
                break;
            case 2:
                printf("The traffic light is green.\n");
                printf("Go!\n");
                break;
            default:
                printf("Error: invalid traffic light status.\n");
        }
        printf("\n");
    }

    return 0;
}