//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
/*
A Decentralized Elevator Simulation Program Implemented in C

The program simulates a 5-story building with 2 elevators. 
It uses a decentralized approach where each elevator is controlled independently.
The program uses a simple state machine to manage the elevator's operations.

Author: ABC
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the constants
#define NUM_FLOORS 5
#define NUM_ELEVATORS 2

// Define the structure of an elevator
struct Elevator {
    int id;
    int current_floor;
    int target_floor;
    bool is_busy;
};

// Define the state of an elevator
enum ElevatorState {
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    ARRIVED,
};

// Define the main function
int main() {
    // Initialize the elevators
    struct Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i+1;
        elevators[i].current_floor = 1;
        elevators[i].target_floor = 1;
        elevators[i].is_busy = false;
    }

    // Run the simulation loop
    while (true) {
        // Simulate people pressing the elevator buttons on each floor
        int floor_buttons[NUM_FLOORS] = {0};
        for (int i = 0; i < NUM_FLOORS; i++) {
            if (rand() % 10 == 0) {
                floor_buttons[i] = 1;
                printf("Floor %d: Someone pressed the button for the elevator\n", i+1);
            }
        }

        // Simulate each elevator's movement
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].is_busy) {
                // Elevator is moving towards the target floor
                if (elevators[i].current_floor < elevators[i].target_floor) {
                    printf("Elevator %d is moving up\n", i+1);
                    elevators[i].current_floor++;
                } else if (elevators[i].current_floor > elevators[i].target_floor) {
                    printf("Elevator %d is moving down\n", i+1);
                    elevators[i].current_floor--;
                } else {
                    printf("Elevator %d has arrived at floor %d\n", i+1, elevators[i].current_floor);
                    elevators[i].is_busy = false;
                }
            } else {
                // Elevator is idle
                for (int j = 0; j < NUM_FLOORS; j++) {
                    if (floor_buttons[j]) {
                        printf("Elevator %d is going to floor %d\n", i+1, j+1);
                        elevators[i].target_floor = j+1;
                        elevators[i].is_busy = true;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}