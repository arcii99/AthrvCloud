//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

void delay(int seconds) {
    int end = clock() + seconds * CLOCKS_PER_SEC;
    while(clock() < end);
}

int main() {
    int state = GREEN;

    while(1) {
        switch(state) {
            case GREEN:
                printf("Green light on, cars can go!\n");
                delay(10);
                state = YELLOW;
                break;

            case YELLOW:
                printf("Yellow light on, cars should prepare to stop.\n");
                delay(2);
                state = RED;
                break;

            case RED:
                printf("Red light on, cars must stop.\n");
                delay(10);
                state = GREEN;
                break;
        }
    }
    return 0;
}