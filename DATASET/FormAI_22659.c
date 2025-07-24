//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // seed random number generator
    srand(time(NULL));

    // generate random temperature between -30 and 50 Celsius
    int temperature = rand() % 81 - 30;

    // generate random humidity between 0 and 100 percent
    int humidity = rand() % 101;

    // generate random wind speed between 0 and 50 km/h
    int windSpeed = rand() % 51;

    // print current weather conditions
    printf("Current weather conditions:\n");
    printf("Temperature: %dC\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d km/h\n", windSpeed);

    // determine weather forecast based on current conditions
    if (temperature >= 25 && humidity >= 50 && windSpeed <= 30) {
        printf("Forecast: hot and humid, with light breezes.\n");
    } else if (temperature >= 0 && temperature < 10) {
        printf("Forecast: cold and cloudy, with a chance of snow.\n");
    } else if (temperature >= 10 && temperature < 25) {
        printf("Forecast: pleasant and sunny, with light winds.\n");
    } else if (temperature < 0) {
        printf("Forecast: bitterly cold, with strong winds and heavy snowfall.\n");
    } else {
        printf("Forecast: mild and cloudy, with moderate winds.\n");
    }

    return 0;
}