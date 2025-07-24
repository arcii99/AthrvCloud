//FormAI DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    bool isTempSafe = true;
    int maxTemp = 30; // Maximum temperature setting
    int minTemp = 15; // Minimum temperature setting
    int temp; // Temperature reading

    while (isTempSafe)
    {
        srand(time(NULL)); // Seed random number generator with current time
        temp = rand() % 10 + 15; // Generate random temperature between 15-25 degrees Celsius

        if (temp > maxTemp)
        {
            printf("WARNING: Temperature is too high! Temperature: %d degrees Celsius\n", temp);
            isTempSafe = false;
        }
        else if (temp < minTemp)
        {
            printf("WARNING: Temperature is too low! Temperature: %d degrees Celsius\n", temp);
            isTempSafe = false;
        }
        else
        {
            printf("Temperature is within safe range. Temperature: %d degrees Celsius\n", temp);
        }

        sleep(1); // Wait for 1 second before taking another temperature reading
    }

    return 0;
}