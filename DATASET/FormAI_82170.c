//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

int traffic_light = RED_LIGHT; // initial traffic light state is red

void *controller(void *arg) {
    while(1) {
        switch(traffic_light) {
            case RED_LIGHT:
                printf("Red light is on\n");
                sleep(5);
                traffic_light = GREEN_LIGHT;
                break;
            case YELLOW_LIGHT:
                printf("Yellow light is on\n");
                sleep(2);
                traffic_light = RED_LIGHT;
                break;
            case GREEN_LIGHT:
                printf("Green light is on\n");
                sleep(10);
                traffic_light = YELLOW_LIGHT;
                break;
        }
    }
}

int main() {
    pthread_t control_thread;

    int rc = pthread_create(&control_thread, NULL, controller, NULL);
    if (rc) {
        printf("Thread creation failed: %d", rc);
        return 1;
    }

    while(1) {
        printf("Traffic light is %d\n", traffic_light);
        sleep(1);
    }

    return 0;
}