//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed
    int red_time = rand() % 10 + 1; // generate random time for red light between 1-10 seconds
    int green_time = rand() % 20 + 1; // generate random time for green light between 1-20 seconds
    int yellow_time = rand() % 5 + 1; // generate random time for yellow light between 1-5 seconds

    printf("Traffic light sequence:\n");

    while(1) // infinite loop for continuous traffic light sequence
    {
        printf("Red light for %d seconds...\n", red_time);
        sleep(red_time); // pause program for red light duration

        printf("Green light for %d seconds...\n", green_time);
        sleep(green_time); // pause program for green light duration

        printf("Yellow light for %d seconds...\n", yellow_time);
        sleep(yellow_time); // pause program for yellow light duration

        printf("Changing to red light...\n");
    }

    return 0;
}