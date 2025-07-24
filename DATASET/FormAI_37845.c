//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 80
#define MIN_DISTANCE 5

int main() {
    srand(time(NULL));  // Seed the random number generator
    int cars[MAX_CARS];  // Array to store the positions of all cars
    int speeds[MAX_CARS];  // Array to store the speeds of all cars
    int num_cars = 10;  // The number of cars in the simulation
    int distance;  // The distance between two cars
    int i, j;  // Loop counters
    int time = 0;  // The time elapsed
    int max_distance = 0;  // The maximum distance between two cars
    int max_speed = 0;  // The maximum speed of all cars
    
    // Initialize the cars and speeds randomly
    for (i = 0; i < num_cars; i++) {
        cars[i] = rand() % 1000;  // Generate a random position
        speeds[i] = rand() % MAX_SPEED + 1;  // Generate a random speed
        if (speeds[i] > max_speed) {
            max_speed = speeds[i];  // Update the maximum speed if necessary
        }
    }
    
    // Simulate the traffic flow
    while (1) {
        // Check if any cars have collided
        for (i = 0; i < num_cars; i++) {
            for (j = 0; j < num_cars; j++) {
                if (i != j && abs(cars[i] - cars[j]) < MIN_DISTANCE) {
                    printf("Collision occurred at time %d between car %d and car %d\n", time, i, j);
                    return 1;
                }
            }
        }
        
        // Check if all cars have reached the end
        if (cars[num_cars - 1] >= 1000) {
            printf("Simulation complete at time %d\n", time);
            return 0;
        }
        
        // Update the position of each car
        for (i = 0; i < num_cars; i++) {
            distance = cars[(i + 1) % num_cars] - cars[i];
            if (distance < MIN_DISTANCE) {
                // Slow down if the car in front is too close
                speeds[i] = distance - MIN_DISTANCE;
                if (speeds[i] < 0) {
                    speeds[i] = 0;
                }
            } else {
                // Speed up if there is enough space
                if (speeds[i] < max_speed) {
                    speeds[i]++;
                }
            }
            cars[i] += speeds[i];  // Move the car by its speed
            if (cars[i] > max_distance) {
                max_distance = cars[i];  // Update the maximum distance if necessary
            }
        }
        
        // Print the current state of the simulation
        printf("Time: %d\n", time);
        for (i = 0; i < num_cars; i++) {
            printf("Car %d: position=%d speed=%d\n", i, cars[i], speeds[i]);
        }
        printf("Max distance: %d\n", max_distance);
        
        time++;  // Increment the time
    }
}