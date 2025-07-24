//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the constants for managing the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the time duration for each traffic light states in seconds
#define RED_LIGHT_DURATION 13
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 15

// Define the function to display the current traffic light state
void displayLightState(int currentState) {
    switch (currentState) {
        case RED:
            printf("RED LIGHT\n");
            break;

        case YELLOW:
            printf("YELLOW LIGHT\n");
            break;

        case GREEN:
            printf("GREEN LIGHT\n");
            break;
    }
}

// Define the function to simulate the traffic light controller
void simulateTrafficLight() {
    int currentState = RED; // Initialize the current state to RED
    int timeRemaining = RED_LIGHT_DURATION; // Initialize the time remaining to RED_LIGHT_DURATION

    while (1) {
        // Display the current traffic light state
        displayLightState(currentState);

        // Wait for the current time remaining
        for (int i = timeRemaining; i >= 0; i--) {
            printf("%d\n", i);
            sleep(1);
        }

        // Change the traffic light state
        switch (currentState) {
            case RED:
                currentState = GREEN;
                timeRemaining = GREEN_LIGHT_DURATION;
                break;

            case YELLOW:
                currentState = RED;
                timeRemaining = RED_LIGHT_DURATION;
                break;

            case GREEN:
                currentState = YELLOW;
                timeRemaining = YELLOW_LIGHT_DURATION;
                break;
        }
    }
}

// Define the main function to start the traffic light simulation
int main() {
    simulateTrafficLight();

    return 0;
}