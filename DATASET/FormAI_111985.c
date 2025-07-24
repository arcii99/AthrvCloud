//FormAI DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>

int main(void)
{
    int temperature = 25; // initial temperature
    int lowerLimit = 15; // lower temperature limit
    int upperLimit = 30; // upper temperature limit

    printf("Welcome to the Retro Temperature Monitor\n\n");

    // main loop to simulate temperature change
    while(1)
    {
        printf("Current temperature: %d\n", temperature);

        // check if temperature is within limits
        if (temperature < lowerLimit)
        {
            printf("Temperature is too low! Increasing by 1 degree\n");
            temperature++;
        }
        else if (temperature > upperLimit)
        {
            printf("Temperature is too high! Decreasing by 1 degree\n");
            temperature--;
        }
        else
        {
            printf("Temperature is within acceptable range\n");
        }

        printf("\n");

        // wait for 1 second before checking again
        sleep(1);
    }

    return 0;
}