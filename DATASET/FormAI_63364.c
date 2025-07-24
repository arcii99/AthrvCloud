//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Traffic light controller\n");

    // initialize variables
    int red_time = 10; // in seconds
    int yellow_time = 3; // in seconds
    int green_time = 15; // in seconds
    int total_time = red_time + yellow_time + green_time;
    time_t start_time = time(NULL);

    while (1)
    {
        int elapsed_time = time(NULL) - start_time;

        // red light
        if (elapsed_time % total_time < red_time)
        {
            printf("RED\n");
        }
        // yellow light
        else if (elapsed_time % total_time < red_time + yellow_time)
        {
            printf("YELLOW\n");
        }
        // green light
        else
        {
            printf("GREEN\n");
        }

        // wait for one second
        sleep(1);
    }

    return 0;
}