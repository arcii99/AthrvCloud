//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int ns, ew, i, rand_time;
    time_t t;

    printf("Traffic Light Controller Program\n");

    srand(time(&t));
    rand_time = rand() % 201 + 50; // Random number between 50 and 250

    // Initialize North-South and East-West lights
    ns = 0; // 0 for red, 1 for green
    ew = 1; // 0 for red, 1 for green

    // Loop forever
    while(1)
    {
        // Print current status
        printf("\nCurrent Status:\n");
        printf("North-South Light: %s\n", ns == 0 ? "RED" : "GREEN");
        printf("East-West Light: %s\n", ew == 0 ? "RED" : "GREEN");

        // Change lights based on timer
        if(ns == 1 && ew == 0)
        {
            if(rand_time <= 0)
            {
                ns = 0;
                ew = 1;
                rand_time = rand() % 201 + 50; // Random number between 50 and 250
            }
            else
            {
                rand_time--;
            }
        }
        else if(ns == 0 && ew == 1)
        {
            if(rand_time <= 0)
            {
                ns = 1;
                ew = 0;
                rand_time = rand() % 201 + 50; // Random number between 50 and 250
            }
            else
            {
                rand_time--;
            }
        }

        // Wait for 1 second
        for(i = 0; i < 100000000; i++);
    }

    return 0;
}