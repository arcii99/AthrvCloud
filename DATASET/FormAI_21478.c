//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
    int state = GREEN;
    time_t start_time, current_time;
    int delay_time = 10;
    srand(time(NULL));

    while(1) {
        printf("Current State: %d\n", state);
        switch(state) {
            case RED:
                printf("Stop!\n");
                start_time = time(NULL);
                while((current_time = time(NULL)) - start_time < delay_time);
                if(rand() % 2 == 0) {
                    state = GREEN;
                } else {
                    state = YELLOW;
                }
                break;
            case YELLOW:
                printf("Prepare to Go!\n");
                start_time = time(NULL);
                while((current_time = time(NULL)) - start_time < delay_time);
                state = GREEN;
                break;
            case GREEN:
                printf("Go!\n");
                start_time = time(NULL);
                while((current_time = time(NULL)) - start_time < delay_time);
                if(rand() % 2 == 0) {
                    state = YELLOW;
                } else {
                    state = RED;
                }
                break;
        }
    }
    return 0;
}