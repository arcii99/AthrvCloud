//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

// Define traffic light colors
#define RED 1
#define AMBER 2
#define GREEN 3

// Define initial values for lights
int traffic_light_1 = RED;
int traffic_light_2 = GREEN;

// Define global variable to check for signal from timer
volatile sig_atomic_t sigflag = 0;

// Define signal handler for timer
void handler(int signum) {
    sigflag = 1;
}

// Define function to switch traffic light
void switch_light(int traffic_light) {
    switch (traffic_light) {
        case RED:
            printf("Red light.\n");
            sleep(4);
            break;
        case AMBER:
            printf("Amber light.\n");
            sleep(2);
            break;
        case GREEN:
            printf("Green light.\n");
            sleep(6);
            break;
        default:
            break;
    }
}

int main() {
    // Register signal handler for timer
    signal(SIGALRM, handler);

    // Set up timer to send signal every 10 seconds
    struct itimerval timer;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);

    while (true) {
        // Check for signal from timer
        if (sigflag != 0) {
            sigflag = 0;
            // Switch traffic lights
            if (traffic_light_1 == RED && traffic_light_2 == GREEN) {
                traffic_light_1 = GREEN;
                traffic_light_2 = RED;
            } else if (traffic_light_1 == GREEN && traffic_light_2 == RED) {
                traffic_light_1 = AMBER;
            } else if (traffic_light_1 == AMBER) {
                traffic_light_1 = RED;
                traffic_light_2 = GREEN;
            }
        }
        // Switch traffic lights
        switch_light(traffic_light_1);
        switch_light(traffic_light_2);
    }

    return 0;
}