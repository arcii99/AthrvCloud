//FormAI DATASET v1.0 Category: Weather simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, wind_speed, humidity, is_raining, is_snowing;
    srand(time(0)); // Initializing random number generator

    // Generating random values for temperature, wind_speed, and humidity
    temperature = rand() % 50 - 10; // Temperature range: -10 to 40 degrees Celsius
    wind_speed = rand() % 30; // Wind speed range: 0 to 29 km/h
    humidity = rand() % 100; // Humidity range: 0% to 99%

    // Checking for rain based on humidity
    if (humidity > 50)
    {
        is_raining = 1;
    }
    else
    {
        is_raining = 0;
    }

    // Checking for snow based on temperature and humidity
    if (temperature < 0 && humidity > 80)
    {
        is_snowing = 1;
    }
    else
    {
        is_snowing = 0;
    }

    // Printing weather conditions
    printf("Current temperature: %d C\n", temperature);
    printf("Current wind speed: %d km/h\n", wind_speed);

    if (humidity <= 30)
    {
        printf("Current humidity: Dry\n");
    }
    else if (humidity <= 70)
    {
        printf("Current humidity: Moderate\n");
    }
    else
    {
        printf("Current humidity: Humid\n");
    }

    // Printing precipitation information
    if (is_raining && !is_snowing)
    {
        printf("Precipitation: Rain\n");
    }
    else if (!is_raining && is_snowing)
    {
        printf("Precipitation: Snow\n");
    }
    else if (is_raining && is_snowing)
    {
        printf("Precipitation: Rain and Snow\n");
    }
    else
    {
        printf("Precipitation: None\n");
    }

    return 0;
}