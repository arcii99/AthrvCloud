//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed random generator

    int red = 1;
    int yellow = 0;
    int green = 0;

    while(1)
    {
        int random_num = rand() % 3 + 1; // Generate a random number between 1 and 3

        if (random_num == 1) // RED LIGHT
        {
            if (red == 0) // If the red light is not already on
            {
                printf("RED LIGHT ON\n");
                red = 1;
                yellow = 0;
                green = 0;
            }
        }

        else if (random_num == 2) // YELLOW LIGHT
        {
            if (yellow == 0) // If the yellow light is not already on
            {
                printf("YELLOW LIGHT ON\n");
                red = 0;
                yellow = 1;
                green = 0;
            }
        }

        else if (random_num == 3) // GREEN LIGHT
        {
            if (green == 0) // If the green light is not already on
            {
                printf("GREEN LIGHT ON\n");
                red = 0;
                yellow = 0;
                green = 1;
            }
        }

        else
        {
            printf("INVALID RANDOM NUMBER\n"); // Should never get here, but just in case
        }

        sleep(2); // Pause for 2 seconds before changing the light
    }

    return 0;
}