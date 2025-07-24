//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 50 // length of the road
#define MAX_SPEED 5 // maximum speed of the cars
#define NUM_CARS 10 // number of cars in the simulation
#define MAX_SIMULATION_TIME 20 // maximum time (in seconds) for the simulation

// function to simulate a car moving
int moveCar(int currentPosition, int speed) {
    // move the car
    currentPosition += speed;
    
    // check if the car has left the road
    if (currentPosition > ROAD_LENGTH) {
        currentPosition = -1; // set the car to be off the road
    }
    
    return currentPosition;
}

int main() {
    srand(time(NULL)); // initialize the random number generator with the current time
    
    // create the initial array of car positions
    int carPositions[NUM_CARS];
    for (int i = 0; i < NUM_CARS; i++) {
        carPositions[i] = rand() % (ROAD_LENGTH - 1) + 1; // randomly place the cars on the road
    }

    printf("Initial car positions:\n");
    for (int i = 0; i < NUM_CARS; i++) {
        printf("Car %d: %d\n", i, carPositions[i]);
    }
    printf("\n");

    // simulate the traffic flow for the specified amount of time
    for (int time = 1; time <= MAX_SIMULATION_TIME; time++) {
        printf("Time %d:\n", time);

        // move each car
        for (int i = 0; i < NUM_CARS; i++) {
            // calculate the speed of the car based on the distance to the next car
            int distanceToNextCar = ROAD_LENGTH; // initialize to the maximum distance
            for (int j = 0; j < NUM_CARS; j++) {
                if (i != j) { // don't compare a car to itself
                    int distance = carPositions[j] - carPositions[i];
                    if (distance > 0 && distance < distanceToNextCar) {
                        distanceToNextCar = distance;
                    }
                }
            }
            int speed = distanceToNextCar - 1; // subtract 1 to leave a gap between the cars
            if (speed > MAX_SPEED) { // make sure the car doesn't exceed the maximum speed
                speed = MAX_SPEED;
            }

            // move the car and print its new position
            int newPosition = moveCar(carPositions[i], speed);
            printf("Car %d:\t%d -> %d (speed = %d)\n", i, carPositions[i], newPosition, speed);
            carPositions[i] = newPosition;
        }

        printf("\n");
    }

    return 0;
}