//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

typedef struct {
    int red;
    int green;
    int yellow;
} TrafficLight;

void initTrafficLight(TrafficLight *tl) {
    tl->red = 1;
    tl->green = 0;
    tl->yellow = 0;
}

void printTrafficLight(TrafficLight tl) {
    printf("Red: %d | Green: %d | Yellow: %d\n", tl.red, tl.green, tl.yellow);
}

void setTrafficLight(TrafficLight *tl, int color) {
    switch(color) {
        case RED:
            tl->red = 1;
            tl->green = 0;
            tl->yellow = 0;
            break;
        case GREEN:
            tl->red = 0;
            tl->green = 1;
            tl->yellow = 0;
            break;
        case YELLOW:
            tl->red = 0;
            tl->green = 0;
            tl->yellow = 1;
            break;
    }
}

int main() {
    TrafficLight tl;
    int count = 0;

    initTrafficLight(&tl);

    while(count < 10) {
        printf("Cycle %d:\n", count+1);
        printTrafficLight(tl);

        sleep(1);

        if(count % 3 == 0) {
            setTrafficLight(&tl, GREEN);
        } else if(count % 3 == 1) {
            setTrafficLight(&tl, YELLOW);
        } else {
            setTrafficLight(&tl, RED);
        }

        count++;
    }

    return 0;
}