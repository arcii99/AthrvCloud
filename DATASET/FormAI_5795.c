//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* Traffic light state */
typedef enum TrafficLightState {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

/* Get the duration of a state */
int getStateDuration(TrafficLightState state) {
    switch (state) {
        case RED:
            return 10;
        case YELLOW:
            return 3;
        case GREEN:
            return 15;
        default:
            return 0;
    }
}

/* Traffic light controller */
int main() {
    srand(time(NULL)); // set the seed for the random number generator
    
    TrafficLightState state = RED; // start at red light
    int remainingTime = getStateDuration(state); // get the duration of this state
    
    printf("The traffic light is now RED.\n");

    while (true) {
        // check if the remaining time of the current state is 0
        if (remainingTime == 0) {
            // change to the next state
            switch (state) {
                case RED:
                    state = GREEN;
                    printf("The traffic light is now GREEN.\n");
                    break;
                case YELLOW:
                    state = RED;
                    printf("The traffic light is now RED.\n");
                    break;
                case GREEN:
                    state = YELLOW;
                    printf("The traffic light is now YELLOW.\n");
                    break;
                default:
                    break;
            }
            // get the duration of this state
            remainingTime = getStateDuration(state);
        }
        printf("%d seconds left in this state.\n", remainingTime);
        remainingTime--; // decrement the remaining time
        int waitTime = rand()%3 + 1; // wait for 1-3 seconds
        printf("Waiting for %d seconds.\n", waitTime);
        sleep(waitTime); // wait for a random time between 1-3 seconds
    }
    return 0;
}