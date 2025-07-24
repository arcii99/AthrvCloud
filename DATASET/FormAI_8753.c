//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random float between two values
float random_float(float min, float max) {
    float range = max - min;
    float num = ((float)rand() / RAND_MAX) * range + min;
    return num;
}

int main() {
    // initialization
    srand(time(0));
    float temperature = random_float(20.0, 40.0);
    float humidity = random_float(30.0, 80.0);
    float wind_speed = random_float(0.0, 10.0);
    int weather_code = rand() % 4; // 0 = sunny, 1 = cloudy, 2 = rainy, 3 = snowy

    // print initial weather conditions
    printf("Initial Weather Conditions:\n");
    printf("Temperature: %0.1f °C\n", temperature);
    printf("Humidity: %0.1f %%\n", humidity);
    printf("Wind Speed: %0.1f km/h\n", wind_speed);
    switch (weather_code) {
        case 0:
            printf("Weather: Sunny\n");
            break;
        case 1:
            printf("Weather: Cloudy\n");
            break;
        case 2:
            printf("Weather: Rainy\n");
            break;
        case 3:
            printf("Weather: Snowy\n");
            break;
    }
    printf("\n");

    // simulate weather for the next 24 hours
    printf("Weather Forecast for the Next 24 Hours:\n");
    printf("| Hour | Temperature | Humidity | Wind Speed | Weather |\n");
    for (int hour = 1; hour <= 24; hour++) {
        float temp_change = random_float(-2.0, 2.0);
        float humid_change = random_float(-5.0, 5.0);
        float wind_change = random_float(-2.0, 2.0);

        temperature += temp_change;
        humidity += humid_change;
        wind_speed += wind_change;

        // weather code transitions
        if (weather_code == 0) {
            if (temperature <= 25.0) {
                weather_code = 1;
            } else if (temperature >= 35.0) {
                weather_code = 2;
            }
        } else if (weather_code == 1) {
            if (humidity >= 70.0) {
                weather_code = 2;
            }
        } else if (weather_code == 2) {
            if (temperature >= 35.0) {
                weather_code = 3;
            } else if (humidity <= 40.0) {
                weather_code = 1;
            }
        } else if (weather_code == 3) {
            if (temperature <= 5.0) {
                weather_code = 2;
            }
        }

        // print weather forecast for the hour
        printf("| %d | %0.1f °C | %0.1f %% | %0.1f km/h | ", hour, temperature, humidity, wind_speed);
        switch (weather_code) {
            case 0:
                printf("Sunny |\n");
                break;
            case 1:
                printf("Cloudy |\n");
                break;
            case 2:
                printf("Rainy |\n");
                break;
            case 3:
                printf("Snowy |\n");
                break;
        }
    }

    return 0;
}