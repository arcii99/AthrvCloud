//FormAI DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random temperature between min and max */
double generateTemperature(double min, double max) {
    return (double)rand() / (double)RAND_MAX * (max - min) + min;
}

/* Function to generate a random rainfall between min and max */
double generateRainfall(double min, double max) {
    return (double)rand() / (double)RAND_MAX * (max - min) + min;
}

int main() {
    /* Initialize random seed */
    srand(time(NULL));

    /* Define simulation parameters */
    int days = 7;
    double minTemp = 20.0;
    double maxTemp = 35.0;
    double minRain = 0.0;
    double maxRain = 10.0;

    /* Create arrays to store simulation results */
    double temperatures[days];
    double rainfall[days];

    /* Simulate weather for a week */
    printf("Weather simulation for the next %d days:\n", days);
    for (int i = 0; i < days; i++) {
        double temperature = generateTemperature(minTemp, maxTemp);
        double rain = generateRainfall(minRain, maxRain);
        temperatures[i] = temperature;
        rainfall[i] = rain;

        printf("Day %d - Temperature: %.2fC, Rainfall: %.2fmm\n", i+1, temperature, rain);
    }

    /* Calculate average temperature and rainfall for the week */
    double avgTemp = 0.0;
    double avgRain = 0.0;
    for (int i = 0; i < days; i++) {
        avgTemp += temperatures[i];
        avgRain += rainfall[i];
    }
    avgTemp /= days;
    avgRain /= days;

    printf("\nAverage temperature for the week: %.2fC\n", avgTemp);
    printf("Average rainfall for the week: %.2fmm\n", avgRain);

    return 0;
}