//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_VELOCITY 5
#define ROAD_LENGTH 20

int main() {
    int road[ROAD_LENGTH] = {0}; // Initialize road with no cars
    int velocities[MAX_CARS] = {0}; // Initialize all car velocities to zero
    int positions[MAX_CARS] = {0}; // Initialize all car positions to zero
    int cars = 0; // Keeps track of current number of cars on the road
    int tick = 0; // Keeps track of simulation time in ticks

    srand(time(NULL)); // Seed random number generator

    // Generate initial traffic
    while (cars < MAX_CARS) {
        int position = rand() % ROAD_LENGTH; // Choose random position on road
        if (road[position] == 0) { // If chosen position is empty
            road[position] = 1; // Place car on road
            positions[cars] = position; // Record car's position
            velocities[cars] = rand() % MAX_VELOCITY + 1; // Set car's random velocity
            cars++; // Increment car count
        }
    }

    // Simulation loop
    while (tick < 100) {
        printf("Tick %d: ", tick);

        // Keep track of original positions and velocities for future use
        int old_positions[MAX_CARS];
        int old_velocities[MAX_CARS];
        for (int i = 0; i < cars; i++) {
            old_positions[i] = positions[i];
            old_velocities[i] = velocities[i];
        }

        // Update car positions
        for (int i = 0; i < cars; i++) {
            positions[i] += velocities[i];
            if (positions[i] >= ROAD_LENGTH) {
                positions[i] = positions[i] - ROAD_LENGTH;
            }
        }

        // Check for collisions
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i] == 1) {
                int count = 0; // Number of cars on current cell
                int first_car = -1; // Index of first car on current cell
                for (int j = 0; j < cars; j++) {
                    if (positions[j] == i) {
                        count++;
                        if (first_car == -1) {
                            first_car = j;
                        }
                    }
                }
                if (count > 1) { // If more than one car on current cell
                    // Calculate new velocities for all cars on current cell
                    for (int j = first_car; j < first_car + count; j++) {
                        int distance = positions[(j + 1) % cars] - positions[j];
                        if (distance < 0) {
                            distance += ROAD_LENGTH;
                        }
                        if (distance <= velocities[j]) {
                            velocities[j] = distance - 1;
                        }
                    }
                }
            }
        }

        // Update car velocities
        for (int i = 0; i < cars; i++) {
            int distance = positions[(i + 1) % cars] - positions[i];
            if (distance < 0) {
                distance += ROAD_LENGTH;
            }
            if (distance <= velocities[i]) {
                velocities[i] = distance - 1;
            } else if (velocities[i] < MAX_VELOCITY) {
                velocities[i]++;
            }
        }

        // Move cars on road
        for (int i = 0; i < ROAD_LENGTH; i++) {
            road[i] = 0; // Clear road
        }
        for (int i = 0; i < cars; i++) {
            road[positions[i]] = 1; // Place car on road
        }

        // Print current traffic conditions
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i] == 1) {
                int car_id = -1;
                for (int j = 0; j < cars; j++) {
                    if (positions[j] == i) {
                        car_id = j;
                        break;
                    }
                }
                printf("%d(%d) ", car_id, old_velocities[car_id]);
            } else {
                printf(". ");
            }
        }
        printf("\n");

        tick++; // Increment simulation time
    }

    return 0;
}