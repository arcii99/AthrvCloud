//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure to hold car information
struct Car {
    int position;
    int speed;
};

// Function to get random speed
int getRandSpeed() {
    return rand() % 40 + 10; // Speed between 10 to 50 km/hr
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int numCars = 20; // Number of cars in our simulation
    int roadLength = 5000; // Length of the road in meters
    int timeStep = 1; // Time step for simulation in seconds
    int timeLimit = 120; // Time limit for simulation in seconds

    // Create an array of cars with random initial positions and speeds
    struct Car cars[numCars];
    int i;
    for(i=0; i<numCars; i++) {
        cars[i].position = rand() % roadLength;
        cars[i].speed = getRandSpeed();
    }

    // Main simulation loop
    int t;
    for(t=0; t<timeLimit; t+=timeStep) {
        // Print current time and positions of all cars
        printf("Time: %d seconds\n", t);
        for(i=0; i<numCars; i++) {
            printf("Car %d: Position: %d meters, Speed: %d km/hr\n", i+1, cars[i].position, cars[i].speed);
        }
        printf("\n");

        // Update position of all cars in this time step
        for(i=0; i<numCars; i++) {
            cars[i].position += cars[i].speed * (float)timeStep / 3600; // Convert speed from km/hr to m/s
        }

        // Check if any two cars have collided
        int j;
        for(i=0; i<numCars; i++) {
            for(j=i+1; j<numCars; j++) {
                if(abs(cars[i].position - cars[j].position) < 10) { // Collision threshold of 10 meters
                    printf("Cars %d and %d have collided!\n", i+1, j+1);
                    return 0; // Simulation stops on first collision
                }
            }
        }
    }

    // Print final time and positions of all cars
    printf("Time: %d seconds\n", t);
    for(i=0; i<numCars; i++) {
        printf("Car %d: Position: %d meters, Speed: %d km/hr\n", i+1, cars[i].position, cars[i].speed);
    }

    return 0;
}