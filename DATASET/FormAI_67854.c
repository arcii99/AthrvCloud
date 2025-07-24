//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    int red_time = 10;
    int yellow_time = 5;
    int green_time = 15;
    int cycle_time = red_time + yellow_time + green_time;

    printf("Welcome to the Mind-Bending Traffic Light Controller Program!\n");
    printf("Press Ctrl+C to quit at any time.\n\n");

    while (1) {
        printf("Red Light\n");
        delay(red_time);
        printf("Yellow Light\n");
        delay(yellow_time);
        printf("Green Light\n");
        delay(green_time);
        printf("\n");

        int rand_time = rand() % cycle_time;
        if (rand_time < red_time) {
            printf("Random Red Light for %d seconds.\n", rand_time);
            delay(rand_time);
        } else if (rand_time < red_time + yellow_time) {
            printf("Random Yellow Light for %d seconds.\n", rand_time - red_time);
            delay(rand_time - red_time);
        } else {
            printf("Random Green Light for %d seconds.\n", rand_time - red_time - yellow_time);
            delay(rand_time - red_time - yellow_time);
        }

        printf("\n");
    }

    return 0;
}