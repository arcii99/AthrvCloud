//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random temperature between -20 and 40
    int temperature = (rand() % 61) - 20;
    
    // Generate a random chance of rain as a percentage
    int chance_of_rain = rand() % 101;

    // Generate a random wind speed between 0 and 50
    int wind_speed = rand() % 51;

    // Generate a random wind direction
    char wind_direction[4];
    char* directions[] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
    strcpy(wind_direction, directions[rand() % 8]);

    // Print out the forecast
    printf("Weather Forecast:\n");
    printf("-----------------\n");
    printf("Temperature: %dC\n", temperature);
    printf("Chance of Rain: %d%%\n", chance_of_rain);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Wind Direction: %s\n", wind_direction);

    return 0;
}