//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int greenTime = 10;     // green traffic light time in seconds
    int yellowTime = 3;     // yellow traffic light time in seconds
    int redTime = 15;       // red traffic light time in seconds
    int totalTime = 0;      // total time

    // loop through sequence of traffic lights
    for(int i = 1; i <= 10; i++)
    {
        printf("Sequence %d:\n", i);

        // green light
        printf("Green Light: ON\n");
        for(int j = 1; j <= greenTime; j++)
        {
            printf("%02d seconds\n", j);
            sleep(1);  // pause program for 1 second
            totalTime++;    // increment total time
        }

        // yellow light
        printf("Green Light: OFF\n");
        printf("Yellow Light: ON\n");
        for(int j = 1; j <= yellowTime; j++)
        {
            printf("%02d seconds\n", j);
            sleep(1);  // pause program for 1 second
            totalTime++;    // increment total time
        }

        // red light
        printf("Yellow Light: OFF\n");
        printf("Red Light: ON\n");
        for(int j = 1; j <= redTime; j++)
        {
            printf("%02d seconds\n", j);
            sleep(1);  // pause program for 1 second
            totalTime++;    // increment total time
        }

        // end of sequence
        printf("Red Light: OFF\n");
        printf("End of Sequence %d\n", i);
    }

    // total time
    printf("Total Time: %d seconds\n", totalTime);

    return 0;
}