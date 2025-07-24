//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define traffic light colors
typedef enum {RED, YELLOW, GREEN} TrafficColor;

// Define traffic light states
typedef enum {NS_GO, NS_STOP, EW_GO, EW_STOP,} TrafficState;

int main() {
    TrafficColor nsColor, ewColor;
    TrafficState nsState, ewState;
    int nsTimer, ewTimer;

    // Initialize random seed for traffic light times
    srand(time(NULL));

    // Set initial traffic light states and times
    nsColor = RED;
    ewColor = GREEN;
    nsState = NS_STOP;
    ewState = EW_GO;
    nsTimer = rand() % 10 + 10;
    ewTimer = rand() % 10 + 10;

    // Loop through traffic light cycles infinitely
    while(1) {
        // Output current traffic light colors and states
        printf("NS: %d - %d, EW: %d - %d\n", nsColor, nsState, ewColor, ewState);

        // Decrease timer for current traffic light state
        if (nsState == NS_GO) {
            nsTimer--;
        } else if (ewState == EW_GO) {
            ewTimer--;
        }

        // Check if timer for current traffic light state has hit zero
        if (nsTimer == 0 && nsState == NS_GO) {
            nsState = NS_STOP;
            nsColor = YELLOW;
            ewState = EW_GO;
            ewColor = GREEN;
            nsTimer = rand() % 10 + 10;
        } else if (ewTimer == 0 && ewState == EW_GO) {
            ewState = EW_STOP;
            ewColor = YELLOW;
            nsState = NS_GO;
            nsColor = GREEN;
            ewTimer = rand() % 10 + 10;
        }

        // Sleep for one second to simulate real-time traffic light changes
        sleep(1);
    }

    // Exit program
    return 0;
}