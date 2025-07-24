//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define GREEN 1

int main()
{
    int state = RED;        // initial state of the traffic light
    int timer = 0;          // timer for counting seconds
    int redTime = 15;       // time for red light
    int greenTime = 10;     // time for green light

    srand(time(NULL));      // seed random generator

    for (int i = 0; i < 50; i++)    // loop for 50 seconds
    {
        printf("Time: %d\n", i);

        if (state == RED)   // current state is RED
        {
            printf("Red Light\n");
            if (timer >= redTime)  // timer has reached redTime
            {
                state = GREEN;      // change state to GREEN
                timer = 0;          // reset timer
            }
            else
            {
                timer++;    // increment timer
            }
        }
        else    // current state is GREEN
        {
            printf("Green Light\n");
            if (timer >= greenTime)  // timer has reached greenTime
            {
                state = RED;        // change state back to RED
                timer = 0;          // reset timer
            }
            else
            {
                timer++;    // increment timer
            }
        }

        // Simulate cars passing through the intersection
        if (rand() % 5 == 0)
        {
            printf("Car passing through!\n");
        }

        printf("\n");
    }

    return 0;
}