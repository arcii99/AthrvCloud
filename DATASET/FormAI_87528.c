//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 80 // Maximum speed of cars on the road
#define MAX_CARS 50 // Maximum number of cars on the road
#define MAX_TIME 60 // Maximum simulation time in seconds

typedef struct {
    int id;
    int speed;
    int position;
} Car;

int main() {
    srand(time(NULL)); // Initialize random number generator
    Car cars[MAX_CARS]; // Create an array for the cars on the road
    int current_time = 0; // Initialize simulation time
    int num_cars = rand() % MAX_CARS + 1; // Randomly generate number of cars

    // Initialize each car's id, speed, and position
    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i + 1;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].position = i * 10;
    }

    // Simulate traffic flow for MAX_TIME seconds
    while (current_time < MAX_TIME) {
        printf("Time: %d seconds\n", current_time);

        // Print each car's speed and position
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d: speed=%d km/h, position=%d meters\n", cars[i].id, cars[i].speed, cars[i].position);
        }

        // Update each car's position
        for (int i = 1; i < num_cars; i++) {
            int distance = cars[i].position - cars[i-1].position; // Calculate distance between current car and car in front of it
            int min_distance = cars[i].speed; // Keep a minimum safe distance based on the car's speed
            if (distance < min_distance) { // If car is too close to car in front of it, slow down
                cars[i].speed = distance;
            }
            cars[i].position += cars[i].speed; // Update car's position based on its speed
        }

        // Randomly generate a new car with a speed and position
        if (rand() % 100 < 10 && num_cars < MAX_CARS) {
            num_cars++;
            cars[num_cars-1].id = num_cars;
            cars[num_cars-1].speed = rand() % MAX_SPEED + 1;
            cars[num_cars-1].position = cars[num_cars-2].position - 50;
        }

        current_time++; // Increment simulation time
    }

    return 0;
}