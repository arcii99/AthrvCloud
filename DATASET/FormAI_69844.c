//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

// State struct for each traffic light
typedef struct {
    int state;
    int duration;
} TrafficLightState;

// Array of traffic light state structs
TrafficLightState trafficLights[] = {
    {RED, 10},
    {GREEN, 10},
    {YELLOW, 3},
    {RED, 10}
};

// Index of current traffic light
int currentLight = 0;

// Handler for SIGALRM signal to advance to next traffic light
void sigalarm_handler(int sig) {
    currentLight = (currentLight + 1) % 4;
    alarm(trafficLights[currentLight].duration);
}

int main() {
    // Set up alarm signal handler
    struct sigaction sa;
    sa.sa_handler = &sigalarm_handler;
    sigaction(SIGALRM, &sa, NULL);

    // Start with first traffic light
    alarm(trafficLights[currentLight].duration);

    // Loop to manage traffic lights
    while (true) {
        // Check current state and sleep for appropriate duration
        if (trafficLights[currentLight].state == GREEN) {
            printf("Green light at traffic light %d\n", currentLight);
            sleep(trafficLights[currentLight].duration);
        } else if (trafficLights[currentLight].state == YELLOW) {
            printf("Yellow light at traffic light %d\n", currentLight);
            sleep(trafficLights[currentLight].duration);
        } else if (trafficLights[currentLight].state == RED) {
            printf("Red light at traffic light %d\n", currentLight);
            sleep(trafficLights[currentLight].duration);
        }
    }

    return 0;
}