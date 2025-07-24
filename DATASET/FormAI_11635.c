//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to delay for a specific number of seconds
void delay(int seconds) {
    int milliseconds = seconds * 1000;
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

// Traffic light states
enum State {
    RED,
    YELLOW,
    GREEN
};

// Struct representing a traffic light
struct TrafficLight {
    enum State state;
    int duration;
};

// Function to update the state of a traffic light
void updateTrafficLight(struct TrafficLight *trafficLight) {
    switch (trafficLight->state) {
        case RED:
            trafficLight->duration = 5;
            trafficLight->state = GREEN;
            break;
        case YELLOW:
            trafficLight->duration = 2;
            trafficLight->state = RED;
            break;
        case GREEN:
            trafficLight->duration = 10;
            trafficLight->state = YELLOW;
            break;
    }
}

int main() {
    // Initialize the traffic lights
    struct TrafficLight trafficLight1 = {.state = RED, .duration = 5};
    struct TrafficLight trafficLight2 = {.state = GREEN, .duration = 10};

    while (1) {
        // Update the traffic light states
        updateTrafficLight(&trafficLight1);
        updateTrafficLight(&trafficLight2);

        // Print the current state of the traffic lights
        printf("Traffic Light 1: ");
        switch (trafficLight1.state) {
            case RED:
                printf("Red\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
        }
        printf("Traffic Light 2: ");
        switch (trafficLight2.state) {
            case RED:
                printf("Red\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
        }

        // Delay for the duration of the current traffic light states
        delay(trafficLight1.duration);
        delay(trafficLight2.duration);
    }

    return 0;
}