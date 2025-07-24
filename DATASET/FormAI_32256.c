//FormAI DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed random number generator with current time

    int temperature = 65; // Set starting temperature to 65 degrees Fahrenheit
    int humidity = 50; // Set starting humidity to 50%
    int wind_speed = 10; // Set starting wind speed to 10 mph

    printf("Starting weather conditions:\n");
    printf("Temperature: %d degrees Fahrenheit\nHumidity: %d%%\nWind Speed: %d mph\n", temperature, humidity, wind_speed);

    for (int i = 1; i <= 10; i++) // Simulate weather for 10 days
    {
        printf("\nWeather for Day %d:\n", i);

        // Simulate temperature change - pick random number between -5 and 5 degrees Fahrenheit
        int temp_change = rand() % 11 - 5;
        temperature += temp_change;
        printf("Temperature: %d degrees Fahrenheit (%+d)\n", temperature, temp_change);

        // Simulate humidity change - pick random number between -10% and 10%
        int humidity_change = rand() % 21 - 10;
        humidity += humidity_change;
        printf("Humidity: %d%% (%+d%%)\n", humidity, humidity_change);

        // Simulate wind speed change - pick random number between -5 and 5 mph
        int wind_change = rand() % 11 - 5;
        wind_speed += wind_change;
        printf("Wind Speed: %d mph (%+d mph)\n", wind_speed, wind_change);
    }

    return 0;
}