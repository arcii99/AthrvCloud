//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cyberpunk
/*  Cyberpunk Traffic Light Controller Program  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// define constants for traffic light colors
#define RED 0
#define GREEN 1
#define YELLOW 2

// define constant for number of traffic lights
#define NUM_TRAFFIC_LIGHTS 4

// define constant for duration of each color in seconds
#define RED_DURATION 5
#define GREEN_DURATION 10
#define YELLOW_DURATION 3

/* Function to randomly generate a delay time between specified min and max values */
int randomDelay(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // declare and initialize arrays to hold the current color and time remaining for each traffic light
    int current_colors[NUM_TRAFFIC_LIGHTS] = {GREEN, RED, GREEN, RED};
    int time_remaining[NUM_TRAFFIC_LIGHTS] = {GREEN_DURATION, RED_DURATION, GREEN_DURATION, RED_DURATION};

    // loop indefinitely
    while (true) {
        // update the time remaining for each traffic light
        for (int i = 0; i < NUM_TRAFFIC_LIGHTS; i++) {
            time_remaining[i]--;

            // if the current color is red or yellow and the time remaining is zero, switch to green
            if ((current_colors[i] == RED || current_colors[i] == YELLOW) && time_remaining[i] == 0) {
                current_colors[i] = GREEN;
                time_remaining[i] = GREEN_DURATION;
            }

            // if the current color is green and the time remaining is zero, switch to yellow
            else if (current_colors[i] == GREEN && time_remaining[i] == 0) {
                current_colors[i] = YELLOW;
                time_remaining[i] = YELLOW_DURATION;
            }

            // if the current color is yellow and the time remaining is zero, switch to red
            else if (current_colors[i] == YELLOW && time_remaining[i] == 0) {
                current_colors[i] = RED;
                time_remaining[i] = RED_DURATION;
            }
        }

        // print the current state of the traffic lights
        printf("\n\n\n");

        // print the first traffic light
        printf(" Traffic Light 1\t\t Traffic Light 2\n");
        printf("****************\t\t****************\n\n");
        if (current_colors[0] == GREEN) {
            printf("      \x1b[32m@\x1b[0m\t\t\t      ");
        } else if (current_colors[0] == YELLOW) {
            printf("      \x1b[33m@\x1b[0m\t\t\t      ");
        } else {
            printf("      \x1b[31m@\x1b[0m\t\t\t      ");
        }

        if (current_colors[1] == GREEN) {
            printf("\x1b[32m@\x1b[0m\n");
        } else if (current_colors[1] == YELLOW) {
            printf("\x1b[33m@\x1b[0m\n");
        } else {
            printf("\x1b[31m@\x1b[0m\n");
        }

        // print the second traffic light
        printf(" Traffic Light 3\t\t Traffic Light 4\n");
        printf("****************\t\t****************\n\n");
        if (current_colors[2] == GREEN) {
            printf("      \x1b[32m@\x1b[0m\t\t\t      ");
        } else if (current_colors[2] == YELLOW) {
            printf("      \x1b[33m@\x1b[0m\t\t\t      ");
        } else {
            printf("      \x1b[31m@\x1b[0m\t\t\t      ");
        }

        if (current_colors[3] == GREEN) {
            printf("\x1b[32m@\x1b[0m\n");
        } else if (current_colors[3] == YELLOW) {
            printf("\x1b[33m@\x1b[0m\n");
        } else {
            printf("\x1b[31m@\x1b[0m\n");
        }

        // delay for a random amount of time between 1 and 3 seconds
        int delay = randomDelay(1, 3);
        printf("\n\nNext change in %d seconds...", delay);
        for (int i = 0; i < delay; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
    }

    return 0;
}