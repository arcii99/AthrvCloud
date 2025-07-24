//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLOORS 10
#define ELEVATORS 3

// Keeps track of the current state of the elevator
typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN
} ElevatorState;

// Represents a single elevator
typedef struct {
    int current_floor;
    ElevatorState state;
} Elevator;

// Represents the state of the entire building
typedef struct {
    Elevator elevators[ELEVATORS];
    bool floor_requests[FLOORS][2]; // 0 for down, 1 for up
} BuildingState;

// Prints out the current state of the building
void print_state(BuildingState* bs) {
    printf("Building state:\n");

    for (int i = FLOORS - 1; i >= 0; i--) {
        printf("Floor %d: ", i);

        if (bs->floor_requests[i][0]) {
            printf("D ");
        } else {
            printf(". ");
        }

        if (bs->floor_requests[i][1]) {
            printf("U ");
        } else {
            printf(". ");
        }

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < ELEVATORS; i++) {
        printf("Elevator %d: %d [", i, bs->elevators[i].current_floor);

        switch (bs->elevators[i].state) {
            case IDLE:
                printf("idle");
                break;
            case MOVING_UP:
                printf("up");
                break;
            case MOVING_DOWN:
                printf("down");
                break;
        }

        printf("]\n");
    }

    printf("\n");
}

// Moves an elevator one floor in the specified direction
void move_elevator(Elevator* el, int direction) {
    el->current_floor += direction;

    if (direction > 0) {
        el->state = MOVING_UP;
    } else {
        el->state = MOVING_DOWN;
    }
}

// Selects the closest elevator to a floor and returns its index, or -1 if no elevator is available
int select_elevator(BuildingState* bs, int floor, int direction) {
    int closest_distance = FLOORS + 1;
    int closest_elevator = -1;

    for (int i = 0; i < ELEVATORS; i++) {
        int distance = abs(bs->elevators[i].current_floor - floor);

        if (bs->elevators[i].state == IDLE || (bs->elevators[i].state == MOVING_UP && direction > 0) || (bs->elevators[i].state == MOVING_DOWN && direction < 0)) {
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_elevator = i;
            }
        }
    }

    return closest_elevator;
}

int main() {
    BuildingState bs = {};
    bs.elevators[0].current_floor = 0;
    bs.elevators[1].current_floor = 3;
    bs.elevators[2].current_floor = 7;

    // Floors requesting elevators
    bs.floor_requests[2][0] = true; // Floor 2 requesting elevator going down
    bs.floor_requests[5][1] = true; // Floor 5 requesting elevator going up

    print_state(&bs);

    // Elevator 0 moves up to floor 2
    move_elevator(&bs.elevators[0], 1);
    move_elevator(&bs.elevators[0], 1);

    // Assign elevator 0 to floor 2 going down
    int elevator_index = select_elevator(&bs, 2, -1);
    bs.floor_requests[2][0] = false;
    bs.elevators[elevator_index].state = IDLE;

    print_state(&bs);

    // Elevator 1 moves down to floor 4
    move_elevator(&bs.elevators[1], -1);
    move_elevator(&bs.elevators[1], -1);
    move_elevator(&bs.elevators[1], -1);

    // Assign elevator 1 to floor 5 going up
    elevator_index = select_elevator(&bs, 5, 1);
    bs.floor_requests[5][1] = false;
    bs.elevators[elevator_index].state = IDLE;

    print_state(&bs);

    return 0;
}