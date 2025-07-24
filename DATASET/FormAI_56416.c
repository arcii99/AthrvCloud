//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
/* Traffic Light Controller Program by Shannon */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_TIME 20     // Green light for 20 seconds
#define YELLOW_TIME 5     // Yellow light for 5 seconds
#define RED_TIME 30       // Red light for 30 seconds

int main()
{
    srand(time(NULL));   // Seed random number generator

    int current_light = 0;  // Current traffic light (0 = Green, 1 = Yellow, 2 = Red)
    int countdown = 0;      // Countdown timer for current light

    while (1)   // Loop forever
    {
        // Display current traffic light
        printf("Current Light State: ");
        if (current_light == 0)
            printf("Green\n");
        else if (current_light == 1)
            printf("Yellow\n");
        else
            printf("Red\n");

        // Decrement countdown timer
        if (countdown > 0)
        {
            countdown--;
            continue;
        }

        // Switch to next traffic light
        current_light = (current_light + 1) % 3;

        // Set countdown timer for next light
        if (current_light == 0)   // Green
            countdown = GREEN_TIME;
        else if (current_light == 1)  // Yellow
            countdown = YELLOW_TIME;
        else    // Red
            countdown = RED_TIME + (rand() % RED_TIME);   // Random delay for red light
    }
    return 0;
}