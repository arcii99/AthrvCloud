//FormAI DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 50
#define MIN_TEMP 10

float generateRandomTemp();
float getAverageTemp(float *tempArray, int tempArraySize);
float getMaxTemp(float *tempArray, int tempArraySize);
float getMinTemp(float *tempArray, int tempArraySize);

int main() {
    float tempArray[24]; // Temperature readings for 24 hours
    char location[20]; // Location where temperature is measured
    int i;

    srand(time(NULL)); // Seed random number generator with current time

    printf("Enter the location for temperature reading: ");
    fgets(location, 20, stdin); // Get location input from user

    for (i = 0; i < 24; i++) {
        tempArray[i] = generateRandomTemp(); // Generate random temperature for each hour
    }

    printf("\n\nTemperature report for %s", location);
    printf("\n----------------------------------------\n");

    for (i = 0; i < 24; i++) {
        printf("Hour %d: %.2f°C\n", i+1, tempArray[i]); // Print temperature reading for each hour
    }

    printf("\n\n24-hour average temperature: %.2f°C", getAverageTemp(tempArray, 24));
    printf("\nHighest temperature recorded: %.2f°C", getMaxTemp(tempArray, 24));
    printf("\nLowest temperature recorded: %.2f°C", getMinTemp(tempArray, 24));

    return 0;
}

/**
 * Generates a random temperature between MAX_TEMP and MIN_TEMP
 * @return float
 */
float generateRandomTemp() {
    float temp;
    temp = (float)(rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP);
    return temp;
}

/**
 * Calculates the average of temperature readings
 * @param tempArray float*
 * @param tempArraySize int
 * @return float
 */
float getAverageTemp(float *tempArray, int tempArraySize) {
    float sum = 0.0;
    int i;
    for (i = 0; i < tempArraySize; i++) {
        sum += tempArray[i];
    }
    return sum / tempArraySize;
}

/**
 * Finds the maximum temperature reading from an array
 * @param tempArray float*
 * @param tempArraySize int
 * @return float
 */
float getMaxTemp(float *tempArray, int tempArraySize) {
    int i;
    float max = tempArray[0];
    for (i = 1; i < tempArraySize; i++) {
        if (tempArray[i] > max) {
            max = tempArray[i];
        }
    }
    return max;
}

/**
 * Finds the minimum temperature reading from an array
 * @param tempArray float*
 * @param tempArraySize int
 * @return float
 */
float getMinTemp(float *tempArray, int tempArraySize) {
    int i;
    float min = tempArray[0];
    for (i = 1; i < tempArraySize; i++) {
        if (tempArray[i] < min) {
            min = tempArray[i];
        }
    }
    return min;
}