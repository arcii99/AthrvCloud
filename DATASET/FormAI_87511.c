//FormAI DATASET v1.0 Category: Smart home light control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int light = 0; // initial light setting

    // generate random time
    srand(time(NULL));
    int time = rand() % 24;

    printf("Current time: %d:00 hours\n", time);

    if (time >= 6 && time < 9) // turn on lights during morning hours
    {
        light = 1;
    }
    else if (time >= 18 && time < 21) // turn on lights during evening hours
    {
        light = 1;
    }

    if (light == 1)
    {
        printf("Light is ON\n");
    }
    else
    {
        printf("Light is OFF\n");
    }

    return 0;
}