//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock();

    while (clock() < start_time + (seconds * CLOCKS_PER_SEC));
}

int main() {
    int traffic_state = 0; // 0 = red light, 1 = yellow light, 2 = green light
    int red_time = 8;
    int yellow_time = 3;
    int green_time = 4;

    while (1) {
        switch(traffic_state) {
            case 0: // Red Light
                printf("Red Light\n");
                delay(red_time);
                traffic_state = 1; // Change to Yellow Light
                break;

            case 1: // Yellow Light
                printf("Yellow Light\n");
                delay(yellow_time);
                traffic_state = 2; // Change to Green Light
                break;

            case 2: // Green Light
                printf("Green Light\n");
                delay(green_time);
                traffic_state = 0; // Change to Red Light
                break;
        }
    }

    return 0;
}