//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
    srand(time(NULL));
    int state = GREEN;
    int timer = rand() % 20 + 1;
    int count = 0;

    while (count < 10) {
        if (state == RED) {
            printf("RED\n");
            sleep(timer);
            state = GREEN;
            timer = rand() % 20 + 1;
        }
        else if (state == YELLOW) {
            printf("YELLOW\n");
            sleep(3);
            state = RED;
        }
        else if (state == GREEN) {
            printf("GREEN\n");
            sleep(timer);
            state = YELLOW;
            timer = rand() % 5 + 1;
            count++;
        }
    }

    printf("Traffic Light Controller Simulation Complete\n");

    return 0;
}