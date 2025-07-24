//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL)); // Set random seed based on current time

    int red = 0, yellow = 0, green = 1; // Start with green light on
    int timeToSwitch = 0; // Variable to hold time until light switch

    while (1) { // Infinite loop

        // Print out current light status
        printf("Current Light Status:\n");
        printf("Red: %d\n", red);
        printf("Yellow: %d\n", yellow);
        printf("Green: %d\n\n", green);

        // Calculate a random time until next switch
        timeToSwitch = (rand() % 5) + 2; // Random number between 2-6 seconds

        // Sleep for calculated time
        sleep(timeToSwitch); 

        // Switch lights based on current status
        if (red) {
            red = 0;
            yellow = 1;
            green = 0;
        }
        else if (yellow) {
            red = 1;
            yellow = 0;
            green = 0;
        }
        else if (green) {
            red = 0;
            yellow = 0;
            green = 1;
        }
    }

    return 0;
}