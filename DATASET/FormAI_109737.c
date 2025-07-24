//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    srand(time(NULL));  // initialize the random number generator

    int red_light = 0;   // red light is initially on
    int yellow_light = 0;
    int green_light = 0;
    int count = 0;       // initialize the counter

    while (count < 10)   // loop for 10 cycles
    {
        int wait_time = rand() % 10 + 1;   // generate a random number between 1-10

        if (red_light == 1)   // if red light is on
        {
            printf("RED light ON\n");
            sleep(3);   // wait for 3 seconds
            red_light = 0;
            yellow_light = 1;   // turn on yellow light
        }
        else if (yellow_light == 1)   // if yellow light is on
        {
            printf("YELLOW light ON\n");
            sleep(2);   // wait for 2 seconds
            yellow_light = 0;
            green_light = 1;   // turn on green light
        }
        else if (green_light == 1)   // if green light is on
        {
            printf("GREEN light ON\n");
            sleep(4);   // wait for 4 seconds
            green_light = 0;
            red_light = 1;   // turn on red light
            count++;   // increment the counter
        }

        printf("Waiting for %d seconds...\n", wait_time);
        sleep(wait_time);   // wait for a random time between 1-10 seconds
    }

    printf("Traffic Light Controller simulation complete.\n");

    return 0;
}