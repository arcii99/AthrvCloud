//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for traffic light timing
#define GREEN_DURATION 30
#define YELLOW_DURATION 5
#define RED_DURATION 25

// Define an enum for the traffic light color
enum TRAFFIC_LIGHT_COLOR {GREEN, YELLOW, RED};

// Define a function to print the current traffic light color
void print_traffic_light(enum TRAFFIC_LIGHT_COLOR color) {
    switch(color) {
        case GREEN:
            printf("Traffic Light is Green\n");
            break;
        case YELLOW:
            printf("Traffic Light is Yellow\n");
            break;
        case RED:
            printf("Traffic Light is Red\n");
            break;
    }
}

// Define a function to control the traffic light
void exec_traffic_light(bool toggle) {
    static enum TRAFFIC_LIGHT_COLOR color = RED;
    static int count = 0;

    if(toggle) {
        count++;

        // Determine the current traffic light color based on count
        if(count <= GREEN_DURATION) {
            color = GREEN;
        } else if(count <= (GREEN_DURATION + YELLOW_DURATION)) {
            color = YELLOW;
        } else {
            color = RED;
            count = 0;
        }

        // Print the current traffic light color
        print_traffic_light(color);
    }
}

int main() {
    bool toggle = true;

    // Simulate traffic light for 2 minutes
    for(int i = 0; i < 120; i++) {
        exec_traffic_light(toggle);
        toggle = !toggle; // Toggle the traffic light every second
    }

    return 0;
}