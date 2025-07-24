//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int red, yellow, green;

    srand(time(0)); // Initialize random seed

    while(1) // Loop indefinitely
    {
        // Generate random values for each light
        red = rand() % 10 + 1;
        yellow = rand() % 5 + 1;
        green = rand() % 15 + 1;

        // Display the status of each light
        printf("Red: %d seconds\n", red);
        printf("Yellow: %d seconds\n", yellow);
        printf("Green: %d seconds\n\n", green);

        // Wait for the specified amount of time
        sleep(red);
        sleep(yellow);
        sleep(green);
    }

    return 0;
}