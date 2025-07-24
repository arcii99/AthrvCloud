//FormAI DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_READINGS 10

int main() {
    float readings[NUM_READINGS];
    float total_reading = 0.0;
    int i;

    printf("Starting temperature monitor...\n");

    // Main loop
    for (i = 0; i < NUM_READINGS; i++) {
        // Generate a random temperature reading
        float reading = ((float) rand() / (float) RAND_MAX) * 100;
        printf("Reading %d: %.2f\n", i + 1, reading);

        // Add it to the total
        total_reading += reading;

        // Store the reading in the array
        readings[i] = reading;

        // Sleep for 1 second
        // Using synchronous style with sleep to demonstrate blocking behavior
        sleep(1);
    }

    // Calculate the average temperature
    float average_reading = total_reading / NUM_READINGS;
    printf("\nAverage reading: %.2f\n", average_reading);

    // Print any readings that are above the average
    printf("\nReadings above average:\n");
    for (i = 0; i < NUM_READINGS; i++) {
        if (readings[i] > average_reading) {
            printf("Reading %d: %.2f\n", i + 1, readings[i]);
        }
    }

    printf("\nTemperature monitor complete.");

    return 0;
}