//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {
    int state = RED;
    time_t start_time = time(NULL);

    while (1) {
        time_t current_time = time(NULL);
        int elapsed_time = current_time - start_time;

        switch (state) {
            case RED:
                printf("RED\n");
                if (elapsed_time >= 20) {
                    state = GREEN;
                    start_time = current_time;
                }
                break;
            case YELLOW:
                printf("YELLOW\n");
                if (elapsed_time >= 2) {
                    state = RED;
                    start_time = current_time;
                }
                break;
            case GREEN:
                printf("GREEN\n");
                if (elapsed_time >= 30) {
                    state = YELLOW;
                    start_time = current_time;
                }
                break;
        }
    }

    return 0;
}