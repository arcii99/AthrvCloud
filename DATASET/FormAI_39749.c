//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    int green_time;  // time for green light
    int yellow_time; // time for yellow light
    int red_time;    // time for red light
    int timer;       // timer for light change
} traffic_light;

void init_traffic_light(traffic_light *tl) { // initialise traffic light values
    tl->green_time = 10;
    tl->yellow_time = 3;
    tl->red_time = 15;
    tl->timer = 0;
}

void reset_timer(traffic_light *tl) { // reset the timer value
    tl->timer = 0;
}

void switch_to_green(traffic_light *tl) { // switch to green light
    printf("Green light ON\n");
    tl->timer = tl->green_time;
}

void switch_to_yellow(traffic_light *tl) { // switch to yellow light
    printf("Yellow light ON\n");
    tl->timer = tl->yellow_time;
}

void switch_to_red(traffic_light *tl) { // switch to red light
    printf("Red light ON\n");
    tl->timer = tl->red_time;
}

int main() {
    traffic_light tl;
    init_traffic_light(&tl); // initialise traffic light values
    
    // infinite loop for traffic light
    while(1) {
        if(tl.timer == 0) { // if timer is 0, switch to next light
            if(rand() % 2 == 0) { // randomly switch between green and red
                switch_to_green(&tl);
            } else {
                switch_to_red(&tl);
            }
        } else {
            tl.timer--; // decrement timer
            if(tl.timer == tl.yellow_time) { // switch to yellow light when timer is equal to yellow time
                switch_to_yellow(&tl);
            }
        }
        sleep(1); // 1 second delay between each loop
    }
    return 0;
}