//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int green_time, yellow_time, red_time;
    int time_left;
    srand(time(0));
    green_time = rand() % 61 + 30;
    yellow_time = rand() % 6 + 3;
    red_time = rand() % 76 + 45;
    printf("Green light will last for %d seconds.\n", green_time);
    printf("Yellow light will last for %d seconds.\n", yellow_time);
    printf("Red light will last for %d seconds.\n", red_time);
    time_left = green_time + yellow_time + red_time;
    printf("Total time cycle: %d seconds.\n\nLet's start the traffic light controller...\n\n", time_left);
    
    while (time_left > 0)
    {
        printf("%d seconds remaining...\n", time_left);
        if (time_left <= green_time)
        {
            printf("Green light is on!\n");
        }
        else if (time_left > green_time && time_left <= green_time + yellow_time)
        {
            printf("Yellow light is on!\n");
        }
        else
        {
            printf("Red light is on!\n");
        }
        time_left--;
        sleep(1);
    }
    printf("Traffic light cycle over.");
    return 0;
}