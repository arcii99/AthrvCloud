//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INTERVAL 5000 // interval for changing lights

int main()
{
    srand(time(NULL));
    int green_time = rand() % 10 + 10; // random green time from 10-19 seconds
    int yellow_time = rand() % 3 + 2; // random yellow time from 2-4 seconds
    int red_time = 30 - green_time - yellow_time; // red time is the remaining time

    int paranoid_mode = 1;

    while (1)
    {
        if (paranoid_mode)
        {
            printf("PARANOID MODE ACTIVATED! ALL LIGHTS FLASHING!\n");
            usleep(INTERVAL); // sleep for interval microseconds
        }
        else
        {
            printf("\033[0;32mGREEN\033[0m LIGHT: %d seconds left\n", green_time);
            printf("\033[0;33mYELLOW\033[0m LIGHT: %d seconds left\n", yellow_time);
            printf("\033[0;31mRED\033[0m LIGHT: %d seconds left\n", red_time);
            usleep(INTERVAL); // sleep for interval microseconds
        }

        // decrement green time each interval
        green_time -= INTERVAL / 1000000;
        if (green_time <= 0)
        {
            green_time = 0;
            printf("\a"); // beep when light changes
        }

        // decrement yellow time each interval after green time is finished
        if (green_time == 0)
        {
            yellow_time -= INTERVAL / 1000000;
            if (yellow_time <= 0)
            {
                yellow_time = 0;
                printf("\a"); // beep when light changes
            }
        }

        // decrement red time each interval after yellow time is finished and reset green time
        if (yellow_time == 0)
        {
            red_time -= INTERVAL / 1000000;
            if (red_time <= 0)
            {
                red_time = 0;
                printf("\a"); // beep when light changes
                green_time = rand() % 10 + 10;
                yellow_time = rand() % 3 + 2;
                red_time = 30 - green_time - yellow_time;
            }
        }

        // toggle paranoid mode when green time is <= 5 seconds
        if (green_time <= 5 && paranoid_mode)
        {
            printf("PARANOID MODE DEACTIVATED! BACK TO NORMAL OPERATION!\n");
            paranoid_mode = 0;
        }
        else if (green_time > 5 && !paranoid_mode)
        {
            printf("PARANOID MODE ACTIVATED! ALL LIGHTS FLASHING!\n");
            paranoid_mode = 1;
        }
    }

    return 0;
}