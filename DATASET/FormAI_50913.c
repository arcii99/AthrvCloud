//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
// This code snippet is a futuristic traffic light controller, using advanced algorithms and technology.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_GREEN_TIME 10    // minimum green time for a lane in seconds
#define MAX_GREEN_TIME 30    // maximum green time for a lane in seconds
#define YELLOW_TIME 5        // yellow light duration in seconds

// Enum to represent the various states of a traffic light
typedef enum {
    RED,
    YELLOW,
    GREEN
} LightState;

// Struct to represent a traffic light
typedef struct {
    LightState state;       // current state of the light
    int duration;           // duration of the current state
} TrafficLight;

// Function to change the state of a traffic light
void changeLightState(TrafficLight* light, LightState newState) {
    light->state = newState;
    light->duration = 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the traffic lights
    TrafficLight northLight = {RED, 0};
    TrafficLight southLight = {RED, 0};
    TrafficLight eastLight = {GREEN, 0};
    TrafficLight westLight = {GREEN, 0};

    while(true) {
        // Print the current state of the traffic lights
        printf("North-South: %d\tEast-West: %d\n", northLight.state, eastLight.state);

        // Update the duration of the current state for each traffic light
        northLight.duration++;
        southLight.duration++;
        eastLight.duration++;
        westLight.duration++;

        // Check if any traffic light needs to change state
        if(northLight.state == GREEN && northLight.duration >= MAX_GREEN_TIME)
            changeLightState(&northLight, YELLOW);
        else if(southLight.state == GREEN && southLight.duration >= MAX_GREEN_TIME)
            changeLightState(&southLight, YELLOW);
        else if(eastLight.state == GREEN && eastLight.duration >= MAX_GREEN_TIME)
            changeLightState(&eastLight, YELLOW);
        else if(westLight.state == GREEN && westLight.duration >= MAX_GREEN_TIME)
            changeLightState(&westLight, YELLOW);
        else if((northLight.state == YELLOW && northLight.duration >= YELLOW_TIME) ||
                (southLight.state == YELLOW && southLight.duration >= YELLOW_TIME) ||
                (eastLight.state == YELLOW && eastLight.duration >= YELLOW_TIME) ||
                (westLight.state == YELLOW && westLight.duration >= YELLOW_TIME)) {
            // Reset the duration of the current state and switch to the appropriate next state
            if(northLight.state == YELLOW || southLight.state == YELLOW) {
                changeLightState(&northLight, RED);
                changeLightState(&southLight, RED);

                // Randomly choose which east-west lane gets the green light
                if(rand() % 2 == 0)
                    changeLightState(&eastLight, GREEN);
                else
                    changeLightState(&westLight, GREEN);
            }
            else {
                changeLightState(&eastLight, RED);
                changeLightState(&westLight, RED);

                // Randomly choose which north-south lane gets the green light
                if(rand() % 2 == 0)
                    changeLightState(&northLight, GREEN);
                else
                    changeLightState(&southLight, GREEN);
            }
        }

        // Sleep for 1 second before starting a new iteration
        sleep(1);
    }

    return 0;
}