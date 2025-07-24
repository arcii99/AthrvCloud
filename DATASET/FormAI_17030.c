//FormAI DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature;

    srand(time(NULL)); // Initialize random seed

    while(1) // Infinite loop to continuously monitor temperature
    {
        temperature = (float) (rand() % 51 + 150) / 10; // Generate a random temperature between 15.0 to 20.0

        if (temperature > 18.0) // If temperature is greater than 18.0 degrees Celsius
        {
            printf("Temperature is above 18.0C %.1fC\n", temperature);
            printf("Turning on Cooling system...\n");
            // Code to turn on cooling system
        }
        else if (temperature < 16.0) // If temperature is less than 16.0 degrees Celsius
        {
            printf("Temperature is below 16.0C %.1fC\n", temperature);
            printf("Turning on Heating system...\n");
            // Code to turn on heating system
        }
        else // If temperature is between 16.0 to 18.0 degrees Celsius
        {
            printf("Temperature is within safe range %.1fC\n", temperature);
            // Code to maintain temperature within safe range
        }

        sleep(5); // Wait for 5 seconds before checking temperature again
    }

    return 0;
}