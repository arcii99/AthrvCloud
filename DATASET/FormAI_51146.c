//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 20
#define YELLOW_LIGHT 4
#define GREEN_LIGHT 20
#define MAX_WAIT_TIME 10

typedef enum {RED, YELLOW, GREEN} Light;

void change_light(Light *current_light) {
    if (*current_light == RED) {
        *current_light = GREEN;
    } else if (*current_light == GREEN) {
        *current_light = YELLOW;
    } else if (*current_light == YELLOW) {
        *current_light = RED;
    }
}

int main() {
    Light current_light = RED;
    int time_remaining = RED_LIGHT + YELLOW_LIGHT + GREEN_LIGHT;
    srand(time(NULL));
    printf("Starting traffic light program...\n");
    while (true) {
        printf("Current light: ");
        if (current_light == RED) {
            printf("RED\n");
        } else if (current_light == YELLOW) {
            printf("YELLOW\n");
        } else if (current_light == GREEN) {
            printf("GREEN\n");
        }

        if (time_remaining <= 0) {
            change_light(&current_light);
            if (current_light == GREEN) {
                time_remaining = GREEN_LIGHT;
            } else if (current_light == YELLOW) {
                time_remaining = YELLOW_LIGHT;
            } else if (current_light == RED) {
                time_remaining = RED_LIGHT;
            }
        }

        int wait_time = rand() % MAX_WAIT_TIME + 1;
        printf("%d seconds until next light change\n", time_remaining);
        printf("Waiting %d seconds...\n", wait_time);
        time_remaining -= wait_time;

        if (time_remaining < 0) {
            time_remaining = 0;
        }
    }

    return 0;
}