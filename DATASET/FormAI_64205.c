//FormAI DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50.0
#define MIN_TEMPERATURE -50.0
#define MAX_WIND 150
#define MIN_WIND 0
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

int main(void) {
    srand(time(NULL));
    float temperature, humidity, wind_speed;
    int cloudcover, chance_of_rain;

    printf("Today's Weather Forecast:\n");

    // simulate temperature
    temperature = (float) rand() / RAND_MAX * (MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE;
    printf("Temperature: %.1f C\n", temperature);

    // simulate humidity
    humidity = (float) rand() / RAND_MAX * (MAX_HUMIDITY - MIN_HUMIDITY) + MIN_HUMIDITY;
    printf("Humidity: %.1f%%\n", humidity);

    // simulate wind speed
    wind_speed = (float) rand() / RAND_MAX * (MAX_WIND - MIN_WIND) + MIN_WIND;
    printf("Wind Speed: %.1f km/h\n", wind_speed);

    // simulate cloud cover
    cloudcover = rand() % 101;
    printf("Cloud Cover: %d%%\n", cloudcover);

    // simulate chance of rain
    chance_of_rain = rand() % 101;
    printf("Chance of Rain: %d%%\n", chance_of_rain);

    return 0;
}