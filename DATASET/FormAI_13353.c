//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// Define enum for traffic light states
enum TrafficLightState {
    RED, YELLOW, GREEN
};

// Define struct for traffic light
struct TrafficLight {
    enum TrafficLightState state;
    int duration;
};

// Define function to update traffic light state
void updateTrafficLight(struct TrafficLight *trafficLight) {
    switch(trafficLight->state) {
        case RED:
            trafficLight->state = GREEN;
            trafficLight->duration = 10;
            break;
        case YELLOW:
            trafficLight->state = RED;
            trafficLight->duration = 5;
            break;
        case GREEN:
            trafficLight->state = YELLOW;
            trafficLight->duration = 2;
            break;
    }
}

// Define function to display traffic light state
void displayTrafficLight(struct TrafficLight *trafficLight) {
    switch(trafficLight->state) {
        case RED:
            printf("\nRED LIGHT\n");
            break;
        case YELLOW:
            printf("\nYELLOW LIGHT\n");
            break;
        case GREEN:
            printf("\nGREEN LIGHT\n");
            break;
    }
}

int main() {
    struct TrafficLight tLight;
    tLight.state = RED;
    tLight.duration = 5;
    
    while(true) {
        displayTrafficLight(&tLight);
        sleep(tLight.duration);
        updateTrafficLight(&tLight);
    }
    
    return 0;
}