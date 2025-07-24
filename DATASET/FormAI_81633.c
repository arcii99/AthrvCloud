//FormAI DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialise random seed
    srand(time(NULL));

    // Generate random temperature between -10 to 40 degrees Celsius
    int temperature = rand() % 51 - 10;

    // Generate random humidity level between 20 to 80 percent
    int humidity = rand() % 61 + 20;

    // Generate random wind speed between 0 to 50 km/h
    int wind_speed = rand() % 51;

    // Generate random precipitation level between 0 to 20 mm
    int precipitation = rand() % 21;

    // Display weather data
    printf("Today's weather:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Precipitation: %d mm\n", precipitation);

    // Determine weather condition based on temperature and precipitation
    if (temperature <= 0) {
        printf("Condition: Snow\n");
    } else if (temperature < 10 && precipitation > 0) {
        printf("Condition: Sleet\n");
    } else if (temperature < 15 && precipitation > 0) {
        printf("Condition: Light rain\n");
    } else if (temperature < 20 && precipitation > 0) {
        printf("Condition: Moderate rain\n");
    } else if (temperature >= 20 && precipitation > 0) {
        printf("Condition: Heavy rain\n");
    } else if (temperature < 25) {
        printf("Condition: Mostly cloudy\n");
    } else if (temperature < 35) {
        printf("Condition: Partly cloudy\n");
    } else {
        printf("Condition: Sunny\n");
    }

    // Determine weather warning based on humidity and wind speed
    if (humidity >= 80 && wind_speed >= 30) {
        printf("WARNING: Typhoon\n");
    } else if (humidity >= 60 && wind_speed >= 25) {
        printf("WARNING: Hurricane\n");
    } else if (humidity >= 50 && wind_speed >= 20) {
        printf("WARNING: Tornado\n");
    } else if (humidity >= 40 && wind_speed >= 15) {
        printf("WARNING: Thunderstorm\n");
     } else if (humidity >= 30 && wind_speed >= 10) {
        printf("WARNING: Strong wind\n");
    }

    return 0;
}