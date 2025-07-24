//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int light, temp;

int main()
{
    printf("Initializing Traffic Light Controller...\n");

    while(1)
    {
        // Red Light
        light = 0;
        printf("Red Light On...\n");

        // Wait for 10 seconds
        for(int i = 10; i >= 1; i--)
        {
            printf("%d...\n", i);
            sleep(1);
        }

        // Yellow Light
        light = 1;
        printf("Yellow Light On...\n");

        // Wait for 2 seconds
        for(int i = 2; i >= 1; i--)
        {
            printf("%d...\n", i);
            sleep(1);
        }

        // Green Light
        light = 2;
        printf("Green Light On...\n");

        // Wait for 15 seconds
        for(int i = 15; i >= 1; i--)
        {
            printf("%d...\n", i);
            sleep(1);
        }

        // Yellow Light
        light = 1;
        printf("Yellow Light On...\n");

        // Wait for 2 seconds
        for(int i = 2; i >= 1; i--)
        {
            printf("%d...\n", i);
            sleep(1);
        }
        
        // Check for temperature
        temp = rand() % 100;
        if(temp > 90)
        {
            printf("Warning: High Temperature Detected! Decreasing Green Time...\n");
            for(int i = 5; i >= 1; i--)
            {
                printf("%d...\n", i);
                sleep(1);
            }
        }

        // Reset to Red Light
        light = 0;
    }

    return 0;
}