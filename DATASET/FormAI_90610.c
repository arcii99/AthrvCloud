//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the simulation
#define ROAD_LENGTH 100     // in meters
#define CAR_LENGTH 5        // in meters
#define SAFE_DISTANCE 10    // in meters
#define MAX_SPEED 60        // in meters per second
#define MAX_TRAFFIC 30      // maximum number of cars on the road
#define SIMULATION_TIME 120 // in seconds
  
int main() {
    srand(time(NULL)); // initialize random number generator with current time
  
    int time, num_cars, speed, distance, i, j;
    int cars[MAX_TRAFFIC];

    // Initialize the cars on the road randomly
    num_cars = rand() % MAX_TRAFFIC;
    for (i = 0; i < num_cars; i++) {
        cars[i] = rand() % ROAD_LENGTH;
    }

    printf("Simulation starting for %d seconds...\n", SIMULATION_TIME);
    for (time = 0; time < SIMULATION_TIME; time++) {
        printf("Time: %d\n", time);

        // Move the cars forward based on their speed
        for (i = 0; i < num_cars; i++) {
            speed = rand() % MAX_SPEED; // randomize speed of car
            distance = speed + cars[i]; // new position is current position plus speed
            if (distance >= ROAD_LENGTH) { // check if car reached end of road
                printf("Car %d reached the end of the road!\n", i);
                num_cars--; // remove car from road
            } else {
                for (j = i+1; j < num_cars; j++) {
                    if (cars[j] - distance <= SAFE_DISTANCE) { // check if another car is too close
                        printf("Car %d must slow down due to Car %d being too close!\n", i, j);
                    }
                    else {
                        cars[i] = distance; // update position of car
                    }
                }
            }
        }
    }
    printf("Simulation complete!\n");
    return 0;
}