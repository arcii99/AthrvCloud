//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50    // Maximum cars on the road
#define MAX_SPEED 120  // Maximum speed the cars can travel at
#define MAX_TIME 120   // Maximum amount of time for the simulation

// Function to generate a random integer between min and max
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate the traffic flow
void simulate_traffic_flow(int num_cars, int max_speed, int max_time) {
    int car_positions[num_cars];
    int car_speeds[num_cars];

    // Initialize the car positions and speeds randomly
    for (int i = 0; i < num_cars; i++) {
        car_positions[i] = i * 100;  // Distance between cars = 100 meters
        car_speeds[i] = rand_int(0, max_speed);
    }

    // Print the initial state of the road
    printf("Initial state of the road:\n");
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: Position = %d meters, Speed = %d km/h\n", i, car_positions[i], car_speeds[i]);
    }
    printf("\n");

    // Simulate the traffic flow for the given amount of time
    for (int t = 1; t <= max_time; t++) {
        printf("Time = %d seconds\n", t);

        // Move each car according to its speed
        for (int i = 0; i < num_cars; i++) {
            car_positions[i] += car_speeds[i] / 3.6;  // Convert speed from km/h to m/s
        }

        // Check for collisions
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car_positions[i] == car_positions[j]) {
                    printf("Collision between Car %d and Car %d at Position = %d meters\n", i, j, car_positions[i]);
                }
            }
        }

        // Print the state of the road
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d: Position = %d meters, Speed = %d km/h\n", i, car_positions[i], car_speeds[i]);
        }
        printf("\n");
    }
}

// Main function to run the program
int main() {
    srand(time(NULL));  // Seed the random number generator

    int num_cars = rand_int(10, MAX_CARS);
    int max_speed = rand_int(60, MAX_SPEED);
    int max_time = rand_int(60, MAX_TIME);

    simulate_traffic_flow(num_cars, max_speed, max_time);

    return 0;
}