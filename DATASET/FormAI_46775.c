//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the state constants
#define STATE_RED 0
#define STATE_YELLOW 1
#define STATE_GREEN 2

// Define the state time intervals in seconds
#define RED_TIME 10
#define YELLOW_TIME 3
#define GREEN_TIME 15

// Define the transition constants
#define TRANSITION_RED_TO_GREEN 0
#define TRANSITION_GREEN_TO_YELLOW 1
#define TRANSITION_YELLOW_TO_RED 2

// Define the transition time intervals in seconds
#define TRANSITION_TIME 1

// Define the initial state to be RED
int currentState = STATE_RED;

// Define the initial state time remaining
int currentTimeRemaining = RED_TIME;

// Define the transition time remaining
int currentTransitionTimeRemaining = 0;

// Define the function to switch the state
void switchState(int newState) {
    currentState = newState;
    currentTransitionTimeRemaining = TRANSITION_TIME;
}

int main() {
    while (1) {
        // Print the current state
        switch (currentState) {
            case STATE_RED:
                printf("RED\n");
                break;
            case STATE_YELLOW:
                printf("YELLOW\n");
                break;
            case STATE_GREEN:
                printf("GREEN\n");
                break;
        }
        
        // Decrement the current time remaining
        currentTimeRemaining--;
        
        // Check for state transition
        if (currentTimeRemaining == 0) {
            switch (currentState) {
                case STATE_RED:
                    switchState(TRANSITION_RED_TO_GREEN);
                    currentTimeRemaining = GREEN_TIME;
                    break;
                case STATE_YELLOW:
                    switchState(TRANSITION_YELLOW_TO_RED);
                    currentTimeRemaining = RED_TIME;
                    break;
                case STATE_GREEN:
                    switchState(TRANSITION_GREEN_TO_YELLOW);
                    currentTimeRemaining = YELLOW_TIME;
                    break;
            }
        }
        
        // Check for transition time remaining
        if (currentTransitionTimeRemaining > 0) {
            currentTransitionTimeRemaining--;
            if (currentTransitionTimeRemaining == 0) {
                switch (currentState) {
                    case TRANSITION_RED_TO_GREEN:
                        currentState = STATE_GREEN;
                        currentTimeRemaining = GREEN_TIME;
                        break;
                    case TRANSITION_GREEN_TO_YELLOW:
                        currentState = STATE_YELLOW;
                        currentTimeRemaining = YELLOW_TIME;
                        break;
                    case TRANSITION_YELLOW_TO_RED:
                        currentState = STATE_RED;
                        currentTimeRemaining = RED_TIME;
                        break;
                }
            }
        }
    }

    return 0;
}