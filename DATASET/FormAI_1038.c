//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int cars_waiting = 0;
    int max_waiting_time = 20;
    int min_green_time = 10;
    int max_green_time = 20;
    int green_time_left = 0;
    int red_time_left = 0;
    int yellow_time_left = 0;
    int current_light = 0;

    srand(time(NULL));

    while (1)
    {
        if (current_light == 0)
        {
            // Red light
            printf("Red Light\n");
            if (cars_waiting > 0)
            {
                // If there are cars waiting, switch to green
                green_time_left = rand() % (max_green_time - min_green_time + 1) + 
                    min_green_time;
                current_light = 1;
                cars_waiting = 0;
                printf("Switching to green in %d seconds\n", green_time_left);
            }
            else
            {
                // If no cars are waiting, continue with red
                red_time_left = rand() % max_waiting_time + 1;
                printf("Waiting at red for %d seconds\n", red_time_left);
            }
        }
        else if (current_light == 1)
        {
            // Green light
            printf("Green Light\n");
            if (green_time_left > 0)
            {
                // If green time left, continue with green
                green_time_left--;
            }
            else
            {
                // If no green time left, switch to yellow
                yellow_time_left = 5;
                current_light = 2;
                printf("Switching to yellow in %d seconds\n", yellow_time_left);
            }
        }
        else if (current_light == 2)
        {
            // Yellow light
            printf("Yellow Light\n");
            if (yellow_time_left > 0)
            {
                // If yellow time left, continue with yellow
                yellow_time_left--;
            }
            else
            {
                // If no yellow time left, switch to red
                current_light = 0;
                printf("Switching to red\n");
            }
        }

        // Randomly generate cars waiting
        if (rand() % 10 == 0)
        {
            printf("Car waiting\n");
            cars_waiting++;
        }

        // Sleep for 1 second
        printf("\n");
        sleep(1);
    }

    return 0;
}