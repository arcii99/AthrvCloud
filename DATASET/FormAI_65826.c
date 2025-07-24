//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

/* function prototypes */
void stop_light();
void warn_light();
void go_light();

/* global variable to keep track of traffic light state */
int traffic_light_state = RED_LIGHT;

int main() {
    int i;

    /* loop forever */
    while (1) {

        /* switch case to handle traffic light states */
        switch (traffic_light_state) {
            case RED_LIGHT:
                stop_light();
                traffic_light_state = GREEN_LIGHT;
                break;
            case YELLOW_LIGHT:
                warn_light();
                traffic_light_state = RED_LIGHT;
                break;
            case GREEN_LIGHT:
                go_light();
                traffic_light_state = YELLOW_LIGHT;
                break;
            default:
                printf("Invalid state!\n");
                exit(1);
        }

        /* wait for some time between light changes */
        for (i = 0; i < 500000; i++) {
            /* do nothing */
        }
    }

    return 0;
}

/* function to display red light */
void stop_light() {
    printf("STOP! RED LIGHT\n");
}

/* function to display yellow light */
void warn_light() {
    printf("CAUTION! YELLOW LIGHT\n");
}

/* function to display green light */
void go_light() {
    printf("GO! GREEN LIGHT\n");
}