//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define MIN_TIME 5
#define MAX_TIME 20

void delay(int seconds) {
    clock_t start_time = clock();
    while(clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    int signal = RED;
    int red_time, yellow_time, green_time;
    srand(time(NULL));
    printf("Traffic Light Controller running...\n");

    while(1) {
        switch(signal) {
            case RED:
                red_time = rand() % (MAX_TIME - MIN_TIME) + MIN_TIME;
                printf("Red signal for %d seconds\n", red_time);
                delay(red_time);
                signal = GREEN;
                break;

            case YELLOW:
                yellow_time = rand() % (MAX_TIME - MIN_TIME) + MIN_TIME;
                printf("Yellow signal for %d seconds\n", yellow_time);
                delay(yellow_time);
                if(rand() % 2) signal = RED;
                else signal = GREEN;
                break;

            case GREEN:
                green_time = rand() % (MAX_TIME - MIN_TIME) + MIN_TIME;
                printf("Green signal for %d seconds\n", green_time);
                delay(green_time);
                signal = YELLOW;
                break;
        }
    }
    return 0;
}