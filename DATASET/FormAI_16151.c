//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

void delay(int seconds) {
    sleep(seconds);
}

void update_traffic_light(int current_state) {
    if (current_state == GREEN) {
        printf("\nCurrent State: Green\n");
        printf("Please proceed with caution.\n");
        delay(5);
        update_traffic_light(YELLOW);
    } else if (current_state == YELLOW) {
        printf("\nCurrent State: Yellow\n");
        printf("Please slow down and prepare to stop if necessary.\n");
        delay(3);
        update_traffic_light(RED);
    } else if (current_state == RED) {
        printf("\nCurrent State: Red\n");
        printf("Please stop and wait for the green light.\n");
        delay(5);
        update_traffic_light(GREEN);
    }
}

int main() {
    srand(time(NULL));
    int initial_state = rand() % 3 + 1;
    update_traffic_light(initial_state);
    return 0;
}