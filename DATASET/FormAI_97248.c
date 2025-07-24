//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define RED_TIME 10
#define YELLOW_TIME 2
#define GREEN_TIME 10

int current_light;
int time_remaining;

void update_controller();
void print_controller_state();

int main() {
    srand(time(NULL));
    current_light = rand() % 3;
    time_remaining = current_light == RED ? RED_TIME :
                    current_light == YELLOW ? YELLOW_TIME :
                    GREEN_TIME;
    print_controller_state();
    while (1) {
        update_controller();
        print_controller_state();
        if (time_remaining == 0) {
            current_light = (current_light + 1) % 3;
            time_remaining = current_light == RED ? RED_TIME :
                            current_light == YELLOW ? YELLOW_TIME :
                            GREEN_TIME;
        }
    }
}

void update_controller() {
    time_remaining--;
}

void print_controller_state() {
    printf("Current Light: ");
    if (current_light == RED) {
        printf("RED\n");
    } else if (current_light == YELLOW) {
        printf("YELLOW\n");
    } else if (current_light == GREEN) {
        printf("GREEN\n");
    }
    printf("Time Remaining: %d seconds\n\n", time_remaining);
}