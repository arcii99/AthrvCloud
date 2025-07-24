//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 5
#define NUM_ELEVATORS 2

// define the elevator struct
typedef struct {
    int currentFloor;
    int targetFloor;
    bool direction; // false = down, true = up
    bool moving;
} Elevator;

// initialize all elevators to ground floor
void initElevators(Elevator elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].targetFloor = -1;
        elevators[i].direction = true;
        elevators[i].moving = false;
    }
}

// move an elevator up or down one floor
void moveElevator(Elevator *elevator) {
    if (elevator->direction) {
        elevator->currentFloor++;
    } else {
        elevator->currentFloor--;
    }
}

// check if any elevators are moving
bool areAnyElevatorsMoving(Elevator elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].moving) {
            return true;
        }
    }
    return false;
}

int main() {
    Elevator elevators[NUM_ELEVATORS];
    initElevators(elevators);

    int floorRequests[NUM_FLOORS] = {0};

    // simulate elevator operation for 100 time units
    for (int t = 0; t < 100; t++) {
        // move elevators and handle arrivals
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            Elevator *elevator = &elevators[i];
            if (elevator->moving) {
                moveElevator(elevator);
                if (elevator->currentFloor == elevator->targetFloor) {
                    elevator->moving = false;
                    elevator->targetFloor = -1;
                }
            } else if (elevator->targetFloor >= 0) {
                elevator->moving = true;
            } else if (floorRequests[elevator->currentFloor] > 0) {
                elevator->targetFloor = elevator->currentFloor;
                elevator->moving = true;
                floorRequests[elevator->currentFloor]--;
            }
        }

        // handle floor requests
        for (int f = 0; f < NUM_FLOORS; f++) {
            if (floorRequests[f] > 0 && !areAnyElevatorsMoving(elevators)) {
                // no elevators are currently moving, so move one to this floor
                for (int i = 0; i < NUM_ELEVATORS; i++) {
                    Elevator *elevator = &elevators[i];
                    if (!elevator->moving) {
                        elevator->targetFloor = f;
                        elevator->moving = true;
                        floorRequests[f]--;
                        break;
                    }
                }
            }
        }

        // generate new floor requests randomly
        if (rand() % 10 == 0) {
            int f = rand() % NUM_FLOORS;
            floorRequests[f]++;
            printf("New floor request: floor %d\n", f);
        }

        // print elevator states
        printf("Time unit %d:\n", t);
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            Elevator *elevator = &elevators[i];
            printf("Elevator %d: ", i);
            if (elevator->moving) {
                printf("moving %s from floor %d to floor %d\n", elevator->direction ? "up" : "down", elevator->currentFloor, elevator->targetFloor);
            } else {
                printf("idle at floor %d\n", elevator->currentFloor);
            }
        }
        printf("\n");
    }

    return 0;
}