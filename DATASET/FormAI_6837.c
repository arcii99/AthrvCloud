//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {
    int state = RED; // initialize the traffic light to red
    int count = 0; // initialize the counter to zero

    while(count < 10) { // loop the traffic light ten times
        switch(state) { // determine the current state of the traffic light
            case RED:
                printf("The traffic light is red.\n");
                printf("Stop!\n");
                state = GREEN; // change to green
                break;
            case YELLOW:
                printf("The traffic light is yellow.\n");
                printf("Slow down.\n");
                state = RED; // change to red
                break;
            case GREEN:
                printf("The traffic light is green.\n");
                printf("Go!\n");
                state = YELLOW; // change to yellow
                break;
        }

        count++; // increment the counter
    }

    return 0; // exit the program
}