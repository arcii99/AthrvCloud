//FormAI DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>  // For standard input and output functions
#include <time.h>   // For time functions
#include <stdlib.h> // For random number generator function

int main() {

    int currentTemp;    // Current temperature value
    int lowTemp = 0;    // Starting low temperature value
    int highTemp = 100; // Starting high temperature value

    srand(time(NULL));  // Initialize random number generator with current time value

    printf("Starting temperature monitor...\n\n");

    while(1) {

        // Generate random temperature value between 0 and 100
        currentTemp = rand() % 101;

        // Print current temperature value
        printf("Current temperature: %d C\n", currentTemp);

        // Check for low temperature alert
        if(currentTemp < lowTemp) {
            printf("ALERT: Low temperature detected!\n");
            lowTemp = currentTemp; // Set new low temperature value
        }

        // Check for high temperature alert
        if(currentTemp > highTemp) {
            printf("ALERT: High temperature detected!\n");
            highTemp = currentTemp; // Set new high temperature value
        }

        // Wait for 5 seconds before checking temperature again
        printf("\n");
        sleep(5);

    }

    return 0;
}