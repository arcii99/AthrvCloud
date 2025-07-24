//FormAI DATASET v1.0 Category: Weather simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// FUNCTION TO RETURN RANDOM TEMPERATURE
int getTemperature(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// MAIN FUNCTION
int main() {

    // INITIALIZING VARIABLES
    int temperature[24], i, mean, max_temperature, min_temperature;

    // GENERATE SEED FOR RANDOM FUNCTION
    srand(time(NULL));

    // GENERATING 24-HOUR TEMPERATURES
    for (i = 0; i < 24; i++) {
        temperature[i] = getTemperature(20, 35);
        printf("\nHour %d temperature: %dC", i+1, temperature[i]);
    }

    // MEAN TEMPERATURE CALCULATION
    mean = 0;
    for (i = 0; i < 24; i++) {
        mean += temperature[i];
    }
    mean /= 24;

    // MAXIMUM TEMPERATURE CALCULATION
    max_temperature = temperature[0];
    for (i = 1; i < 24; i++) {
        if (temperature[i] > max_temperature) {
            max_temperature = temperature[i];
        }
    }

    // MINIMUM TEMPERATURE CALCULATION
    min_temperature = temperature[0];
    for (i = 1; i < 24; i++) {
        if (temperature[i] < min_temperature) {
            min_temperature = temperature[i];
        }
    }

    // OUTPUT MAXIMUM, MINIMUM, MEAN TEMPERATURES
    printf("\n\nMaximum temperature for the day: %dC", max_temperature);
    printf("\nMinimum temperature for the day: %dC", min_temperature);
    printf("\nAverage temperature for the day: %dC", mean);

    return 0;
}