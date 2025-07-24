//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int timeLeft = 120; // Total simulation time is 2 minutes (120 seconds)
    int amberTime = 5; // Amber lights will last for 5 seconds
    int redTime = 10; // Red lights will last for 10 seconds
    int greenTime = 15; // Green lights will last for 15 seconds 
    int trafficLights[3] = {1,0,0}; // Start with green light on for first traffic light

    srand(time(NULL)); // Seed the random number generator

    while (timeLeft > 0) {
        
        int randomNumber = rand() % 100; // Generate a random number between 0 and 99

        // Determine which traffic light will change based on the random number
        if (randomNumber < 33) { // 33 percent chance to change traffic light 1
            trafficLights[0] = 0; // Turn off current traffic light
            trafficLights[1] = 1; // Turn on next traffic light
        } else if (randomNumber < 66) { // 33 percent chance to change traffic light 2
            trafficLights[1] = 0; // Turn off current traffic light
            trafficLights[2] = 1; // Turn on next traffic light
        } else { // 33 percent chance to change traffic light 3
            trafficLights[2] = 0; // Turn off current traffic light
            trafficLights[0] = 1; // Turn on next traffic light
        }

        // Print current traffic light configuration
        printf("Traffic light 1: ");
        if (trafficLights[0] == 1) {
            printf("Green\n");
        } else {
            printf("Red\n");
        }
        
        printf("Traffic light 2: ");
        if (trafficLights[1] == 1) {
            printf("Green\n");
        } else {
            printf("Red\n");
        }
        
        printf("Traffic light 3: ");
        if (trafficLights[2] == 1) {
            printf("Green\n");
        } else {
            printf("Red\n");
        }

        // Decrease time left by the time for one traffic light cycle
        timeLeft -= amberTime + redTime + greenTime;

        // Wait for amber light to turn on
        printf("Amber light...\n");
        sleep(amberTime);

        // Wait for red light to turn on
        printf("Red light...\n");
        sleep(redTime);

        // Wait for green light to turn on
        printf("Green light...\n");
        sleep(greenTime);

        // Wait for amber light again before changing traffic light
        printf("Amber light...\n");
        sleep(amberTime);
    }

    return 0;
}