//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_THRESHOLD 25.0   // Threshold temperature
#define TIME_INTERVAL 5        // Sample interval in seconds
#define MAX_SAMPLES 10         // Maximum number of samples

int main(void) {
    srand(time(NULL));        // Seed the random number generator
    float temp = 20.0;        // Starting temperature
    int i = 0;                // Sample counter
    float samples[MAX_SAMPLES]; // Array to hold samples

    // Loop until maximum number of samples have been taken or temperature exceeds threshold
    while (i < MAX_SAMPLES && temp <= TEMP_THRESHOLD) {
        // Sleep for defined interval
        sleep(TIME_INTERVAL);

        // Randomly increase or decrease temperature by a small amount
        temp += (float)(rand() % 10 - 5) / 10.0;

        // Display current temperature
        printf("Sample %d: Temperature is %.1f C\n", i+1, temp);

        // Store sample in array
        samples[i] = temp;

        // Increase sample counter
        i++;
    }

    // Determine if threshold was exceeded
    if (temp > TEMP_THRESHOLD) {
        printf("Threshold temperature of %.1f C was exceeded after %d samples\n", TEMP_THRESHOLD, i);
    } else {
        printf("Maximum number of samples reached\n");
    }

    // Display all samples
    printf("All %d samples:\n", i);
    for (int j = 0; j < i; j++) {
        printf("%.1f ", samples[j]);
    }

    return 0;
}