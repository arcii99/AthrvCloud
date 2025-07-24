//FormAI DATASET v1.0 Category: Weather simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Set up variables for temperature and precipitation
    int temperature, precipitation;

    // Loop through the next 24 hours
    for (int i = 0; i < 24; i++) {

        // Generate a random temperature between -10 and 50 degrees Celsius
        temperature = rand() % 61 - 10;

        // Generate a random precipitation value between 0 and 100 millimeters
        precipitation = rand() % 101;

        // Display the weather conditions for this hour
        printf("Hour %d: temperature %d C, precipitation %d mm\n", i + 1, temperature, precipitation);

        // Check if the temperature is below freezing and precipitation is above 0
        if (temperature < 0 && precipitation > 0) {

            // Display a warning about potential ice build-up
            printf("Warning: Potential ice build-up on roads and sidewalks!\n");
        }
    }

    // Exit the program
    return 0;
}