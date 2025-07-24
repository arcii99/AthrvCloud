//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int temperature = (rand() % 101) - 50; // Generates random temperature between -50 and 50 Celsius
    int humidity = rand() % 101; // Generates random humidity between 0 and 100
    int wind_speed = rand() % 51; // Generates random wind speed between 0 and 50 km/h
    char *wind_directions[] = {"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest"}; // Array of wind directions
    int wind_direction = rand() % 8; // Generates random wind direction index between 0 and 7 corresponding to array

    printf("Current weather conditions:\n");
    printf("Temperature: %d Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Wind direction: %s\n", wind_directions[wind_direction]);

    if (temperature <= 0) {
        printf("It's freezing outside!\n");
    } else if (temperature <= 10) {
        printf("It's very cold outside.\n");
    } else if (temperature <= 20) {
        printf("It's chilly outside.\n");
    } else if (temperature <= 30) {
        printf("It's mild outside.\n");
    } else if (temperature <= 40) {
        printf("It's warm outside.\n");
    } else {
        printf("It's very hot outside!\n");
    }

    if (humidity <= 30) {
        printf("It's very dry outside.\n");
    } else if (humidity <= 60) {
        printf("It's a comfortable level of humidity outside.\n");
    } else {
        printf("It's very humid outside.\n");
    }

    if (wind_speed <= 5) {
        printf("There's only a light breeze.\n");
    } else if (wind_speed <= 20) {
        printf("There's a moderate wind blowing outside.\n");
    } else {
        printf("It's very windy outside!\n");
    }

    return 0;
}