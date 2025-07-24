//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_SPEED 5
#define MAX_SPACING 10
#define MAX_TIME 60

// Struct for car properties
typedef struct {
    int speed;
    int location;
} Car;

// Function to initialize random values for car speed and location
void initCars(Car cars[]) {
    for(int i = 0; i < MAX_CARS; i++) {
        cars[i].speed = (rand() % MAX_SPEED) + 1;
        cars[i].location = (rand() % MAX_SPACING) + 1;
    }
}

// Function to move cars based on speed and location
void moveCars(Car cars[]) {
    int currentLocation;
    int newLocation;
    for(int i = 0; i < MAX_CARS; i++) {
        currentLocation = cars[i].location;
        newLocation = currentLocation + cars[i].speed;
        if(newLocation > MAX_SPACING) {
            newLocation = MAX_SPACING;
        }
        cars[i].location = newLocation;
    }
}

// Function to print the state of all cars
void printCars(Car cars[]) {
    printf("\nTime: %d\n", MAX_TIME);
    for(int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: Speed %d, Location %d\n", i+1, cars[i].speed, cars[i].location);
    }
}

int main() {
    srand(time(NULL));
    Car cars[MAX_CARS];
    initCars(cars);
    for(int i = 0; i < MAX_TIME; i++) {
        moveCars(cars);
        printCars(cars);
    }
    return 0;
}