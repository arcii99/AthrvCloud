//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature;

    // Seed random number generator with current time
    srand(time(NULL));

    // Generate random initial temperature
    temperature = (float)(rand() % 40);

    // Print initial temperature
    printf("Initial temperature: %.2f degrees Celsius\n", temperature);

    // Loop through 10 iterations
    for (int i = 0; i < 10; i++)
    {
        // Generate random change in temperature
        float change = (float)(rand() % 10 - 5) / 10;

        // Update temperature
        temperature += change;

        // Print out change in temperature
        if (change > 0)
        {
            printf("Temperature increased by %.2f degrees Celsius\n", change);
        }
        else if (change < 0)
        {
            printf("Temperature decreased by %.2f degrees Celsius\n", -change);
        }
        else
        {
            printf("Temperature did not change\n");
        }

        // Print out current temperature
        printf("Current temperature: %.2f degrees Celsius\n", temperature);
    }

    return 0;
}