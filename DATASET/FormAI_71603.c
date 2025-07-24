//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10
#define LIGHT_INTERVAL 3
#define LIGHT_DURATION 2
#define CAR_PROBABILITY 50

int main() {
    srand(time(NULL)); // Initialize random number generator

    int road[ROAD_LENGTH] = {0}; // Initialize road with all empty slots
    int lightCounter = 0; // Counter for the traffic light
    int carCounter = 0; // Counter for the number of cars that pass through the road
    int lightState = 1; // Traffic light is initially green
    int i;

    while (carCounter < 100) { // Repeat simulation until 100 cars pass through

        // Move cars forward by 1 slot
        for (i = ROAD_LENGTH - 1; i >= 0; i--) {
            if (road[i] == 1) {
                if (i != ROAD_LENGTH - 1) {
                    road[i+1] = 1;
                    road[i] = 0;
                } else {
                    road[i] = 0;
                }
            }
        }

        // Check if a new car enters the road
        if (rand() % 100 < CAR_PROBABILITY) {
            road[0] = 1;
        }

        // Update traffic light state
        if (lightCounter == LIGHT_INTERVAL) {
            lightCounter = 0;
            lightState = (lightState == 1) ? 0 : 1;
        }

        // Stop cars when traffic light is red
        if (lightState == 0) {
            for (i = ROAD_LENGTH - 1; i >= 0; i--) {
                if (road[i] == 1 && i != ROAD_LENGTH - 1) {
                    road[i] = 0;
                    road[i+1] = 1;
                }
            }
        }

        // Increment counters
        lightCounter++;
        if (road[ROAD_LENGTH-1] == 1) { // If the car reaches the end of the road
            road[ROAD_LENGTH-1] = 0;
            carCounter++;
        }

        // Print current road state
        printf("Road: ");
        for (i = 0; i < ROAD_LENGTH; i++) {
            printf("%d ", road[i]);
        }
        printf(" | ");
        if (lightState == 1) {
            printf("Green\n");
        } else {
            printf("Red\n");
        }


        // Wait for 1 second
        sleep(1);
    }

    return 0;
}