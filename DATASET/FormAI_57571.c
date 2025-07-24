//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the states and events for the Traffic Light FSM
typedef enum {
    RED,
    YELLOW,
    GREEN
} State;

typedef enum {
    PED_EVENT,
    TIMER_EVENT,
    END_EVENT
} Event;

// Initializing the state and event variables
State currentState = RED;
Event currentEvent;

// Setting the timer variable for switching from Green to Yellow state
int timer = 0;

// Defining the functions for handling each state and event
void redState() {
    printf("Traffic Light is RED\n");
}

void yellowState() {
    printf("Traffic Light is YELLOW\n");
}

void greenState() {
    printf("Traffic Light is GREEN\n");
}

void pedestrianEvent() {
    printf("Pedestrian Event Occurred\n");
}

void timerEvent() {
    printf("Timer Event Occurred\n");
}

void endEvent() {
    printf("End Event Occurred\n");
}

// Function to handle the transition from one state to another
void transition(State newState) {
    // Checking the current state and the event that was triggered
    switch(currentState) {
        case RED:
            if (currentEvent == PED_EVENT) {
                currentState = GREEN;
                greenState();
            }
            else {
                currentState = GREEN;
                greenState();
            }
            break;
        case YELLOW:
            if (currentEvent == TIMER_EVENT) {
                currentState = RED;
                redState();
            }
            else {
                currentState = RED;
                redState();
            }
            break;
        case GREEN:
            if (currentEvent == TIMER_EVENT) {
                currentState = YELLOW;
                yellowState();
            }
            else {
                currentState = YELLOW;
                yellowState();
            }
            break;
    }
}

// Looping through the events until the end
int main() {
    while (currentEvent != END_EVENT) {
        // Generating random event for simulation
        int randNum = rand() % 3;
        if (randNum == 0) {
            currentEvent = PED_EVENT;
            pedestrianEvent();
        }
        else if (randNum == 1) {
            currentEvent = TIMER_EVENT;
            timerEvent();
        }
        else {
            currentEvent = END_EVENT;
            endEvent();
        }
        // Handling the transitions after the events occur
        transition(currentState);
    }
    return 0;
}