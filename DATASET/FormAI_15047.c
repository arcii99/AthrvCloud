//FormAI DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0.0
#define MAX_TEMP 100.0

// Function to simulate a temperature reading
float readTemperature() {
    float temp;
    temp = MIN_TEMP + (float)rand()/((float)RAND_MAX/(MAX_TEMP-MIN_TEMP));
    return temp;
}

int main() {
    srand(time(NULL));  // Seed random number generator with time

    float currentTemp = readTemperature();
    printf("Current temperature: %.2f degrees Celsius\n", currentTemp);

    int numReadings = 5;
    float tempReadings[numReadings];
    tempReadings[0] = currentTemp;

    for (int i = 1; i < numReadings; i++) {
        float newTemp = readTemperature();
        tempReadings[i] = newTemp;
        printf("Temperature reading %d: %.2f degrees Celsius\n", i, newTemp);
    }

    float totalTemp = 0.0;
    for (int i = 0; i < numReadings; i++) {
        totalTemp += tempReadings[i];
    }
    float averageTemp = totalTemp / numReadings;
    printf("Average temperature: %.2f degrees Celsius\n", averageTemp);

    float maxTemp = MIN_TEMP;
    float minTemp = MAX_TEMP;
    for (int i = 0; i < numReadings; i++) {
        if (tempReadings[i] > maxTemp) {
            maxTemp = tempReadings[i];
        }
        if (tempReadings[i] < minTemp) {
            minTemp = tempReadings[i];
        }
    }
    printf("Maximum temperature: %.2f degrees Celsius\n", maxTemp);
    printf("Minimum temperature: %.2f degrees Celsius\n", minTemp);

    return 0;
}