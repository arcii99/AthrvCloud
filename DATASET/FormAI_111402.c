//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50.0
#define MIN_TEMPERATURE -10.0
#define MAX_WIND_SPEED 30.0
#define MIN_WIND_SPEED 0.0

int main() {
    //Declare variables
    double temperature, wind_speed, humidity;
    int month, day;
    time_t t;

    //Seed random number generator
    srand((unsigned) time(&t));

    //Generate and print a random date
    month = rand() % 12 + 1;
    day = rand() % 28 + 1;
    printf("Weather simulation for: %d/%d\n", month, day);

    //Generate and print a random temperature
    temperature = (double)rand() / RAND_MAX * (MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE;
    printf("Temperature: %.1f°C\n", temperature);

    //Generate and print a random wind speed
    wind_speed = (double)rand() / RAND_MAX * (MAX_WIND_SPEED - MIN_WIND_SPEED) + MIN_WIND_SPEED;
    printf("Wind speed: %.1f km/h\n", wind_speed);

    //Generate and print a random humidity
    humidity = (double)rand() / RAND_MAX;
    printf("Humidity: %.1f%%\n", humidity * 100.0);

    //Print weather conditions based on temperature and wind speed
    if (temperature > 25 && wind_speed < 10) {
        printf("Weather conditions: Hot and calm\n");
    } else if (temperature > 25 && wind_speed > 10) {
        printf("Weather conditions: Hot and windy\n");
    } else if (temperature > 0 && temperature <= 25 && wind_speed < 10) {
        printf("Weather conditions: Pleasant and calm\n");
    } else if (temperature > 0 && temperature <= 25 && wind_speed > 10) {
        printf("Weather conditions: Pleasant and windy\n");
    } else if (temperature <= 0 && wind_speed < 10) {
        printf("Weather conditions: Cold and calm\n");
    } else {
        printf("Weather conditions: Cold and windy\n");
    }

    return 0;
}