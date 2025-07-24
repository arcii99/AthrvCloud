//FormAI DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define TEMP_RANGE (MAX_TEMP - MIN_TEMP)

int main() {
    int tempSensor1 = MIN_TEMP, tempSensor2 = MIN_TEMP;
    float runningAverage = 0;

    while (1) {
        // Simulate temperature readings from two sensors
        tempSensor1 += rand() % TEMP_RANGE / 4 - TEMP_RANGE / 8;
        tempSensor2 += rand() % TEMP_RANGE / 4 - TEMP_RANGE / 8;

        // Make sure temperature values are within bounds
        if (tempSensor1 < MIN_TEMP) tempSensor1 = MIN_TEMP;
        if (tempSensor1 > MAX_TEMP) tempSensor1 = MAX_TEMP;
        if (tempSensor2 < MIN_TEMP) tempSensor2 = MIN_TEMP;
        if (tempSensor2 > MAX_TEMP) tempSensor2 = MAX_TEMP;

        // Calculate running average of temperature readings
        runningAverage = (runningAverage * 2 + tempSensor1 + tempSensor2) / 4;

        // Print temperature readings and running average
        printf("Sensor 1: %d\tSensor 2: %d\tRunning Avg: %.2f\n", tempSensor1, tempSensor2, runningAverage);

        // Delay for 1 second
        sleep(1);
    }

    return 0;
}