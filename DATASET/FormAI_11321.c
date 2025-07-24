//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 4

typedef struct {
    int floor;
    bool direction_up;
} elevator_t;

int main() {
    // Initialize elevators
    elevator_t elevators[ELEVATORS];
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].direction_up = true;
    }

    // Generate random passengers
    srand(time(NULL));
    int passengers[FLOORS][2];
    for (int i = 0; i < FLOORS; i++) {
        int going_up = rand() % 10;
        int going_down = rand() % 10;
        passengers[i][0] = going_up;
        passengers[i][1] = going_down;
    }

    // Elevator simulation loop
    while (true) {
        // Print floor status
        printf("\n");
        for (int i = FLOORS - 1; i >= 0; i--) {
            printf("|%2d: %d u %d d|\n", i, passengers[i][0], passengers[i][1]);
        }

        // Move elevators
        for (int i = 0; i < ELEVATORS; i++) {
            // Check if elevator has arrived at destination
            if (elevators[i].floor == 0 && elevators[i].direction_up == false) {
                elevators[i].direction_up = true;
            } else if (elevators[i].floor == FLOORS - 1 && elevators[i].direction_up == true) {
                elevators[i].direction_up = false;
            }

            // Check if elevator should change direction based on passenger traffic
            if (elevators[i].direction_up && passengers[elevators[i].floor][0] == 0) {
                elevators[i].direction_up = false;
            } else if (!elevators[i].direction_up && passengers[elevators[i].floor][1] == 0) {
                elevators[i].direction_up = true;
            }

            // Move elevator in current direction
            if (elevators[i].direction_up) {
                elevators[i].floor++;
            } else {
                elevators[i].floor--;
            }
        }

        // Load and unload passengers
        for (int i = 0; i < ELEVATORS; i++) {
            int current_floor = elevators[i].floor;
            int passengers_going_up = passengers[current_floor][0];
            int passengers_going_down = passengers[current_floor][1];

            // Unload passengers going up
            if (elevators[i].direction_up) {
                passengers[current_floor][0] = 0;
            }

            // Unload passengers going down
            if (!elevators[i].direction_up) {
                passengers[current_floor][1] = 0;
            }

            // Load passengers going in the current direction
            if (elevators[i].direction_up) {
                int available_space = FLOORS - current_floor - 1;
                if (passengers_going_up <= available_space) {
                    elevators[i].floor += passengers_going_up;
                    passengers[current_floor][0] -= passengers_going_up;
                } else {
                    elevators[i].floor += available_space;
                    passengers[current_floor][0] -= available_space;
                }
            } else {
                int available_space = current_floor;
                if (passengers_going_down <= available_space) {
                    elevators[i].floor -= passengers_going_down;
                    passengers[current_floor][1] -= passengers_going_down;
                } else {
                    elevators[i].floor -= available_space;
                    passengers[current_floor][1] -= available_space;
                }
            }
        }

        // Wait 1 second before continuing simulation
        printf("\n-\n");
        sleep(1);
    }

    return 0;
}