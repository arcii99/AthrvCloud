//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOORS 20  // Maximum number of floors
#define MAX_ELEVATORS 5 // Maximum number of elevators

// Enumeration for state of each elevator
typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    ARRIVED,
    OUT_OF_ORDER
} elevator_state_t;

// Structure for each elevator
typedef struct {
    int id;  // Unique id of the elevator
    int current_floor;  // Current floor of the elevator
    int destination_floor;  // Destination floor of the elevator
    elevator_state_t state;  // Current state of the elevator
} elevator_t;

// Function to move an elevator up or down
void move_elevator(elevator_t *elevator) {
    if (elevator->state == MOVING_UP) {
        printf("Elevator %d is moving up from floor %d to floor %d\n", elevator->id, elevator->current_floor, elevator->current_floor + 1);
        elevator->current_floor++;
    } else if (elevator->state == MOVING_DOWN) {
        printf("Elevator %d is moving down from floor %d to floor %d\n", elevator->id, elevator->current_floor, elevator->current_floor - 1);
        elevator->current_floor--;
    }
}

// Function to check if an elevator has arrived at its destination floor
bool elevator_has_arrived(elevator_t *elevator) {
    return (elevator->current_floor == elevator->destination_floor);
}

// Function to simulate the elevator system
void elevator_simulation() {
    // Create an array of elevators
    elevator_t elevators[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = 1;
        elevators[i].destination_floor = 1;
        elevators[i].state = IDLE;
    }

    // Main simulation loop
    while (true) {
        // Generate random elevator requests
        int requested_floor = rand() % MAX_FLOORS + 1;
        int requested_elevator = rand() % MAX_ELEVATORS;
        printf("Request for elevator at floor %d\n", requested_floor);

        // Assign elevator to the request
        elevator_t *elevator = &elevators[requested_elevator];
        elevator->destination_floor = requested_floor;

        // Move the elevator until it arrives at the destination floor
        while (!elevator_has_arrived(elevator)) {
            if (elevator->state == IDLE) {
                if (elevator->current_floor < elevator->destination_floor) {
                    elevator->state = MOVING_UP;
                } else {
                    elevator->state = MOVING_DOWN;
                }
            }

            move_elevator(elevator);

            if (elevator_has_arrived(elevator)) {
                elevator->state = ARRIVED;
                printf("Elevator %d has arrived at floor %d\n", elevator->id, elevator->current_floor);
            }
        }
    }
}

int main() {
    elevator_simulation();
    return 0;
}