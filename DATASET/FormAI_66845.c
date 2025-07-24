//FormAI DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    // Declare variables to hold sensor data
    bool motionDetected = false;
    bool windowOpen = false;
    bool doorOpen = false;
    int temperature = 0;
    int humidity = 0;

    // Simulate values from sensors
    srand(time(NULL)); // Seed random number generator
    motionDetected = rand() % 2; // Randomly generate 0 or 1
    windowOpen = rand() % 2;
    doorOpen = rand() % 2;
    temperature = rand() % 30 + 10; // Generate temperature between 10 and 40
    humidity = rand() % 50 + 30; // Generate humidity between 30 and 80

    // Print sensor values for testing
    printf("Motion detected: %d\n", motionDetected);
    printf("Window open: %d\n", windowOpen);
    printf("Door open: %d\n", doorOpen);
    printf("Temperature: %d\n", temperature);
    printf("Humidity: %d\n", humidity);

    // Check sensor values and trigger actions accordingly
    if (motionDetected) {
        printf("Motion detected!\n");
        // Turn on the lights
        // ...
    }

    if (windowOpen) {
        printf("Window is open!\n");
        // Close the window
        // ...
    }

    if (doorOpen) {
        printf("Door is open!\n");
        // Send notification to owner's phone
        // ...
    }

    if (temperature > 25) {
        printf("Temperature is too high!\n");
        // Turn on the air conditioning
        // ...
    }

    if (humidity > 60) {
        printf("Humidity is too high!\n");
        // Turn on the dehumidifier
        // ...
    }

    // Program exits
    return 0;
}