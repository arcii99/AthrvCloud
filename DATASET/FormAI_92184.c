//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int time_elapsed = 0;
    int green_light = 20;
    bool car_arrive = false;
    bool pedestrian_press = false;

    while (true)
    {
        /* Car arrives every 30 seconds */
        if (time_elapsed % 30 == 0)
        {
            car_arrive = true;
        }

        /* Pedestrian presses button every 60 seconds */
        if (time_elapsed % 60 == 0)
        {
            pedestrian_press = true;
        }

        if (green_light > 0)
        {
            printf("Green light: %d\n", green_light);
            green_light--;
        }
        else
        {
            printf("Red light: %d\n", 30 - time_elapsed);
        }

        if (car_arrive && green_light < 10)
        {
            printf("Car waiting\n");
        }

        if (pedestrian_press && green_light < 15)
        {
            printf("Pedestrian waiting\n");
        }

        if (time_elapsed == 30)
        {
            green_light = 20;
        }

        if (time_elapsed == 60)
        {
            pedestrian_press = false;
            time_elapsed = 0;
        }

        car_arrive = false;

        /* Delay for one second */
        system("sleep 1");

        /* Increment time elapsed */
        time_elapsed++;
    }

    return 0;
}