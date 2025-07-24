//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to delay program execution
void waitTime(int seconds) {
    clock_t end_wait = seconds + clock();
    while (end_wait > clock());
}

int main() {
    // Initialize variables
    int redTimer = 10;
    int yellowTimer = 3;
    int greenTimer = 10;
    int currentLight = 0;
    int cycleCount = 0;

    // Infinite loop for controlling the traffic light
    while(1) {
        // Print out the current cycle number
        printf("Cycle %d\n", cycleCount);
        cycleCount++;

        // Turn on the red light
        currentLight = 0;
        printf("Red Light On\n");
        waitTime(redTimer);

        // Turn on the yellow light
        currentLight = 1;
        printf("Yellow Light On\n");
        waitTime(yellowTimer);

        // Turn on the green light
        currentLight = 2;
        printf("Green Light On\n");
        waitTime(greenTimer);
    }

    // Exit the program
    return 0;
}