//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define GREEN_LIGHT_TIME 10  // Green light time in seconds
#define YELLOW_LIGHT_TIME 3  // Yellow light time in seconds
#define RED_LIGHT_TIME 15    // Red light time in seconds

typedef struct {
    bool is_green;
    bool is_yellow;
    bool is_red;
} Light;

void print_traffic_light(Light* traffic_light) {
    printf("Traffic Light Status:\n");
    printf("Green: %s\n", traffic_light->is_green ? "On" : "Off");
    printf("Yellow: %s\n", traffic_light->is_yellow ? "On" : "Off");
    printf("Red: %s\n\n", traffic_light->is_red ? "On" : "Off");
}

int main() {
    // Initialize traffic light to all red
    Light traffic_light = { false, false, true };
    print_traffic_light(&traffic_light);

    // Loop forever
    while (true) {
        // Wait for random amount of time
        srand(time(NULL));
        int wait_time = rand() % 10 + 1;  // Random between 1 and 10 seconds
        printf("Waiting for %d seconds...\n", wait_time);
        sleep(wait_time);

        // Change traffic light colors
        if (traffic_light.is_red) {
            traffic_light.is_red = false;
            traffic_light.is_green = true;
            printf("Green light on for %d seconds...\n", GREEN_LIGHT_TIME);
            sleep(GREEN_LIGHT_TIME);
            traffic_light.is_green = false;
            traffic_light.is_yellow = true;
            printf("Yellow light on for %d seconds...\n", YELLOW_LIGHT_TIME);
            sleep(YELLOW_LIGHT_TIME);
            traffic_light.is_yellow = false;
            traffic_light.is_red = true;
            printf("Red light on for %d seconds...\n", RED_LIGHT_TIME);
            sleep(RED_LIGHT_TIME);
        }
        print_traffic_light(&traffic_light);
    }
    return 0;
}