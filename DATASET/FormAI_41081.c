//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define NUM_OF_MEASUREMENTS 5

float measurements[NUM_OF_MEASUREMENTS];

void takeMeasurements(int measurementNumber);

void printResults(void);

int main(void) {
    printf("C Wi-Fi Signal Strength Analyzer!\n");

    for(int i = 0; i < NUM_OF_MEASUREMENTS; i++)
        takeMeasurements(i);

    printf("\nAnalysis Results:\n");
    printf("=============================\n");
    printResults();

    return 0;
}

void takeMeasurements(int measurementNumber) {
    float signalStrength = 0.0f;
    float totalStrength = 0.0f;
    float averageStrength = 0.0f;
    int num_readings = 10;
    // Simulate taking multiple readings to get an accurate value
    for(int i = 0; i < num_readings; i++) {
        signalStrength = (float)rand() / RAND_MAX * (-100 - 40) + 40; // Generate a random float between -100.0 and -40.0
        totalStrength += signalStrength;
    }
    averageStrength = totalStrength / num_readings;
    measurements[measurementNumber] = averageStrength;
}

void printResults() {
    float minStrength = measurements[0];
    int minIndex = 0;
    float maxStrength = measurements[0];
    int maxIndex = 0;
    float totalStrength = 0.0f;

    for(int i = 0; i < NUM_OF_MEASUREMENTS; i++) {
        totalStrength += measurements[i];
        if(measurements[i] < minStrength) {
            minStrength = measurements[i];
            minIndex = i;
        }
        if(measurements[i] > maxStrength) {
            maxStrength = measurements[i];
            maxIndex = i;
        }
    }

    float averageStrength = totalStrength / NUM_OF_MEASUREMENTS;

    printf("Minimum Signal Strength: %.1f dBm (Measurement #%d)\n", minStrength, minIndex+1);
    printf("Maximum Signal Strength: %.1f dBm (Measurement #%d)\n", maxStrength, maxIndex+1);
    printf("Average Signal Strength: %.1f dBm\n", averageStrength);
}