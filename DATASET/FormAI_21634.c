//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// define traffic light states
enum TrafficLightState {
    GREEN,
    YELLOW,
    RED
};

// define function to handle state transition
enum TrafficLightState transition(enum TrafficLightState state) {
    switch (state) {
        case GREEN:
            return YELLOW;
        case YELLOW:
            return RED;
        case RED:
            return GREEN;
    }
}

// define function to print current state
void printState(enum TrafficLightState state) {
    switch (state) {
        case GREEN:
            printf("Green light is on\n");
            break;
        case YELLOW:
            printf("Yellow light is on\n");
            break;
        case RED:
            printf("Red light is on\n");
            break;
    }
}

int main() {
    enum TrafficLightState state = GREEN; // set initial state to green
    int cycleCount = 0; // count number of cycles
    
    while (1) { // loop infinitely
        printState(state);
        cycleCount++;
        
        if (cycleCount == 10) { // if 10 cycles have passed
            state = transition(state); // transition to next state
            cycleCount = 0; // reset cycle count
        }
        
        // wait for 1 second
        #ifdef _WIN32
            system("timeout /t 1 >nul");
        #else
            sleep(1);
        #endif
    }
    
    return 0;
}