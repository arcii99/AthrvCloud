//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the State Machine states
typedef enum {
    Green,
    Yellow,
    Red,
} State;

// Define the Traffic Light structure
typedef struct {
    State state;
    int timeRemaining;
} TrafficLight;

// Define the function prototypes
void changeState(TrafficLight* trafficLight);
void printState(TrafficLight* trafficLight);
void printStatus(TrafficLight* trafficLight);

// Main function
int main() {
    TrafficLight trafficLight = {Green, 10};  // Initialize the traffic light
    
    while (1) {  // Main loop
        system("clear");  // Clear the console
        
        printStatus(&trafficLight);  // Print the traffic light status
        
        if (trafficLight.timeRemaining == 0) {  // Time is up
            changeState(&trafficLight);  // Change the state
        }
        else {
            trafficLight.timeRemaining--;  // Decrement the time remaining
        }
        
        sleep(1);  // Wait for 1 second
    }
    
    return 0;
}

// Change the state function
void changeState(TrafficLight* trafficLight) {
    switch (trafficLight->state) {
        case Green:
            trafficLight->state = Yellow;
            trafficLight->timeRemaining = 3;
            break;
        case Yellow:
            trafficLight->state = Red;
            trafficLight->timeRemaining = 5;
            break;
        case Red:
            trafficLight->state = Green;
            trafficLight->timeRemaining = 10;
            break;
    }
}

// Print the state function
void printState(TrafficLight* trafficLight) {
    switch (trafficLight->state) {
        case Green:
            printf("Green ");
            break;
        case Yellow:
            printf("Yellow ");
            break;
        case Red:
            printf("Red ");
            break;
    }
}

// Print the status function
void printStatus(TrafficLight* trafficLight) {
    printf("Traffic Light Status:\n\n");
    printf("State: ");
    printState(trafficLight);
    printf("\nTime Remaining: %d\n", trafficLight->timeRemaining);
}