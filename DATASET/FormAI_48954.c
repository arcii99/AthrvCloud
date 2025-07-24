//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximum number of cars in the simulation
#define MAX_CARS 1000

// Define maximum number of lanes in the simulation
#define MAX_LANES 5

// Define struct to hold information about a car in the simulation
typedef struct {
    int speed;
    int lane;
    int position; 
} Car;

// Define array of cars in the simulation
Car cars[MAX_CARS];

// Define function to randomly generate a car with a given speed and lane
Car generateCar(int speed, int lane) {
    Car newCar;
    newCar.speed = speed;
    newCar.lane = lane;
    newCar.position = -1;  // This will be set when the car enters the simulation
    return newCar;
}

// Define function to initialize the simulation with a given number of cars
void initializeSimulation(int numCars) {
    srand(time(NULL));  // Seed the random number generator with the current time
    for (int i = 0; i < numCars; i++) {
        // Generate a car with a random speed between 1 and 5 (inclusive) and a random lane between 1 and MAX_LANES
        Car newCar = generateCar(rand() % 5 + 1, rand() % MAX_LANES + 1);  
        cars[i] = newCar;
    }
}

// Define function to simulate the movement of all cars in the simulation for one time step
void simulateStep() {
    for (int i = 0; i < MAX_CARS; i++) {
        // Check if car is on the road
        if (cars[i].position >= 0) {
            // Calculate new position of car based on its speed and lane
            int newPosition = cars[i].position + cars[i].speed;
            // Check if car has left the road
            if (newPosition >= 100) {
                cars[i].position = -1;  // Remove car from the road
            } else {
                // Check if there is another car in front of this car in the same lane
                int distanceToNextCar = 100;  // Initialize to maximum possible value
                for (int j = 0; j < MAX_CARS; j++) {
                    if (cars[j].position >= 0 && cars[j].lane == cars[i].lane && cars[j].position > cars[i].position) {
                        int distance = cars[j].position - cars[i].position;
                        if (distance < distanceToNextCar) {
                            distanceToNextCar = distance;
                        }
                    }
                }
                // Calculate new speed of car based on distance to next car
                if (distanceToNextCar <= cars[i].speed) {
                    cars[i].speed = distanceToNextCar - 1;
                } else if (distanceToNextCar <= 10 && cars[i].speed > 1) {
                    cars[i].speed--;
                } else if (cars[i].speed < 5) {
                    cars[i].speed++;
                }
                // Update position of car based on its new speed
                cars[i].position = newPosition;
            }
        } else {
            // Check if a new car should be added to the road
            if (rand() % 10 == 0) {  // 10% chance of adding a new car
                // Find first empty slot in cars array
                int index = 0;
                while (cars[index].position >= 0) {
                    index++;
                }
                // Generate new car with random speed and lane
                Car newCar = generateCar(rand() % 5 + 1, rand() % MAX_LANES + 1);
                newCar.position = 0;
                cars[index] = newCar;
            }
        }
    }
}

// Define function to print the current state of the simulation
void printSimulation() {
    int road[MAX_LANES][100];  // Array to represent the road
    for (int i = 0; i < MAX_LANES; i++) {
        for (int j = 0; j < 100; j++) {
            road[i][j] = -1;  // Initialize to -1 (empty)
        }
    }
    // Add cars to the road array
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].position >= 0) {
            road[cars[i].lane - 1][cars[i].position] = i;
        }
    }
    // Print road array
    for (int i = 0; i < MAX_LANES; i++) {
        for (int j = 0; j < 100; j++) {
            if (road[i][j] >= 0) {
                printf("%d", road[i][j]);
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Main function to run the simulation
int main() {
    initializeSimulation(50);  // Initialize simulation with 50 cars
    for (int i = 0; i < 100; i++) {  // Run simulation for 100 time steps
        simulateStep();
        printSimulation();
    }
    return 0;
}