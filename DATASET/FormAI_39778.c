//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_SPEED 5
#define MAX_DISTANCE 100

// Struct to represent a car in the simulation
typedef struct car {
    int speed;
    int distance;
} Car;

// Function to initialize a car with random speed and distance values
void initCar(Car* c) {
    c->speed = (rand() % MAX_SPEED) + 1;
    c->distance = (rand() % MAX_DISTANCE) + 1;
}

int main() {
    srand(time(NULL));  // Seed random number generator

    Car cars[MAX_CARS];  // Array to hold all the cars in the simulation

    // Initialize all the cars in the simulation
    for (int i = 0; i < MAX_CARS; i++) {
        initCar(&cars[i]);
    }

    // Simulate 10 iterations of the traffic flow
    for (int i = 0; i < 10; i++) {
        printf("\nIteration %d:\n\n", i+1);

        // Print out the current state of all the cars in the simulation
        for (int j = 0; j < MAX_CARS; j++) {
            printf("Car %d: Speed = %d, Distance = %d\n", j+1, cars[j].speed, cars[j].distance);
        }

        // Update the state of all the cars in the simulation
        for (int j = 0; j < MAX_CARS; j++) {
            // Check if this car is too close to the car in front of it
            if (j > 0 && cars[j].distance - cars[j-1].distance <= 2) {
                cars[j].speed = cars[j-1].speed;
            }
            else {
                // Randomly adjust the speed of the car
                int speedChange = (rand() % 3) - 1;
                cars[j].speed += speedChange;

                // Make sure the speed is within the allowed range
                if (cars[j].speed < 1) {
                    cars[j].speed = 1;
                }
                else if (cars[j].speed > MAX_SPEED) {
                    cars[j].speed = MAX_SPEED;
                }
            }

            // Adjust the distance of the car based on its speed
            cars[j].distance += cars[j].speed;

            // Make sure the distance is within the allowed range
            if (cars[j].distance < 1) {
                cars[j].distance = 1;
            }
            else if (cars[j].distance > MAX_DISTANCE) {
                cars[j].distance = MAX_DISTANCE;
            }
        }
    }

    return 0;
}