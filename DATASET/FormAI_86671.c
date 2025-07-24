//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// defining the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// defining the traffic light times (in seconds)
#define RED_TIME 10
#define YELLOW_TIME 3
#define GREEN_TIME 15

// function to update the state of the traffic light
void update_traffic_light(int new_state) {
    static int current_state = RED; // initialize the current state to red
    if (new_state != current_state) {
        switch (new_state) {
            case RED:
                printf("Traffic light: RED\n");
                sleep(RED_TIME);
                break;
            case YELLOW:
                printf("Traffic light: YELLOW\n");
                sleep(YELLOW_TIME);
                break;
            case GREEN:
                printf("Traffic light: GREEN\n");
                sleep(GREEN_TIME);
                break;
            default:
                // if the new state is invalid, stay in the current state
                printf("Invalid state, staying in current state\n");
                return;
        }
        current_state = new_state;
    } else {
        // if the new state is the same as the current state, do nothing
        printf("Already in this state, doing nothing\n");
    }
}

int main() {
    // initialize the traffic light to red
    update_traffic_light(RED);

    // loop through the states of the traffic light
    while (true) {
        update_traffic_light(GREEN);
        update_traffic_light(YELLOW);
        update_traffic_light(RED);
    }

    // unreachable code
    return 0;
}