//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// defining the duration of red, green and yellow lights
#define RED_LIGHT_TIME 10
#define YELLOW_LIGHT_TIME 3
#define GREEN_LIGHT_TIME 15

// defining the state of the traffic light
enum state {
    RED,
    YELLOW,
    GREEN
};

// function to control the traffic light state
void traffic_light_controller(enum state current_state, int time_remaining) {
    // switch case for different traffic light states
    switch(current_state) {
        case RED:
            printf("RED LIGHT - STOP!\n");
            sleep(time_remaining);
            traffic_light_controller(YELLOW, YELLOW_LIGHT_TIME);
            break;
        case YELLOW:
            printf("YELLOW LIGHT - SLOW DOWN!\n");
            sleep(time_remaining);
            traffic_light_controller(GREEN, GREEN_LIGHT_TIME);
            break;
        case GREEN:
            printf("GREEN LIGHT - GO!\n");
            sleep(time_remaining);
            traffic_light_controller(RED, RED_LIGHT_TIME);
            break;
    }
}

int main() {
    int time_remaining = 0;
    enum state current_state = RED;
    traffic_light_controller(current_state, time_remaining);
    return 0;
}