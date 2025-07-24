//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

/* Function to print the current state of traffic lights */
void print_traffic_lights(int state) {
    switch(state) {
        case GREEN:
            printf("--------------------\n");
            printf("|      GREEN       |\n");
            printf("--------------------\n\n");
            break;
        case YELLOW:
            printf("---------------------\n");
            printf("|      YELLOW       |\n");
            printf("---------------------\n\n");
            break;
        case RED:
            printf("--------------------\n");
            printf("|      RED         |\n");
            printf("--------------------\n\n");
            break;
        default:
            printf("Invalid state\n");
    }
}

int main() {
    int state = GREEN;  // start with green light
    int counter = 0;    // counter to keep track of seconds
    int duration = 10;  // duration of each light state in seconds
    srand(time(NULL));  // seed random number generator

    while(1) {  // loop forever
        print_traffic_lights(state);  // print current state of traffic lights
        sleep(1);  // sleep for 1 second

        counter++;  // increment counter
        if(counter == duration) {
            counter = 0;  // reset counter

            switch(state) {
                case GREEN:
                    state = YELLOW;  // switch to yellow light
                    break;
                case YELLOW:
                    state = RED;  // switch to red light
                    break;
                case RED:
                    state = GREEN;  // switch to green light
                    duration = rand() % 10 + 10;  // random duration between 10 and 20 seconds
                    break;
                default:
                    printf("Invalid state\n");
            }
        }
    }

    return 0;
}