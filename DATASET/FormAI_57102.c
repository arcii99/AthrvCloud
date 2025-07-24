//FormAI DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int temperature;
    int humidity;
    int wind_speed;
    int chance_of_rain;

    // Seed the random number generator 
    srand(time(NULL));

    // Generate random values for temperature, humidity, wind speed, and chance of rain
    temperature = rand() % (100 - 50 +1) + 50;
    humidity = rand() % (100 - 30 + 1) + 30;
    wind_speed = rand() % (50 - 5 + 1) + 5;
    chance_of_rain = rand() % 101;

    // Display the weather forecast
    printf("Today's weather forecast:\n");
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d mph\n", wind_speed);

    // Determine whether or not it will rain
    if (chance_of_rain < 25)
    {
        printf("There is a low chance of rain today.\n");
    }
    else if (chance_of_rain >= 25 && chance_of_rain < 75)
    {
        printf("There is a moderate chance of rain today.\n");
    }
    else
    {
        printf("There is a high chance of rain today.\n");
    }

    return 0;
}