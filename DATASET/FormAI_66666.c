//FormAI DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that returns random float between min and max
float getRandomFloat(float min, float max) {
    return ((float) rand() / RAND_MAX) * (max - min) + min;
}

int main() {
    srand(time(0)); // Seed for random number generation

    float humidity = getRandomFloat(0.0, 100.0);
    float temperature = getRandomFloat(0.0, 50.0);
    float windSpeed = getRandomFloat(0.0, 100.0);

    // Print initial weather conditions
    printf("Today's weather conditions:\n");
    printf("Humidity: %.2f%%\n", humidity);
    printf("Temperature: %.2fC\n", temperature);
    printf("Wind Speed: %.2f m/s\n", windSpeed);

    // Update weather conditions every hour for 24 hours
    for (int hour = 1; hour <= 24; hour++) {
        // Get random values for each weather metric
        float humidityChange = getRandomFloat(-1.0, 1.0);
        float temperatureChange = getRandomFloat(-2.0, 2.0);
        float windSpeedChange = getRandomFloat(-5.0, 5.0);

        // Update weather metrics
        humidity += humidityChange;
        temperature += temperatureChange;
        windSpeed += windSpeedChange;

        // Ensure humidity, temperature, and wind speed stay within acceptable ranges
        if (humidity < 0.0) {
            humidity = 0.0;
        } else if (humidity > 100.0) {
            humidity = 100.0;
        }
        if (temperature < -30.0) {
            temperature = -30.0;
        } else if (temperature > 50.0) {
            temperature = 50.0;
        }
        if (windSpeed < 0.0) {
            windSpeed = 0.0;
        } else if (windSpeed > 200.0) {
            windSpeed = 200.0;
        }

        // Print updated weather conditions
        printf("\nHour %d:\n", hour);
        printf("Humidity: %.2f%%\n", humidity);
        printf("Temperature: %.2fC\n", temperature);
        printf("Wind Speed: %.2f m/s\n", windSpeed);
    }

    printf("\nWeather simulation complete.");

    return 0;
}