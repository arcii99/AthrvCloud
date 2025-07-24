//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate random time delay
int randomDelay(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Define traffic light structure
struct TrafficLight {
    bool red;
    bool yellow;
    bool green;
};

int main() {
    srand(time(NULL)); // Initialize random number generator

    // Create and initialize traffic light
    struct TrafficLight trafficLight = { true, false, false };

    // Loop forever
    while (true) {
        // Print current state of traffic light
        printf("Traffic light state:\n");
        printf("Red: %s\n", trafficLight.red ? "ON" : "OFF");
        printf("Yellow: %s\n", trafficLight.yellow ? "ON" : "OFF");
        printf("Green: %s\n", trafficLight.green ? "ON" : "OFF");

        // Delay for random time
        int delay = randomDelay(1, 5); // Delay for 1-5 seconds
        printf("Delay: %d seconds\n", delay);
        sleep(delay);

        // Change traffic light state based on current state
        if (trafficLight.red) {
            trafficLight.red = false;
            trafficLight.yellow = true;
        } else if (trafficLight.yellow) {
            trafficLight.yellow = false;
            trafficLight.green = true;
        } else if (trafficLight.green) {
            trafficLight.green = false;
            trafficLight.yellow = true;
        } else { // This should never happen
            printf("Error: invalid traffic light state!\n");
            exit(1);
        }
    }

    return 0;
}