//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_TIME 10
#define YELLOW_TIME 2
#define RED_TIME 5

typedef enum {GREEN, YELLOW, RED} TrafficLight;

void startLight(TrafficLight* light) {
    *light = GREEN;
    printf("Traffic light turned on\n");
}

void updateLight(TrafficLight* light, int* count) {
    switch (*light) {
        case GREEN:
            if (*count == GREEN_TIME) {
                *light = YELLOW;
                *count = 0;
                printf("Traffic light changed to YELLOW\n");
            }
            break;
        case YELLOW:
            if (*count == YELLOW_TIME) {
                *light = RED;
                *count = 0;
                printf("Traffic light changed to RED\n");
            }
            break;
        case RED:
            if (*count == RED_TIME) {
                *light = GREEN;
                *count = 0;
                printf("Traffic light changed to GREEN\n");
            }
            break;
    }
}

int main() {
    TrafficLight light;
    int count = 0;
    startLight(&light);
    while (1) {
        // Update traffic light every second
        updateLight(&light, &count);
        count++;
        // Delay for 1 second
        struct timespec delay = {.tv_sec = 1};
        nanosleep(&delay, NULL);
    }
    return 0;
}