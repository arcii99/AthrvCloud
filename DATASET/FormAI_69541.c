//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int numCars = 10; // Number of cars on the road
    int numTicks = 20; // Number of time ticks to simulate
    int trafficFlow[numTicks];
    int i, j, k;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize trafficFlow array with zeros
    for(i=0;i<numTicks;i++) {
        trafficFlow[i] = 0;
    }

    // Simulate each time tick
    for(i=0;i<numTicks;i++) {
        // Determine number of cars that enter the road
        int carsEntering = rand() % numCars;

        // Determine number of cars that exit the road
        int carsExiting = rand() % numCars;

        // Calculate number of cars currently on the road
        int carsOnRoad = 0;
        for(j=0;j<i;j++) {
            carsOnRoad += trafficFlow[j];
        }

        // Subtract exiting cars from cars on road
        carsOnRoad -= carsExiting;

        // Add entering cars to cars on road
        carsOnRoad += carsEntering;

        // Add cars on road to trafficFlow array
        trafficFlow[i] = carsOnRoad;

        // Print out trafficFlow for this time tick
        printf("Time tick %d: %d cars on the road\n", i, trafficFlow[i]);
    }

    return 0;
}