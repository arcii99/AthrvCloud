//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
/* This is a traffic light controller program written in the style of Claude Shannon, the father of digital circuit design.
 * The program uses a state machine to track the current state of the traffic lights and transition between states based on events.
 * It also includes a function to simulate the passage of time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the traffic light intervals
#define GREEN_LIGHT_INTERVAL 10
#define YELLOW_LIGHT_INTERVAL 2
#define RED_LIGHT_INTERVAL 10

// Define constants for the different states of the traffic light
enum LightState { GREEN, YELLOW, RED };

int main() {
    enum LightState lightState = GREEN; // Start with the green light on
    int timer = GREEN_LIGHT_INTERVAL; // Start with the green light interval

    while (1) { // Run infinitely
        printf("The light is currently ");

        switch (lightState) { // Print the current state of the light
            case GREEN:
                printf("green.\n");
                break;
            case YELLOW:
                printf("yellow.\n");
                break;
            case RED:
                printf("red.\n");
                break;
        }

        printf("Waiting for %d seconds...\n", timer); // Wait for the current timer interval
        sleep(timer); // Simulate the passage of time

        switch (lightState) { // Transition to the next state based on the current state
            case GREEN:
                lightState = YELLOW;
                timer = YELLOW_LIGHT_INTERVAL;
                break;
            case YELLOW:
                lightState = RED;
                timer = RED_LIGHT_INTERVAL;
                break;
            case RED:
                lightState = GREEN;
                timer = GREEN_LIGHT_INTERVAL;
                break;
        }
    }
}