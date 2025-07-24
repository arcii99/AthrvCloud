//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

void delay(int seconds) {
    int ms = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + ms);
}

int main() {
    int light_controller[3] = {GREEN, YELLOW, RED};
    int current_state = 0;
    printf("Press Ctrl+C to exit\n");

    while (1) {
        printf("Green light is on\n");
        delay(10);

        printf("Yellow light is on\n");
        delay(3);

        printf("Red light is on\n");
        delay(10);

        current_state++;
        if (current_state > 2) {
            current_state = 0;
        }
    }

    return 0;
}