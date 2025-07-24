//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define RED_DURATION 5
#define YELLOW_DURATION 2
#define GREEN_DURATION 8

typedef enum {
    RED,
    YELLOW,
    GREEN
} Light;

int main() {
    bool running = true;
    int red_timer = RED_DURATION;
    int yellow_timer = 0;
    int green_timer = 0;
    Light current_light = RED;

    srand(time(NULL));

    printf("Traffic light controller program\n");

    while (running) {
        switch (current_light) {
            case RED:
                printf("Red light on, %d seconds remaining\n", red_timer);
                if (--red_timer == 0) {
                    current_light = GREEN;
                    green_timer = GREEN_DURATION;
                }
                break;
            case YELLOW:
                printf("Yellow light on, %d seconds remaining\n", yellow_timer);
                if (--yellow_timer == 0) {
                    if (rand() % 2) {
                        current_light = RED;
                        red_timer = RED_DURATION;
                    } else {
                        current_light = GREEN;
                        green_timer = GREEN_DURATION;
                    }
                }
                break;
            case GREEN:
                printf("Green light on, %d seconds remaining\n", green_timer);
                if (--green_timer == 0) {
                    current_light = YELLOW;
                    yellow_timer = YELLOW_DURATION;
                }
                break;
        }

        sleep(1);
    }

    return 0;
}