//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Define state machine states
#define STATE_GREEN 0
#define STATE_YELLOW 1
#define STATE_RED 2

// Define duration of each state
#define GREEN_TIME 5 // in seconds
#define YELLOW_TIME 2 // in seconds
#define RED_TIME 5 // in seconds

// Define state machine variables
int currentState = STATE_RED; // start in the red state
int nextState = STATE_GREEN; // next state is always green
time_t stateStartTime = 0; // start time of current state

// Define function to get current time in seconds
int getTime() {
    return (int)time(NULL);
}

int main() {
    while (true) {
        int elapsedTime = getTime() - stateStartTime;

        // Check if we need to transition to next state
        if (elapsedTime >= GREEN_TIME && currentState == STATE_GREEN) {
            nextState = STATE_YELLOW;
        } else if (elapsedTime >= YELLOW_TIME && currentState == STATE_YELLOW) {
            nextState = STATE_RED;
        } else if (elapsedTime >= RED_TIME && currentState == STATE_RED) {
            nextState = STATE_GREEN;
        }

        // Check if we need to transition to next state
        if (nextState != currentState) {
            // Update current state and start time
            currentState = nextState;
            stateStartTime = getTime();

            // Output the state
            if (currentState == STATE_GREEN) {
                printf("Traffic light is green.\n");
            } else if (currentState == STATE_YELLOW) {
                printf("Traffic light is yellow.\n");
            } else if (currentState == STATE_RED) {
                printf("Traffic light is red.\n");
            }
        }
    }

    return 0;
}