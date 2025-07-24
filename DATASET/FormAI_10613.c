//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100
#define MAX_CARS 10
#define MAX_SPEED 5

// Structure to represent a car
typedef struct Car {
    int position;
    int speed;
} Car;

// Function to check if there is a car at a given position on the road
int isCarAtPosition(Car cars[], int numCars, int position) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i].position == position) {
            return 1;
        }
    }
    return 0;
}

// Function to get the next position of a car on the road
int getNextPosition(Car car) {
    return car.position + car.speed;
}

// Function to update the position of a car on the road
void updateCarPosition(Car *car) {
    car->position = getNextPosition(*car);
}

// Function to update the speed of a car based on the speed of the car in front of it
void updateCarSpeed(Car *car, int distanceToNextCar) {
    if (distanceToNextCar <= car->speed) {
        car->speed = distanceToNextCar - 1;
    } else if (car->speed < MAX_SPEED) {
        car->speed++;
    }
}

int main() {
    // Set up random seed
    srand(time(NULL));
    
    // Create an array of cars
    Car road[ROAD_LENGTH];
    int numCars = rand() % MAX_CARS + 1;
    for (int i = 0; i < numCars; i++) {
        road[i].position = rand() % ROAD_LENGTH;
        road[i].speed = rand() % MAX_SPEED + 1;
    }
    
    // Simulate traffic flow for 10 iterations
    for (int i = 1; i <= 10; i++) {
        // Print iteration number
        printf("Iteration %d:\n", i);
        
        // Update speeds of the cars
        for (int j = 0; j < numCars; j++) {
            int distanceToNextCar = ROAD_LENGTH;
            for (int k = 0; k < numCars; k++) {
                if (j != k) {
                    int distance = (road[k].position - road[j].position + ROAD_LENGTH) % ROAD_LENGTH;
                    if (distance < distanceToNextCar) {
                        distanceToNextCar = distance;
                    }
                }
            }
            updateCarSpeed(&road[j], distanceToNextCar);
        }
        
        // Update positions of the cars
        for (int j = 0; j < numCars; j++) {
            updateCarPosition(&road[j]);
        }
        
        // Print the state of the road
        for (int j = 0; j < ROAD_LENGTH; j++) {
            if (isCarAtPosition(road, numCars, j)) {
                printf("C");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    
    return 0;
}