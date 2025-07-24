//FormAI DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed random number generator
    srand(time(0));

    // Initialize variables
    float precipitation = 0.0;
    float temperature = 0.0;
    float humidity = 0.0;
    float windSpeed = 0.0;
    float windDirection = 0.0;

    // Simulate weather for each hour of the day
    for (int i = 0; i < 24; i++) {
        // Generate random weather data
        precipitation = (float)(rand() % 100) / 10;    // 0.0 - 9.9
        temperature = (float)((rand() % 100) - 50);    // -50 - 49
        humidity = (float)(rand() % 100);              // 0 - 99
        windSpeed = (float)(rand() % 60);              // 0 - 59
        windDirection = (float)(rand() % 360);         // 0 - 359

        // Print out weather information
        printf("Hour %d:\n", i);
        printf("\tPrecipitation: %.1f mm\n", precipitation);
        printf("\tTemperature: %.1f C\n", temperature);
        printf("\tHumidity: %.1f %%\n", humidity);
        printf("\tWind Speed: %.1f km/h\n", windSpeed);
        printf("\tWind Direction: %.1f degrees\n", windDirection);
    }

    return 0;
}