//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(float seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    int green = 1, yellow = 2, red = 4;

    int state = red;

    while(1) {
        if(state == red) {
            printf("Red Light\n");
            delay(5.0); // wait for 5 seconds
            state = green; // switch to green
        }
        else if(state == green) {
            printf("Green Light\n");
            delay(10.0); // wait for 10 seconds
            state = yellow; // switch to yellow
        }
        else if(state == yellow) {
            printf("Yellow Light\n");
            delay(2.0); // wait for 2 seconds
            state = red; // switch to red
        }
    }

    return 0;
}