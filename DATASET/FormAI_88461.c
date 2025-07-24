//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10
#define MAX_WIND_SPEED 120
#define MAX_PRECIPITATION 50

// Function to generate a random value between min and max
int randInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate the weather for a given day
void simulateWeather(int day) {
    // Generate random values for temperature, wind speed, and precipitation
    int temperature = randInRange(MIN_TEMPERATURE, MAX_TEMPERATURE);
    int windSpeed = randInRange(0, MAX_WIND_SPEED);
    int precipitation = randInRange(0, MAX_PRECIPITATION);

    // Print the simulation results
    printf("Day %d:\n", day);
    printf(" Temperature: %dC\n", temperature);
    printf(" Wind Speed: %dkm/h\n", windSpeed);
    printf(" Precipitation: %d%%\n\n", precipitation);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Simulate the weather for the next 7 days
    for (int day = 1; day <= 7; day++) {
        simulateWeather(day);
    }

    return 0;
}