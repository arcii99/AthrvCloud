//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

/* Define macros for the traffic light colors */
#define RED "red"
#define GREEN "green"
#define YELLOW "yellow"

/* Define the structure for the traffic light */
typedef struct {
    char color[10];
    int duration;
} TrafficLight;

/* Define the function for changing the traffic light colors */
void change_color(TrafficLight* light) {
    if (strcmp(light->color, RED) == 0) {
        strcpy(light->color, GREEN);
        light->duration = 10;
    } else if (strcmp(light->color, GREEN) == 0) {
        strcpy(light->color, YELLOW);
        light->duration = 3;
    } else if (strcmp(light->color, YELLOW) == 0) {
        strcpy(light->color, RED);
        light->duration = 5;
    }
}

/* Define the function for handling the timer signal */
void handle_signal(int signum) {
    /* Do nothing, just handle the signal */
}

/* Define the main function */
int main() {
    /* Set up the signal handler */
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    /* Initialize the traffic light */
    TrafficLight light;
    strcpy(light.color, RED);
    light.duration = 5;

    while (1) {
        /* Print the current traffic light color */
        printf("Traffic Light: %s\n", light.color);

        /* Start the timer */
        alarm(light.duration);

        /* Wait for the timer signal */
        pause();

        /* Change the traffic light color */
        change_color(&light);
    }

    return 0;
}