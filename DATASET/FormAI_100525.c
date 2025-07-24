//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the temperature monitor program!\n");

    // Generate random initial temperature
    srand(time(NULL));
    int temperature = rand() % 101;
    printf("The initial temperature is %d degrees Celsius.\n", temperature);

    // Continuously monitor temperature
    while (1) {
        // Simulate random temperature change
        int change = rand() % 11 - 5; // Generates a number between -5 and +5
        temperature += change;
        printf("The current temperature is %d degrees Celsius.\n", temperature);

        // Check for dangerous temperatures
        if (temperature >= 30) {
            printf("WARNING: Temperature is too high! Cooling systems activated.\n");
        }
        else if (temperature <= 10) {
            printf("WARNING: Temperature is too low! Heating systems activated.\n");
        }

        // Delay for 10 seconds
        printf("Waiting for 10 seconds...\n");
        sleep(10);
    }

    return 0;
}