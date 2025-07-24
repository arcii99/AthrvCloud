//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 10 // length of each lane
#define NUM_LANES 3 // number of lanes
#define MAX_SPEED 5 // max speed of each car
#define MIN_DIST 2 // minimum distance between each car
#define NUM_CARS NUM_LANES * LANE_LENGTH / MIN_DIST // number of cars
#define SIMULATION_TIME 30 // simulation time
#define PAUSE_TIME 1000000 // pause time between each step (in microseconds)

int main() {
    // Initialize variables
    int lanes[NUM_LANES][LANE_LENGTH];
    int speeds[NUM_CARS];
    int positions[NUM_CARS];
    int total_cars_passed = 0;
    int step = 0;
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the lanes with all 0's (no cars)
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < LANE_LENGTH; j++) {
            lanes[i][j] = 0;
        }
    }

    // Add cars to the lanes randomly
    for (i = 0; i < NUM_CARS; i++) {
        int lane = rand() % NUM_LANES;
        int position = rand() % LANE_LENGTH;
        if (lanes[lane][position] == 0) {
            lanes[lane][position] = 1;
            speeds[i] = rand() % MAX_SPEED + 1;
            positions[i] = position;
        } else {
            i--;
        }
    }

    // Simulate the traffic flow
    while (step < SIMULATION_TIME) {
        // Print the lanes
        printf("Step %d:\n", step);
        for (i = 0; i < NUM_LANES; i++) {
            for (j = 0; j < LANE_LENGTH; j++) {
                if (lanes[i][j] == 0) {
                    printf("-");
                } else {
                    printf("x");
                }
            }
            printf("\n");
        }
        printf("\n");

        // Move the cars
        for (i = 0; i < NUM_CARS; i++) {
            // Calculate the distance to the next car in the same lane
            int distance_to_next_car = LANE_LENGTH;
            for (j = positions[i] + 1; j <= positions[i] + LANE_LENGTH; j++) {
                if (lanes[i % NUM_LANES][j % LANE_LENGTH] == 1) {
                    distance_to_next_car = (j - positions[i] - 1) % LANE_LENGTH;
                    break;
                }
            }
            // Calculate the new speed of the car
            int new_speed = speeds[i];
            if (distance_to_next_car <= new_speed) {
                new_speed = distance_to_next_car - 1;
            }
            if (new_speed < 0) {
                new_speed = 0;
            }
            // Update the position of the car
            positions[i] = (positions[i] + new_speed) % LANE_LENGTH;
            // Update the speed of the car
            speeds[i] = new_speed;
            // Check if the car has passed the lane
            if (positions[i] == LANE_LENGTH - 1) {
                lanes[i % NUM_LANES][positions[i]] = 0;
                total_cars_passed++;
            } else {
                lanes[i % NUM_LANES][positions[i]] = 1;
            }
        }

        // Pause before the next step
        usleep(PAUSE_TIME);

        // Increment the step counter
        step++;
    }

    // Print the total number of cars passed
    printf("Total Cars Passed: %d\n", total_cars_passed);

    // Exit the program
    return 0;
}