//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the state of the traffic light
typedef enum {RED, GREEN, YELLOW} TrafficLight;

// Function to change the traffic light
TrafficLight change_light(TrafficLight current) {
    switch (current) {
        case RED:
            return GREEN;
        case GREEN:
            return YELLOW;
        case YELLOW:
            return RED;
    }
}

// Main function
int main(void) {
    TrafficLight light = RED; // Initialize the light to red
    int counter = 0; // Counter to keep track of time

    while (1) { // Infinite loop
        // Print the current light
        switch (light) {
            case RED:
                printf("[RED]\n");
                break;
            case GREEN:
                printf("[GREEN]\n");
                break;
            case YELLOW:
                printf("[YELLOW]\n");
                break;
        }

        // Change the light every 10 seconds
        if (counter >= 10) {
            light = change_light(light);
            counter = 0;
        }

        counter++; // Increment the counter
        sleep(1); // Wait for 1 second
    }

    return 0;
}