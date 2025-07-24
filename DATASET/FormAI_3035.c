//FormAI DATASET v1.0 Category: Weather simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random temperature between 50 and 90 degrees Fahrenheit
    int temperature = rand() % 41 + 50;

    // Generate a random humidity between 30% and 70%
    int humidity = rand() % 41 + 30;

    // Generate a random barometric pressure between 28.5 and 30.5 inches of mercury
    float pressure = (float)(rand() % 201 + 285) / 10;

    // Generate a random wind speed between 0 and 20 miles per hour
    int wind_speed = rand() % 21;

    // Generate a random wind direction in degrees
    int wind_direction = rand() % 361;

    // Calculate the dew point
    float dew_point = temperature - (100 - humidity) / 5;

    // Calculate the heat index
    float heat_index = -42.379 + 2.04901523 * temperature + 10.14333127 * humidity - 0.22475541 * temperature * humidity - 0.00683783 * temperature * temperature - 0.05481717 * humidity * humidity + 0.00122874 * temperature * temperature * humidity + 0.00085282 * temperature * humidity * humidity - 0.00000199 * temperature * temperature * humidity * humidity;

    // Calculate the wind chill factor
    float wind_chill = 35.74 + 0.6215 * temperature - 35.75 * pow(wind_speed, 0.16) + 0.4275 * temperature * pow(wind_speed, 0.16);

    printf("Today's weather:\n");
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Barometric Pressure: %0.2f inches of mercury\n", pressure);
    printf("Wind Speed: %d mph\n", wind_speed);
    printf("Wind Direction: %d degrees\n", wind_direction);
    printf("Dew Point: %0.2f degrees Fahrenheit\n", dew_point);
    printf("Heat Index: %0.2f degrees Fahrenheit\n", heat_index);
    printf("Wind Chill: %0.2f degrees Fahrenheit\n", wind_chill);

    return 0;
}