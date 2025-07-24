//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP -10 // Minimum temperature that can be simulated
#define MAX_TEMP 40 // Maximum temperature that can be simulated
#define MIN_RAINFALL 0 // Minimum rainfall that can be simulated
#define MAX_RAINFALL 50 // Maximum rainfall that can be simulated
#define MIN_WIND_SPEED 0 // Minimum wind speed that can be simulated
#define MAX_WIND_SPEED 100 // Maximum wind speed that can be simulated
#define MIN_HUMIDITY 0 // Minimum humidity that can be simulated
#define MAX_HUMIDITY 100 // Maximum humidity that can be simulated
#define NUM_DAYS 7 // Number of days to simulate

// Function to generate a random float between min and max
float rand_float(float min, float max) {
    float r = (float) rand() / RAND_MAX;
    return min + r * (max - min);
}

int main() {
    // Initialize random number generator with current time
    srand(time(NULL));
    
    // Initialize arrays to store weather data for each day
    float temperatures[NUM_DAYS];
    float rainfall[NUM_DAYS];
    float wind_speeds[NUM_DAYS];
    float humidities[NUM_DAYS];
    
    // Generate weather data for each day
    for (int i = 0; i < NUM_DAYS; i++) {
        temperatures[i] = rand_float(MIN_TEMP, MAX_TEMP);
        rainfall[i] = rand_float(MIN_RAINFALL, MAX_RAINFALL);
        wind_speeds[i] = rand_float(MIN_WIND_SPEED, MAX_WIND_SPEED);
        humidities[i] = rand_float(MIN_HUMIDITY, MAX_HUMIDITY);
    }
    
    // Print weather data for each day
    printf("Weather simulation for the next %d days:\n", NUM_DAYS);
    for (int i = 0; i < NUM_DAYS; i++) {
        printf("Day %d:\n", i + 1);
        printf("  Temperature: %.1f degrees Celsius\n", temperatures[i]);
        printf("  Rainfall: %.1f mm\n", rainfall[i]);
        printf("  Wind speed: %.1f km/h\n", wind_speeds[i]);
        printf("  Humidity: %.0f%%\n", humidities[i]);
    }
    
    return 0;
}