//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// struct to represent a vehicle
typedef struct {
    int speed;  // in mph
    int position;  // in miles
    bool active;  // whether vehicle is on the road
} Vehicle;

// function to initialize a vehicle with random speed and position
Vehicle initVehicle() {
    Vehicle vehicle;
    vehicle.speed = rand() % 31 + 30;  // random speed between 30-60mph
    vehicle.position = rand() % 11;  // random position on the road
    vehicle.active = true;
    return vehicle;
}

int main() {
    // seed the random number generator
    srand(time(0));

    int numVehicles = 20;  // number of vehicles on the road
    Vehicle vehicles[numVehicles];

    // init vehicles
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i] = initVehicle();
    }

    int timeStep = 1;  // each timestep represents 1 minute
    int gameTime = 120;  // game lasts for 2 hours (120 minutes)

    // main game loop
    for (int t = 0; t < gameTime; t += timeStep) {
        // print the current state of the road
        printf("Time: %d minutes\n", t);
        for (int j = 0; j < numVehicles; j++) {
            if (vehicles[j].active) {  // only print active vehicles
                printf("Vehicle %d: Speed %d mph, Position %d miles\n", j+1, vehicles[j].speed, vehicles[j].position);
            }
        }
        printf("\n");

        // update positions of each vehicle
        for (int k = 0; k < numVehicles; k++) {
            if (vehicles[k].active) {
                vehicles[k].position += vehicles[k].speed / 60 * timeStep;  // update position based on speed
            }
        }

        // check if any collisions occurred
        for (int m = 0; m < numVehicles; m++) {
            if (vehicles[m].active) {
                for (int n = m+1; n < numVehicles; n++) {
                    if (vehicles[n].active) {
                        if (vehicles[m].position == vehicles[n].position) {  // collision occurred
                            printf("Collision occurred at time %d between Vehicle %d and Vehicle %d\n", t, m+1, n+1);
                            vehicles[m].active = false;  // both vehicles become inactive after a collision
                            vehicles[n].active = false;
                        }
                    }
                }
            }
        }
    }

    return 0;
}