//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>

#define MAX_DELAY 3 // maximum seconds for delay

volatile sig_atomic_t stop_flag = false;

void handle_sigint(int sig) {
    stop_flag = true;
}

int main() {
    // Register SIGINT handler
    struct sigaction sigint_action;
    sigint_action.sa_flags = 0;
    sigint_action.sa_handler = handle_sigint;
    sigemptyset(&sigint_action.sa_mask);
    sigaction(SIGINT, &sigint_action, NULL);

    // Initialize the traffic light state
    enum { RED, GREEN, YELLOW } color = RED;

    // Initialize the random number generator
    srand(time(NULL));

    // Start the traffic light loop
    while (!stop_flag) {
        printf("Traffic Light [ ");
        switch (color) {
        case RED:
            printf("RED");
            break;
        case GREEN:
            printf("GREEN");
            break;
        case YELLOW:
            printf("YELLOW");
            break;
        }
        printf(" ]\n");

        switch (color) {
        case RED:
            // Red light: wait for a random amount of time between 1 and MAX_DELAY seconds
            printf("Red light: waiting...\n");
            sleep(rand() % MAX_DELAY + 1);

            // Switch to green
            printf("Switching to green!\n");
            color = GREEN;
            break;

        case GREEN:
            // Green light: wait for a random amount of time between 1 and MAX_DELAY seconds
            printf("Green light: waiting...\n");
            sleep(rand() % MAX_DELAY + 1);

            // Switch to yellow
            printf("Switching to yellow...\n");
            color = YELLOW;
            break;

        case YELLOW:
            // Yellow light: wait for a fixed amount of time
            printf("Yellow light: waiting...\n");
            sleep(2);

            // Switch to red
            printf("Switching to red!\n");
            color = RED;
            break;
        }
    }

    printf("Stopping traffic light...\n");
    return EXIT_SUCCESS;
}