//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define ROAD_LENGTH 500

// Car struct
typedef struct {
    int position;
    int speed;
} Car;

// Function prototypes
void printRoad(Car[], int);
void updateSpeed(Car[], int);
void updatePosition(Car[], int);
void addCar(Car[], int);

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize cars
    Car cars[MAX_CARS] = {};

    // Add first car
    addCar(cars, 0);

    // Simulation loop
    for (int t = 0; t < 100; t++) {
        // Update speed and position of cars
        updateSpeed(cars, MAX_CARS);
        updatePosition(cars, MAX_CARS);

        // Add new car with probability p
        float p = (float)cars[MAX_CARS-1].position / ROAD_LENGTH;
        if (rand() / (float)RAND_MAX < p) {
            addCar(cars, MAX_CARS-1);
        }

        // Print current state of road
        printRoad(cars, MAX_CARS);
    }

    return 0;
}

// Function to print the current state of the road
void printRoad(Car cars[], int n) {
    char road[ROAD_LENGTH+1];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '-';
    }
    road[ROAD_LENGTH] = '\0';
    for (int i = 0; i < n; i++) {
        int pos = cars[i].position;
        road[pos] = 'o';
    }
    printf("%s\n", road);
}

// Function to update the speed of the cars
void updateSpeed(Car cars[], int n) {
    // Update speed of each car except the first one
    for (int i = 1; i < n; i++) {
        int distance = cars[i].position - cars[i-1].position;
        if (distance > cars[i].speed) {
            cars[i].speed++;
        } else if (distance < cars[i].speed) {
            cars[i].speed--;
        }
        if (cars[i].speed < 0) {
            cars[i].speed = 0;
        }
    }
}

// Function to update the position of the cars
void updatePosition(Car cars[], int n) {
    // Update position of each car
    for (int i = 0; i < n; i++) {
        cars[i].position += cars[i].speed;
        if (cars[i].position >= ROAD_LENGTH) {
            cars[i].position = 0;
            cars[i].speed = 0;
        }
    }
}

// Function to add a new car
void addCar(Car cars[], int n) {
    if (n == MAX_CARS) {
        return;
    }
    cars[n+1].position = cars[n].position - rand() % 50 - 25;
    if (cars[n+1].position < 0) {
        cars[n+1].position += ROAD_LENGTH;
    }
    cars[n+1].speed = rand() % 6 + 5;
}