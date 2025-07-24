//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GREEN 10
#define YELLOW 3
#define RED 12

int main() {
    int currentlight = GREEN;
    time_t starttime, currenttime;
    bool emergency = false;

    printf("Traffic light system starting...\n");

    while (true) {
        if (emergency) {
            currentlight = GREEN; // switch to green immediately
            printf("Emergency vehicle detected, switching to GREEN\n");
            emergency = false; // turn off emergency for next cycle
        }

        starttime = time(NULL);

        while (difftime(time(NULL), starttime) < currentlight) {
            currenttime = time(NULL);
            printf("Current light: ");
            if (currentlight == GREEN) {
                printf("GREEN\n");
            } else if (currentlight == YELLOW) {
                printf("YELLOW\n");
            } else {
                printf("RED\n");
            }

            printf("Time remaining: %ld seconds\n", currentlight - difftime(currenttime, starttime));
            printf("----------------------\n");
        }

        if (currentlight == GREEN) {
            currentlight = YELLOW;
        } else if (currentlight == YELLOW) {
            currentlight = RED;
        } else {
            currentlight = GREEN;
        }
    }
    return 0;
}