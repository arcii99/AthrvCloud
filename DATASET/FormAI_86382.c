//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int main() {
    int red = 1, yellow = 0, green = 0;
    
    while (1) {
        printf("Red light is on\n");
        delay(5000);
        printf("Yellow light is on\n");
        delay(1000);
        red = 0;
        yellow = 1;
        green = 0;
        printf("Green light is on\n");
        delay(5000);
        printf("Yellow light is on\n");
        delay(1000);
        red = 0;
        yellow = 0;
        green = 1;
        printf("Yellow light is on\n");
        delay(1000);
        red = 1;
        yellow = 0;
        green = 0;
    }

    return 0;
}