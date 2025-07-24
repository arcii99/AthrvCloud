//FormAI DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the seed for random number generation
    srand(time(NULL));

    // Generate a random temperature in degrees Celsius between -10 and 40
    int temperature = (rand() % 51) - 10;

    // Generate a random humidity percentage between 30 and 90
    int humidity = (rand() % 61) + 30;

    // Determine the weather condition based on temperature and humidity
    char* weather;
    if (temperature < 0) {
        weather = "Snow";
    } else if (temperature < 15) {
        if (humidity < 50) {
            weather = "Clear skies";
        } else if (humidity < 80) {
            weather = "Scattered clouds";
        } else {
            weather = "Overcast skies";
        }
    } else if (temperature < 25) {
        if (humidity < 70) {
            weather = "Sunny day";
        } else {
            weather = "Partly cloudy";
        }
    } else {
        if (humidity < 50) {
            weather = "Heat wave";
        } else if (humidity < 80) {
            weather = "Hazy";
        } else {
            weather = "Thunderstorm";
        }
    }

    // Display the weather information
    printf("Temperature: %dC, Humidity: %d%%, Weather Condition: %s\n", temperature, humidity, weather);

    return 0;
}