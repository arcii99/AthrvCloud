//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define traffic light states
#define GREEN 0
#define YELLOW 1
#define RED 2

// Define traffic light modes
#define MANUAL 0
#define AUTOMATIC 1

// Define traffic light timings
#define GREEN_DURATION 10
#define YELLOW_DURATION 3
#define RED_DURATION 10

// Function to print the current state of the traffic light
void printState(int state) {
    switch (state) {
        case GREEN:
            printf("Green\n");
            break;
        case YELLOW:
            printf("Yellow\n");
            break;
        case RED:
            printf("Red\n");
            break;
        default:
            printf("Invalid state\n");
    }
}

// Function to switch from one traffic light state to another
int switchState(int currentState) {
    switch (currentState) {
        case GREEN:
            return YELLOW;
        case YELLOW:
            return RED;
        case RED:
            return GREEN;
        default:
            return -1; // Error
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    int mode = MANUAL; // Start with manual mode
    int state = RED; // Start with red light
    
    while(1) {
        // Display traffic light state
        printf("Traffic light is currently: ");
        printState(state);
        
        if (mode == AUTOMATIC) {
            // Sleep for the duration of the current state
            switch (state) {
                case GREEN:
                    sleep(GREEN_DURATION);
                    break;
                case YELLOW:
                    sleep(YELLOW_DURATION);
                    break;
                case RED:
                    sleep(RED_DURATION);
                    break;
            }
            // Switch to the next state
            state = switchState(state);
        } else {
            // Prompt user for input
            printf("Press 's' to switch to the next state.\n");
            printf("Press 'a' to switch to automatic mode.\n");
            char input = getchar();
            getchar(); // Read the newline left in stdin
            
            switch (input) {
                case 's':
                    state = switchState(state);
                    break;
                case 'a':
                    mode = AUTOMATIC;
                    // Randomize the starting state when switching to automatic mode
                    state = rand() % 3;
                    break;
                default:
                    printf("Invalid input.\n");
            }
        }
    }
    return 0;
}