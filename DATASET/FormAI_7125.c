//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initializes random number generator based on current time

    int green = 0, yellow = 1, red = 2; // Assigns a number to each traffic light color
    int currLight = green; // Starting traffic light

    printf("SIMULATING TRAFFIC LIGHT CONTROLLER...\n\n");
    printf("GREEN LIGHT: GO.\n");
    printf("YELLOW LIGHT: CAUTION.\n");
    printf("RED LIGHT: STOP.\n\n");

    while (1) { // Endless loop to simulate continuous operation
        // Output current traffic light color and delay for a random time between 2-4 seconds
        if (currLight == green) {
            printf("CURRENT LIGHT: GREEN.\n\n");
            delay(rand() % 3 + 2);
        }
        else if (currLight == yellow) {
            printf("CURRENT LIGHT: YELLOW.\n\n");
            delay(2);
        }
        else {
            printf("CURRENT LIGHT: RED.\n\n");
            delay(4);
        }

        // Change traffic light color based on current color
        if (currLight == green)
            currLight = yellow;
        else if (currLight == yellow)
            currLight = red;
        else
            currLight = green;
    }

    return 0;
}

// Function to delay program for a number of seconds
void delay(int seconds) {
    int start = time(NULL);
    while (time(NULL) - start < seconds)
        ;
}