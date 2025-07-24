//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int green_time = 5;
    int yellow_time = 2;
    int red_time = 5;
    bool is_green = true;
    bool is_yellow = false;
    bool is_red = false;
    
    while (1) {
        if (is_green) {
            printf("Green Light is on\n");
            delay(green_time);
            is_green = false;
            is_yellow = true;
        }
        else if (is_yellow) {
            printf("Yellow Light is on\n");
            delay(yellow_time);
            is_yellow = false;
            is_red = true;
        }
        else if (is_red) {
            printf("Red Light is on\n");
            delay(red_time);
            is_red = false;
            is_green = true;
        }
    }
    return 0;
}