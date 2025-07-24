//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// define constants for the colors of the traffic light
enum colors {
    RED,
    YELLOW,
    GREEN,
};

// define a struct to hold the current state of the traffic light
struct traffic_light {
    enum colors color;
    int duration;
};

// function to print the current state of the traffic light
void display_traffic_light(struct traffic_light light) {
    switch(light.color) {
        case RED:
            printf("\nRED LIGHT ON!!!\n");
            break;
        case YELLOW:
            printf("\nYELLOW LIGHT ON!!!\n");
            break;
        case GREEN:
            printf("\nGREEN LIGHT ON!!!\n");
            break;
    }
}

int main() {
    struct traffic_light light = {
        .color = RED,
        .duration = 10,
    };

    while(1) {
        // display the current state of the traffic light
        display_traffic_light(light);

        // update the state of the traffic light
        switch(light.color) {
            case RED:
                usleep(light.duration * 1000000);
                light.color = GREEN;
                light.duration = 20;
                break;
            case YELLOW:
                usleep(light.duration * 1000000);
                light.color = RED;
                light.duration = 10;
                break;
            case GREEN:
                usleep(light.duration * 1000000);
                light.color = YELLOW;
                light.duration = 5;
                break;
        }
    }

    return 0;
}