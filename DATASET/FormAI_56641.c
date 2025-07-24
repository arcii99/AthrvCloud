//FormAI DATASET v1.0 Category: Temperature monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variables to store current temperature and threshold temperature
float current_temp = 25.0;
float threshold_temp = 30.0;

// Function to check if temperature exceeds threshold
bool isOverheating(float temp) {
    if (temp > threshold_temp) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Loop to continually monitor temperature
    while (true) {
        // Simulating temperature readings at random intervals
        int time_delay = rand() % 6; // Random time delay between 0 and 5 seconds
        sleep(time_delay);

        // Simulating temperature readings fluctuating +/- 2 degrees Celsius
        float temperature_change = ((float) rand() / RAND_MAX) * 4 - 2;
        current_temp += temperature_change;

        // Printing current temperature
        printf("Current temperature: %.2f degrees Celsius\n", current_temp);

        // Checking if temperature exceeds threshold
        if (isOverheating(current_temp)) {
            printf("WARNING: Temperature has exceeded threshold of %.2f degrees Celsius!\n", threshold_temp);
            // TODO: Implement warning system (e.g. sound alarm, send notification)
        }
    }
    return 0;
}