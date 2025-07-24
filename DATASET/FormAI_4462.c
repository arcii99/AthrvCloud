//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int red = 0;
    int yellow = 0;
    int green = 1;

    // Seed random generator
    srand(time(NULL));

    // Loop indefinitely
    while (1) {
        // Display current state of traffic light
        printf("Red: %d\tYellow: %d\tGreen: %d\n", red, yellow, green);

        // Wait for random amount of time between 1 and 5 seconds
        int wait_time = rand() % 5 + 1;
        printf("Waiting for %d seconds...\n", wait_time);
        sleep(wait_time);

        // Change lights based on current state
        if (red) {
            red = 0;
            yellow = 1;
            green = 0;
        } else if (yellow) {
            red = 0;
            yellow = 0;
            green = 1;
        } else if (green) {
            red = 1;
            yellow = 0;
            green = 0;
        }
    }

    return 0;
}