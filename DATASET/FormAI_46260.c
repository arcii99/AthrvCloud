//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <unistd.h>    //for sleep function

void red_light() {
    printf("Red light on.\n");
    sleep(5);   //wait for 5 seconds
}

void yellow_light() {
    printf("Yellow light on.\n");
    sleep(2);   //wait for 2 seconds
}

void green_light() {
    printf("Green light on.\n");
    sleep(7);   //wait for 7 seconds
}

int main() {
    while(1) {
        red_light();
        yellow_light();
        green_light();
    }
    return 0;
}