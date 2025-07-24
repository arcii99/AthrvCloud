//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int red = 0, yellow = 0, green = 0, timeCounter = 0;
    int previousLight = -1, currentLight = -1;

    srand(time(0)); // Seed the generator with current time

    printf("Starting paranoid traffic light controller...\n\n");

    while(1) { // Endless loop
        // Make sure we are not stuck on the same light for too long
        if (timeCounter > 5 && currentLight == previousLight) {
            printf("ERROR: Stuck on light %d for too long!\n", currentLight);
            printf("Emergency protocol initiated... switching to emergency lights!\n");
            // Switch to emergency lights: Red -> Yellow -> Green -> Yellow -> Red
            currentLight = -1; // Reset current light to trigger a switch
            timeCounter = 0; // Reset time counter
            red = 1; yellow = 0; green = 0; // All cars must stop
        }

        // Check if it's time to switch lights
        if (timeCounter == 0 || timeCounter >= 10) { // Every 10 seconds
            previousLight = currentLight;
            currentLight++;
            if (currentLight > 2) currentLight = 0; // Cycle between 0, 1, 2 (Red, Yellow, Green)
            timeCounter = 0; // Reset time counter
            printf("\nSwitching to light %d...\n", currentLight);
        }

        // Display current status of lights
        printf("[ ");
        if (red) printf("Red ");
        if (yellow) printf("Yellow ");
        if (green) printf("Green ");
        printf("]\n");

        // Simulate cars passing through lights
        switch(currentLight) {
            case 0: // Red light
                red = 1; yellow = 0; green = 0;
                break;
            case 1: // Yellow light
                red = 0; yellow = 1; green = 0;
                break;
            case 2: // Green light
                red = 0; yellow = 0; green = 1;
                break;
        }

        // Sleep between iterations to simulate real time
        int sleepTime = rand() % 3 + 1; // Random number between 1 and 3
        printf("Sleeping for %d seconds...\n\n", sleepTime);
        timeCounter += sleepTime;
        sleep(sleepTime);
    }

    return 0;
}