//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Elevator states
#define ELEVATOR_IDLE 0
#define ELEVATOR_MOVING_UP 1
#define ELEVATOR_MOVING_DOWN 2

// Number of floors and maximum capacity of elevator
#define NUM_FLOORS 10
#define MAX_CAPACITY 10

// Elevator struct
struct Elevator {
    int current_floor;
    bool going_up;
    bool doors_open;
    int num_people;
};

// Function to initialize elevator
void init_elevator(struct Elevator* elevator) {
    elevator->current_floor = 1;
    elevator->going_up = true;
    elevator->doors_open = false;
    elevator->num_people = 0;
}

// Function to move elevator up or down one floor
void move_elevator(struct Elevator* elevator) {
    if (elevator->going_up) {
        elevator->current_floor++;
    } else {
        elevator->current_floor--;
    }
}

// Function to check if elevator is at top or bottom floor
bool at_extreme_floor(struct Elevator* elevator) {
    if (elevator->current_floor == 1 || elevator->current_floor == NUM_FLOORS) {
        return true;
    } else {
        return false;
    }
}

// Function to open or close elevator doors
void toggle_doors(struct Elevator* elevator) {
    elevator->doors_open = !elevator->doors_open;
}

// Function to add person to elevator
void add_person(struct Elevator* elevator) {
    if (elevator->num_people < MAX_CAPACITY) {
        elevator->num_people++;
    }
}

// Function to remove person from elevator
void remove_person(struct Elevator* elevator) {
    if (elevator->num_people > 0) {
        elevator->num_people--;
    }
}

int main() {
    // Initialize elevator
    struct Elevator elevator;
    init_elevator(&elevator);

    // Elevator starts at the first floor and starts moving up
    int state = ELEVATOR_MOVING_UP;

    // Simulation loop
    while (true) {
        // Print current floor and elevator status
        printf("Current floor: %d\n", elevator.current_floor);
        if (elevator.doors_open) {
            printf("Doors are open\n");
        } else {
            printf("Doors are closed\n");
        }
        printf("Number of people: %d\n", elevator.num_people);

        // Switch elevator state based on current state
        switch (state) {
            case ELEVATOR_IDLE:
                toggle_doors(&elevator);
                state = elevator.going_up ? ELEVATOR_MOVING_UP : ELEVATOR_MOVING_DOWN;
                break;
            case ELEVATOR_MOVING_UP:
                move_elevator(&elevator);
                if (at_extreme_floor(&elevator)) {
                    elevator.going_up = false;
                    state = ELEVATOR_IDLE;
                }
                break;
            case ELEVATOR_MOVING_DOWN:
                move_elevator(&elevator);
                if (at_extreme_floor(&elevator)) {
                    elevator.going_up = true;
                    state = ELEVATOR_IDLE;
                }
                break;
        }

        // Add or remove person from elevator at random
        if (rand() % 2 == 0) {
            add_person(&elevator);
        } else {
            remove_person(&elevator);
        }

        // Wait for a second before printing next elevator status
        sleep(1);
    }

    return 0;
}