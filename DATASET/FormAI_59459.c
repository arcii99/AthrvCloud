//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum light { RED, YELLOW, GREEN };

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void trafficLightController() {
    srand(time(NULL));
    int lightTime[3] = {10, 5, 10};
    int yellowLightTime[3] = {2, 2, 2};
    printf("Traffic Light Controller Started.\n");

    while (1) {
        enum light currentLight = RED;
        printf("Current Light: RED\n");
        delay(lightTime[RED] * 1000);

        currentLight = YELLOW;
        printf("Current Light: YELLOW\n");
        delay(yellowLightTime[YELLOW] * 1000);

        currentLight = GREEN;
        printf("Current Light: GREEN\n");
        delay(lightTime[GREEN] * 1000);

        currentLight = YELLOW;
        printf("Current Light: YELLOW\n");
        delay(yellowLightTime[YELLOW] * 1000);
    }
}

int main() {
    trafficLightController();
    return 0;
}