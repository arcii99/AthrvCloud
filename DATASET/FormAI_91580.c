//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main()
{
    int current_light = RED;
    int seconds_left = 10;
    time_t start_time, current_time;

    time(&start_time);

    while (true)
    {
        time(&current_time);

        if (current_time - start_time >= seconds_left)
        {
            switch (current_light)
            {
            case RED:
                printf("The light is now green.\n");
                current_light = GREEN;
                seconds_left = 20;
                break;
            case GREEN:
                printf("The light is now yellow.\n");
                current_light = YELLOW;
                seconds_left = 5;
                break;
            case YELLOW:
                printf("The light is now red.\n");
                current_light = RED;
                seconds_left = 10;
                break;
            }

            time(&start_time);
        }
    }

    return 0;
}