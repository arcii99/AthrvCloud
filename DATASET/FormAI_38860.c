//FormAI DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(NULL));

    // Define variables and constants
    const int MIN_TEMP = -20;
    const int MAX_TEMP = 40;
    const int MIN_HUMIDITY = 20;
    const int MAX_HUMIDITY = 90;

    int temperature, humidity;
    char weather[20];

    // Generate random weather conditions
    temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;

    // Determine weather conditions based on temperature and humidity
    if (temperature < 0) {
        if (humidity <= 50) {
            sprintf(weather, "Cold and dry");
        } else {
            sprintf(weather, "Cold and humid");
        }
    } else if (temperature >= 0 && temperature < 15) {
        if (humidity <= 50) {
            sprintf(weather, "Cool and dry");
        } else {
            sprintf(weather, "Cool and humid");
        }
    } else if (temperature >= 15 && temperature < 25) {
        if (humidity <= 50) {
            sprintf(weather, "Mild and dry");
        } else {
            sprintf(weather, "Mild and humid");
        }
    } else if (temperature >= 25 && temperature < 35) {
        if (humidity <= 50) {
            sprintf(weather, "Hot and dry");
        } else {
            sprintf(weather, "Hot and humid");
        }
    } else {
        if (humidity <= 50) {
            sprintf(weather, "Very hot and dry");
        } else {
            sprintf(weather, "Very hot and humid");
        }
    }

    // Print weather conditions
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Weather: %s\n", weather);

    return 0;
}