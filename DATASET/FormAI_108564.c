//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Constants for elevator simulation
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Structure to represent elevator
typedef struct elevator {
    int curr_floor;
    int direction; // 1 for up, -1 for down
} elevator_t;

// Function to check if any elevator is present on given floor
int elevator_present_on_floor(elevator_t elevators[], int floor) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].curr_floor == floor) {
            return 1;
        }
    }
    return 0;
}

// Function to simulate elevators moving up
void move_up(elevator_t *elevator) {
    elevator->curr_floor += 1;
    printf("Elevator is at floor %d\n", elevator->curr_floor);
}

// Function to simulate elevators moving down
void move_down(elevator_t *elevator) {
    elevator->curr_floor -= 1;
    printf("Elevator is at floor %d\n", elevator->curr_floor);
}

int main() {
    // Initialize all elevators to be at first floor
    elevator_t elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].curr_floor = 1;
        elevators[i].direction = 1;
    }

    // Start elevator simulation loop
    while (1) {
        // Check if any elevator has reached its target floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].curr_floor == 10) {
                elevators[i].direction = -1; // Change direction to down
            } else if (elevators[i].curr_floor == 1) {
                elevators[i].direction = 1; // Change direction to up
            }
        }

        // Move elevators in their respective direction
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].direction == 1) {
                move_up(&elevators[i]);
            } else {
                move_down(&elevators[i]);
            }
        }

        // Randomly spawn passengers on floors
        for (int i = 1; i <= NUM_FLOORS; i++) {
            if (!elevator_present_on_floor(elevators, i)) {
                int spawn_chance = rand() % 10; // 10% chance of spawning passenger
                if (spawn_chance == 0) {
                    printf("Passenger spawned at floor %d\n", i);
                }
            }
        }
    }

    return 0;
}