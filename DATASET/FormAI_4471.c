//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

typedef struct {
    int state;
    int countdown;
} Light;

void print_state(Light* light) {
    switch(light->state) {
        case RED:
            printf("RED\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        case YELLOW:
            printf("YELLOW\n");
            break;
    }
}

void update_light(Light* light) {
    switch(light->state) {
        case RED:
            light->state = GREEN;
            light->countdown = 20;
            break;
        case GREEN:
            light->state = YELLOW;
            light->countdown = 5;
            break;
        case YELLOW:
            light->state = RED;
            light->countdown = 25;
            break;
    }
}

void tick(Light* light) {
    light->countdown--;
    if(light->countdown == 0) {
        update_light(light);
    }
}

int main() {
    Light traffic_light = {RED, 25};

    printf("Starting Traffic Light Controller\n");

    while(1) {
        tick(&traffic_light);
        print_state(&traffic_light);
    }

    return 0;
}