//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_ELEVATORS 3
#define NUM_FLOORS 10

enum ElevatorState {
    ELEVATOR_SHUTDOWN,
    ELEVATOR_READY,
    ELEVATOR_MOVING,
    ELEVATOR_OCCUPIED
};

enum ElevatorDirection {
    ELEVATOR_DIRECTION_UP,
    ELEVATOR_DIRECTION_DOWN,
    ELEVATOR_DIRECTION_NONE
};

typedef struct {
    enum ElevatorState state;
    enum ElevatorDirection direction;
    int currentFloor;
} Elevator;

Elevator elevators[NUM_ELEVATORS];
bool requests[NUM_FLOORS][2];

void initialize() {
    srand(time(NULL));

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].state = rand() % 2 ? ELEVATOR_READY : ELEVATOR_SHUTDOWN;
        elevators[i].direction = rand() % 2 ? ELEVATOR_DIRECTION_UP : ELEVATOR_DIRECTION_DOWN;
        elevators[i].currentFloor = rand() % NUM_FLOORS;
    }

    for (int i = 0; i < NUM_FLOORS; i++) {
        requests[i][0] = requests[i][1] = false;
    }
}

void updateElevator(Elevator *elevator) {
    switch (elevator->state) {
        case ELEVATOR_READY:
            if (requests[elevator->currentFloor][elevator->direction == ELEVATOR_DIRECTION_UP ? 0 : 1]) {
                elevator->state = ELEVATOR_OCCUPIED;
                requests[elevator->currentFloor][elevator->direction == ELEVATOR_DIRECTION_UP ? 0 : 1] = false;
            }
            break;
        case ELEVATOR_MOVING:
            if (elevator->direction == ELEVATOR_DIRECTION_UP) {
                elevator->currentFloor++;
            } else {
                elevator->currentFloor--;
            }

            if (elevator->currentFloor == 0 || elevator->currentFloor == NUM_FLOORS - 1) {
                elevator->direction = elevator->currentFloor == 0 ? ELEVATOR_DIRECTION_UP : ELEVATOR_DIRECTION_DOWN;
            }

            if (requests[elevator->currentFloor][elevator->direction == ELEVATOR_DIRECTION_UP ? 0 : 1]) {
                elevator->state = ELEVATOR_OCCUPIED;
                requests[elevator->currentFloor][elevator->direction == ELEVATOR_DIRECTION_UP ? 0 : 1] = false;
            }
            break;
        case ELEVATOR_OCCUPIED:
            // do nothing
            break;
        case ELEVATOR_SHUTDOWN:
            // do nothing
            break;
    }
}

void printState() {
    printf("Elevator State\n");
    printf("--------------\n");

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: ", i);
        switch (elevators[i].state) {
            case ELEVATOR_READY:
                printf("Ready on floor %d moving %s\n", elevators[i].currentFloor, elevators[i].direction == ELEVATOR_DIRECTION_UP ? "up" : "down");
                break;
            case ELEVATOR_MOVING:
                printf("Moving on floor %d moving %s\n", elevators[i].currentFloor, elevators[i].direction == ELEVATOR_DIRECTION_UP ? "up" : "down");
                break;
            case ELEVATOR_OCCUPIED:
                printf("Occupied on floor %d moving %s\n", elevators[i].currentFloor, elevators[i].direction == ELEVATOR_DIRECTION_UP ? "up" : "down");
                break;
            case ELEVATOR_SHUTDOWN:
                printf("Shutdown\n");
                break;
        }
    }

    printf("\n");

    printf("Request State\n");
    printf("-------------\n");

    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("Floor %d: ", i);
        if (requests[i][0]) {
            printf("Up");
        }
        if (requests[i][1]) {
            printf("Down");
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    initialize();
    printState();

    while (true) {
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].state != ELEVATOR_SHUTDOWN) {
                updateElevator(&elevators[i]);
            }
        }

        printState();
    }

    return 0;
}