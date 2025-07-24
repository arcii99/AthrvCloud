//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

void delay(int seconds) {
    int milliseconds = seconds * 1000;
    usleep(milliseconds * 1000);
}

void turn_on_light(int light) {
    switch (light) {
        case RED:
            printf("RED light is on.\n");
            break;
        case YELLOW:
            printf("YELLOW light is on.\n");
            break;
        case GREEN:
            printf("GREEN light is on.\n");
            break;
        default:
            printf("Invalid traffic light.\n");
            break;
    }
}

void turn_off_light(int light) {
    switch (light) {
        case RED:
            printf("RED light is off.\n");
            break;
        case YELLOW:
            printf("YELLOW light is off.\n");
            break;
        case GREEN:
            printf("GREEN light is off.\n");
            break;
        default:
            printf("Invalid traffic light.\n");
            break;
    }
}

int main() {
    int current_light = RED;

    srand(time(NULL));

    while (1) {
        turn_on_light(current_light);
        delay(3);
        turn_off_light(current_light);

        if (current_light == RED) {
            current_light = GREEN;
        } else if (current_light == GREEN) {
            current_light = YELLOW;
        } else {
            current_light = RED;
        }
    }

    return 0;
}