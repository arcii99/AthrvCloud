//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
// A lively traffic light controller example program in C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {

    srand(time(NULL));     // initialize random seed

    int current_state = rand() % 3;    // initialize the traffic light
    int timer = 0;          // initialize the timer

    printf("The traffic light is starting in state %d\n", current_state);

    while (1) {     // infinite loop to simulate real life traffic light controller

        if (current_state == RED && timer >= 5) {    // change from red to green
            current_state = GREEN;
            timer = 0;
            printf("Changing from RED to GREEN\n");
        }
        else if (current_state == YELLOW && timer >= 3) {   // change from yellow to red
            current_state = RED;
            timer = 0;
            printf("Changing from YELLOW to RED\n");
        }
        else if (current_state == GREEN && timer >= 7) {    // change from green to yellow
            current_state = YELLOW;
            timer = 0;
            printf("Changing from GREEN to YELLOW\n");
        }

        switch (current_state) {    // print the current state of traffic light
            case RED:
                printf("RED");
                break;
            case YELLOW:
                printf("YELLOW");
                break;
            case GREEN:
                printf("GREEN");
                break;
        }

        printf(" (%d sec left)\n", current_state == RED ? 5 - timer : 
                                   current_state == YELLOW ? 3 - timer : 
                                   7 - timer);  // print the time left for current state

        timer++;    // increment the timer

        sleep(1);   // wait for 1 second before next iteration
    }

    return 0;
}