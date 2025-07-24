//FormAI DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define NUM_READINGS 10

int main() {
    int temperature[NUM_READINGS];
    int i, sum, average;

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Temperature Monitor!\n");

    // Generate random temperature readings and add to array
    for (i = 0; i < NUM_READINGS; i++) {
        temperature[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        printf("Reading %d: %d degrees Celsius\n", i+1, temperature[i]);
    }

    // Calculate average temperature
    sum = 0;
    for (i = 0; i < NUM_READINGS; i++) {
        sum += temperature[i];
    }
    average = sum / NUM_READINGS;

    // Display average temperature
    printf("\nThe average temperature is %d degrees Celsius\n", average);

    return 0;
}