//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 30 // in Celsius
#define MIN_TEMPERATURE -20 // in Celsius
#define MAX_HUMIDITY 100 // in %
#define MIN_HUMIDITY 0 // in %
#define MAX_WIND_SPEED 100 // in km/h
#define MIN_WIND_SPEED 0 // in km/h

int main() {
    srand(time(NULL)); // initialize random seed

    int temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE; // generate random temperature
    int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY; // generate random humidity
    int windSpeed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED; // generate random wind speed

    printf("Current weather conditions:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d km/h\n", windSpeed);

    return 0;
}