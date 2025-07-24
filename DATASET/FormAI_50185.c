//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40.0 // Maximum temperature threshold
#define MIN_TEMP 20.0 // Minimum temperature threshold

// Function to generate random temperature
float generateTemperature() {
    float temperature = (float)(rand() % 200) / 10.0 - 10.0; // Random float value between -10.0 and 10.0
    return temperature;
}

// Function to convert temperature to Celsius
float convertToCelsius(float temperature) {
    return (temperature - 32) * 5 / 9;
}

// Function to check if temperature is within the threshold
int checkTemperature(float temperature) {
    if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
        return 0; // Temperature is not within the threshold
    } else {
        return 1; // Temperature is within the threshold
    }
}

int main() {
    srand(time(NULL)); // Seed for random generation
    
    printf("C Temperature Monitor\n\n");

    float temperature;
    int isWithinThreshold;

    // Loop to continuously generate and monitor temperature
    while (1) {
        temperature = generateTemperature();
        isWithinThreshold = checkTemperature(temperature);

        if (isWithinThreshold) {
            printf("Temperature: %.1fC\n", convertToCelsius(temperature));
        } else {
            printf("WARNING: Temperature: %.1fC is outside the threshold range of %.1fC to %.1fC\n", convertToCelsius(temperature), convertToCelsius(MIN_TEMP), convertToCelsius(MAX_TEMP));
        }
    }

    return 0;
}