//FormAI DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature = 25;
    int humidity = 60;
    int pressure = 1013;
    int windSpeed = 10;
    int chanceOfRain = 0;

    srand(time(0)); // Seed the random number generator with the current time
    
    printf("Welcome to the weather simulation!\n\n");

    // Generate random weather conditions for the next 5 days
    for (int day = 1; day <= 5; day++)
    {
        // Generate temperature for current day (between 5 and 40 degrees Celsius)
        temperature = rand() % 36 + 5;
        
        // Generate humidity for current day (between 30 and 90 percent)
        humidity = rand() % 61 + 30;
        
        // Generate pressure for current day (between 950 and 1050 millibars)
        pressure = rand() % 101 + 950;
        
        // Generate wind speed for current day (between 5 and 20 meters per second)
        windSpeed = rand() % 16 + 5;
        
        // Generate chance of rain for current day (between 0 and 100 percent)
        chanceOfRain = rand() % 101;

        printf("Day %d:\n", day);
        printf("Temperature: %d C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Pressure: %d mb\n", pressure);
        printf("Wind speed: %d m/s\n", windSpeed);
        printf("Chance of rain: %d%%\n", chanceOfRain);
        printf("\n");
    }

    return 0;
}