//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int red_light_time = 10; // in seconds
    int yellow_light_time = 5; // in seconds
    int green_light_time = 15; // in seconds

    int current_time = 0;

    while (current_time <= 300) // 300 seconds is the simulation time
    {
        if (current_time % (red_light_time + yellow_light_time + green_light_time) == 0) // starting from red light
        {
            printf("Red Light");
            sleep(red_light_time);
        }
        else if (current_time % (red_light_time + yellow_light_time + green_light_time) == red_light_time) // switching from red light to green light
        {
            printf("Green Light");
            sleep(green_light_time);
        }
        else if (current_time % (red_light_time + yellow_light_time + green_light_time) == (red_light_time + green_light_time)) // switching from green light to yellow light
        {
            printf("Yellow Light");
            sleep(yellow_light_time);
        }
        current_time++;
    }

    return 0;
}