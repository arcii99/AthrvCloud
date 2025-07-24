//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RED 'R'
#define GREEN 'G'
#define YELLOW 'Y'

char light1, light2;
int timer = 0;

int main()
{
    srand(time(NULL));
    light1 = GREEN;
    light2 = RED;
    printf("SIMULATION STARTED\n\n");

    while (true) 
    {
        int carDir = rand() % 4 + 1;

        printf("CAR APPROACHING...\n");

        if (light1 == GREEN && carDir == 1)
        {
            printf("Car 1 entered the intersection.\n");

            timer = 0;

            while (timer < 10) 
            {
                printf("Time Elapsed: %d seconds\n", timer);
                timer++;
                sleep(1);

                if (timer == 5)
                    light1 = YELLOW;
            }

            light1 = RED;

            printf("Car 1 exited the intersection.\n");
            printf("Light 1 turned RED.\n");
        }
        else if (light2 == GREEN && carDir == 2)
        {
            printf("Car 2 entered the intersection.\n");

            timer = 0;

            while (timer < 10) 
            {
                printf("Time Elapsed: %d seconds\n", timer);
                timer++;
                sleep(1);

                if (timer == 5)
                    light2 = YELLOW;
            }

            light2 = RED;

            printf("Car 2 exited the intersection.\n");
            printf("Light 2 turned RED.\n");
        }

        if (light1 == RED && light2 == RED) 
        {
            printf("\nSimulation Over.\n");
            break;
        }

        if (light1 == RED) 
        {
            light1 = GREEN;
            light2 = RED;
            printf("\nLight 1 turned GREEN\nLight 2 turned RED\n\n");
        }
        else 
        {
            light2 = GREEN;
            light1 = RED;
            printf("\nLight 2 turned GREEN\nLight 1 turned RED\n\n");
        }
    }

    return 0;
}