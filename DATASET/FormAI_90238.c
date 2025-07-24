//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cryptic
#include<stdio.h>
#include<unistd.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int curr_light = RED;

int main() {
    while(1) {
        switch(curr_light) {
            case GREEN:
                printf("Green light is on. Traffic can pass.\n");
                sleep(10);
                curr_light = YELLOW;
                break;
            case YELLOW:
                printf("Yellow light is on. Traffic should slow down.\n");
                sleep(5);
                curr_light = RED;
                break;
            case RED:
                printf("Red light is on. Traffic should stop.\n");
                sleep(10);
                curr_light = GREEN;
                break;
            default:
                printf("Error: Invalid light state.");
                break;
        }
    }
    return 0;
}