//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_TIME 60 // Maximum simulation time in seconds
#define MAX_CARS 100 // Maximum number of cars
#define MAX_SPEED 60 // Maximum speed in km/h

// Structures
typedef struct {
    int speed; // Speed in km/h
    int position; // Position in meters
} Car;

// Function prototypes
void printRoad(Car cars[]);
int simulateTraffic(Car cars[]);
void moveCars(Car cars[]);
void addCar(Car cars[]);
void removeCar(Car cars[]);

int main() {
    srand(time(NULL)); // Seed random number generator

    Car cars[MAX_CARS]; // Array to hold cars
    int num_cars = 0; // Number of cars in the array

    // Add some initial cars
    for (int i = 0; i < 10; i++) {
        addCar(cars);
        num_cars++;
    }

    // Run simulation
    int time = 0; // Current simulation time in seconds
    while (time < MAX_TIME && num_cars > 0) {
        printf("Time: %d seconds\n", time);
        printRoad(cars);
        num_cars = simulateTraffic(cars);
        time++;
    }

    return 0;
}

// Print current position of each car on the road
void printRoad(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].speed > 0 && cars[i].position >= 0) {
            printf("Car %d: %d km/h, %d meters\n", i+1, cars[i].speed, cars[i].position);
        }
    }
}

// Simulate one second of traffic
int simulateTraffic(Car cars[]) {
    // Move each car
    moveCars(cars);

    // Add or remove cars randomly
    if (rand() % 5 == 0) {
        addCar(cars);
    } else if (rand() % 5 == 1) {
        removeCar(cars);
    }

    // Count number of cars still on the road
    int num_cars = 0;
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].speed > 0 && cars[i].position >= 0) {
            num_cars++;
        }
    }

    // Return number of cars still on the road
    return num_cars;
}

// Move each car one second
void moveCars(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].speed > 0 && cars[i].position >= 0) {
            // Calculate new position based on speed
            int new_pos = cars[i].position + (cars[i].speed * 1000 / 3600); // Convert speed from km/h to m/s

            // Check for collisions
            int collision = 0;
            for (int j = 0; j < MAX_CARS; j++) {
                if (i != j && cars[j].speed > 0 && cars[j].position >= 0 && cars[i].position < cars[j].position && new_pos >= cars[j].position) {
                    // Collision detected
                    printf("Car %d collided with car %d\n", i+1, j+1);
                    cars[i].speed = 0;
                    cars[j].speed = 0;
                    collision = 1;
                    break;
                }
            }

            // Move car if no collision detected
            if (!collision) {
                cars[i].position = new_pos;
            }
        }
    }
}

// Add a new car to the array
void addCar(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].speed == 0 && cars[i].position < 0) {
            // Found an empty spot in the array, add a new car with random speed
            cars[i].speed = rand() % MAX_SPEED + 1;
            cars[i].position = 0;
            printf("Car %d added to the road\n", i+1);
            break;
        }
    }
}

// Remove a car from the array
void removeCar(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].speed > 0 && cars[i].position >= 0) {
            // Found a car to remove, set speed to 0 and position to -1
            cars[i].speed = 0;
            cars[i].position = -1;
            printf("Car %d removed from the road\n", i+1);
            break;
        }
    }
}