//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn on a light
void turnOnLight(int lightNumber) {
    printf("Turning on light %d\n", lightNumber);
}

// Function to turn off a light
void turnOffLight(int lightNumber) {
    printf("Turning off light %d\n", lightNumber);
}

int main() {
    int lightCount = 3;
    bool isHomeMode = true;
    bool isNightMode = true;

    // Enter main loop
    while (true) {
        // Check if anyone is home
        bool isAnyoneHome = true;

        // Set lights based on home mode and night mode
        if (isHomeMode && isNightMode) {
            // Turn on some lights
            turnOnLight(1);
            turnOnLight(2);
        }
        else if (isHomeMode && !isNightMode) {
            // Turn on all lights
            for (int i=1; i<=lightCount; i++) {
                turnOnLight(i);
            }
        }
        else {
            // Turn off all lights
            for (int i=1; i<=lightCount; i++) {
                turnOffLight(i);
            }
        }

        // Check if someone enters the room
        if (!isAnyoneHome) {
            // Turn on all lights
            for (int i=1; i<=lightCount; i++) {
                turnOnLight(i);
            }
        }

        // Wait for 10 seconds before looping again
        sleep(10);
    }

    return 0;
}