//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 120
#define MAX_ACCEL 5

typedef struct {
    int speed;
    int accel;
} Car;

void update_car(Car* car, Car* next_car, int distance_to_next_car) {
    if (next_car != NULL && distance_to_next_car < 10) {
        // Slow down to avoid collision
        car->accel = -MAX_ACCEL;
    } else if (car->speed < MAX_SPEED) {
        // Speed up
        car->accel = MAX_ACCEL;
    } else {
        // Maintain speed
        car->accel = 0;
    }
    
    car->speed += car->accel;
    if (car->speed < 0) {
        car->speed = 0;
    }
}

int main() {
    Car cars[MAX_CARS];
    int distances[MAX_CARS - 1];
    int num_cars = 10;
    srand(time(NULL));
    
    // Initialize cars with random speeds
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % MAX_SPEED;
    }
    
    // Simulate traffic for 60 seconds
    for (int t = 0; t < 60; t++) {
        // Calculate distances between cars
        for (int i = 0; i < num_cars - 1; i++) {
            distances[i] = rand() % 30 + 10;
        }
        
        // Update each car based on its distance to the next car
        for (int i = 0; i < num_cars; i++) {
            Car* next_car = NULL;
            if (i < num_cars - 1) {
                next_car = &cars[i+1];
            }
            update_car(&cars[i], next_car, distances[i]);
        }
        
        // Print out the speed of each car
        printf("Time: %d seconds\n", t);
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d speed: %d km/h\n", i+1, cars[i].speed);
        }
        printf("---------------------\n");
    }
    
    return 0;
}