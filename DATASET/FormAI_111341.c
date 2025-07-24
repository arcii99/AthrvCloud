//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_OF_FLOORS 5
#define CAPACITY 10

typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN
} ElevatorState;

typedef struct {
    int currentFloor;
    int destinationFloor;
    ElevatorState state;
    int passengers;
} Elevator;

void initialize(Elevator* elevator) {
    elevator->currentFloor = 1;
    elevator->destinationFloor = 1;
    elevator->state = IDLE;
    elevator->passengers = 0;
}

void move(Elevator* elevator) {
    if (elevator->state == MOVING_UP) {
        elevator->currentFloor++;
    } else if (elevator->state == MOVING_DOWN) {
        elevator->currentFloor--;
    }
    printf("Elevator moved to floor %d.\n", elevator->currentFloor);
}

bool shouldStop(Elevator* elevator, bool* floors) {
    if (elevator->state == MOVING_UP) {
        for (int i = elevator->currentFloor + 1; i <= NUM_OF_FLOORS; i++) {
            if (floors[i]) {
                return true;
            }
        }
    } else if (elevator->state == MOVING_DOWN) {
        for (int i = elevator->currentFloor - 1; i >= 1; i--) {
            if (floors[i]) {
                return true;
            }
        }
    }
    return false;
}

void openDoors(Elevator* elevator, bool* floors) {
    printf("Doors open on floor %d.\n", elevator->currentFloor);
    elevator->destinationFloor = elevator->currentFloor;
    if (floors[elevator->currentFloor]) {
        elevator->passengers++;
        floors[elevator->currentFloor] = false;
    }
}

void closeDoors(Elevator* elevator) {
    printf("Doors close on floor %d.\n", elevator->currentFloor);
}

void updateState(Elevator* elevator, bool* floors) {
    if (elevator->state == IDLE) {
        if (shouldStop(elevator, floors)) {
            if (elevator->currentFloor < elevator->destinationFloor) {
                elevator->state = MOVING_UP;
            } else if (elevator->currentFloor > elevator->destinationFloor) {
                elevator->state = MOVING_DOWN;
            }
        }
    } else if (elevator->state == MOVING_UP) {
        if (shouldStop(elevator, floors)) {
            openDoors(elevator, floors);
            elevator->state = IDLE;
        } else if (elevator->currentFloor == NUM_OF_FLOORS) {
            elevator->state = MOVING_DOWN;
        } else {
            move(elevator);
        }
    } else if (elevator->state == MOVING_DOWN) {
        if (shouldStop(elevator, floors)) {
            openDoors(elevator, floors);
            elevator->state = IDLE;
        } else if (elevator->currentFloor == 1) {
            elevator->state = MOVING_UP;
        } else {
            move(elevator);
        }
    }
}

int main() {
    Elevator elevator;
    bool floors[NUM_OF_FLOORS + 1] = { false };
    initialize(&elevator);
    srand(time(NULL));

    while (true) {
        printf("\nElevator status:\n");
        printf("  Passengers: %d\n", elevator.passengers);
        printf("  Current Floor: %d\n", elevator.currentFloor);
        printf("  Destination Floor: %d\n", elevator.destinationFloor);
        printf("  State: %d\n", elevator.state);

        if (elevator.passengers < CAPACITY) {
            if (rand() % 2 == 0) {
                int floor = rand() % NUM_OF_FLOORS + 1;
                if (floor != elevator.currentFloor) {
                    floors[floor] = true;
                    printf("Person presses button to go to floor %d.\n", floor);
                }
            }
        }

        updateState(&elevator, floors);

        if (elevator.passengers == 0 && !shouldStop(&elevator, floors)) {
            printf("\nElevator is now idle.\n");
            break;
        }

        printf("\n");
    }

    return 0;
}