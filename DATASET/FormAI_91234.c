//FormAI DATASET v1.0 Category: Weather simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int day = 1;    // Day counter
    double temperature = 25;    // Starting temperature in Celsius
    double humidity = 0.7;    // Starting humidity
    double pressure = 1013;    // Starting pressure in hPa
    double rainfall = 0;    // Starting rainfall in mm
    int weatherCondition = 2;    // Starting weather condition (2 = sunny)

    srand(time(NULL));    // Seed random number generator with current time

    printf("Welcome to C Weather Simulator!\n");
    printf("Starting weather conditions: \n");
    printf("Temperature: %.1f C\n", temperature);
    printf("Humidity: %.2f\n", humidity);
    printf("Pressure: %.0f hPa\n", pressure);
    printf("Rainfall: %.1f mm\n", rainfall);

    while (day <= 7) {    // Simulate 7 days
        printf("\nDay %d:\n", day);

        // Change weather conditions randomly
        int randNum = rand() % 4;    // Generate random number between 0 and 3
        if (randNum == 0) {    // 25% chance of rainfall
            weatherCondition = 1;
            rainfall = (rand() % 10) + 1;    // Generate random rainfall between 1-10 mm
            printf("It will rain today! Rainfall expected: %.1f mm.\n", rainfall);
        } else if (randNum == 1) {    // 25% chance of cloudy weather
            weatherCondition = 0;
            printf("It will be cloudy today.\n");
        } else if (randNum == 2) {    // 25% chance of hazy weather
            weatherCondition = 3;
            printf("It will be hazy today.\n");
        } else {    // 25% chance of sunny weather
            weatherCondition = 2;
            printf("It will be sunny today.\n");
        }

        // Update temperature, humidity, and pressure based on weather conditions
        if (weatherCondition == 0) {    // Cloudy
            temperature -= 1;
            humidity += 0.1;
            pressure -= 5;
        } else if (weatherCondition == 1) {    // Rainy
            temperature -= 2;
            humidity += 0.2;
            pressure -= 10;
        } else if (weatherCondition == 2) {    // Sunny
            temperature += 1;
            humidity -= 0.1;
            pressure += 5;
        } else {    // Hazy
            temperature -= 0.5;
            humidity += 0.05;
            pressure -= 2;
        }

        // Print updated weather conditions
        if (temperature < 0) {
            printf("Temperature: %.1f C (Freezing!)\n", temperature);
        } else {
            printf("Temperature: %.1f C\n", temperature);
        }
        printf("Humidity: %.2f\n", humidity);
        printf("Pressure: %.0f hPa\n", pressure);
        printf("Rainfall: %.1f mm\n", rainfall);

        day++;    // Increment day counter
    }

    printf("\nThanks for using C Weather Simulator!");
    return 0;
}