//FormAI DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define THRESHOLD 50

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize temperature variables
    float current_temp = 0;
    float avg_temp = 0;
    int temp_count = 0;

    // Loop through temperature readings
    for (int i = 0; i < 100; i++) {
        // Simulate temperature reading
        current_temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
        printf("Temperature reading %d: %.1f\n", i+1, current_temp);

        // Add reading to average temperature calculation
        avg_temp += current_temp;
        temp_count++;

        // Check if temperature is above threshold
        if (current_temp > THRESHOLD) {
            printf("***WARNING: Temperature above threshold!***\n");
        }
    }

    // Calculate and print average temperature
    avg_temp /= temp_count;
    printf("\nAverage temperature: %.1f\n", avg_temp);

    return 0;
}