//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define GREEN 1
#define YELLOW 2
#define RED 3
#define MAX_TIME 30

void countdown(int time) {
    int countdown = time;
    while (countdown > 0) {
        printf("Time remaining: %d seconds.\n", countdown);
        countdown--;
        sleep(1);
    }
}

void display_status(int status) {
    if (status == GREEN) {
        printf("The traffic light is currently green.\n");
    } else if (status == YELLOW) {
        printf("The traffic light is currently yellow.\n");
    } else {
        printf("The traffic light is currently red.\n");
    }
}

int main() {
    srand(time(0));
    int status = GREEN;
    int time_left = MAX_TIME;
    bool running = true;
    printf("Welcome to the traffic light controller!\n");

    while (running) {
        display_status(status);
        countdown(time_left);

        if (status == GREEN) {
            status = YELLOW;
            time_left = 5; // Yellow light lasts 5 seconds

        } else if (status == YELLOW) {
            status = RED;
            time_left = 10; // Red light lasts 10 seconds

        } else {
            status = GREEN;
            time_left = (rand() % 20) + 10; // Green lasts between 10 and 30 seconds
        }
    }
    return 0;
}