//FormAI DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMPERATURE_RANGE 150 // temperature scaling factor
#define HUMIDITY_RANGE 100 // humidity scaling factor

// function to generate random float value with given range
float randomFloat(float min, float max) {
    return ((float)rand() / (float)RAND_MAX) * (max - min) + min;
}

// main function
int main() {
    srand(time(NULL)); // seed the random number generator with time

    // initialize variables
    float temperature = randomFloat(0, TEMPERATURE_RANGE);
    float humidity = randomFloat(0, HUMIDITY_RANGE);

    // print current weather conditions
    printf("Current weather conditions:\n");
    printf("Temperature: %.2f C\n", temperature);
    printf("Humidity: %.2f %%\n", humidity);

    // simulate weather changes every hour for 24 hours
    for (int i = 1; i <= 24; i++) {
        // simulate temperature changes due to time of day
        float temperatureChange = (i < 12) ? randomFloat(-5, 5) : randomFloat(-10, 10);
        temperature += temperatureChange;

        // simulate humidity changes due to temperature and precipitation
        float humidityChange = randomFloat(-10, 10);
        if (temperature < 0) {
            humidityChange += 10;
        } else if (temperature > 30) {
            humidityChange -= 10;
        }
        humidity += humidityChange;

        // limit temperature and humidity within range
        temperature = (temperature < 0) ? 0 : temperature;
        temperature = (temperature > TEMPERATURE_RANGE) ? TEMPERATURE_RANGE : temperature;
        humidity = (humidity < 0) ? 0 : humidity;
        humidity = (humidity > HUMIDITY_RANGE) ? HUMIDITY_RANGE : humidity;

        // print weather conditions after every hour
        printf("\nWeather conditions after %d hour(s):\n", i);
        printf("Temperature: %.2f C\n", temperature);
        printf("Humidity: %.2f %%\n", humidity);
    }

    return 0;
}