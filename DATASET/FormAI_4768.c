//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_OF_FLOORS 10
#define MAX_OCCUPANTS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    bool isOccupied;
    int currentFloor;
    int destinationFloor;
} Occupant;

typedef struct {
    Occupant occupants[MAX_OCCUPANTS];
    int currentFloor;
    int destinationFloors[NUM_OF_FLOORS];
    int nextStop;
    bool isMovingUp;
} Elevator;

void initializeElevator(Elevator* elevator) {
    for (int i = 0; i < MAX_OCCUPANTS; i++) {
        elevator->occupants[i].isOccupied = false;
        elevator->occupants[i].currentFloor = -1;
        elevator->occupants[i].destinationFloor = -1;
    }
    for (int i = 0; i < NUM_OF_FLOORS; i++) {
        elevator->destinationFloors[i] = 0;
    }
    elevator->currentFloor = 0;
    elevator->nextStop = 0;
    elevator->isMovingUp = true;
}

void addOccupantToElevator(Elevator* elevator, Occupant* occupant) {
    for (int i = 0; i < MAX_OCCUPANTS; i++) {
        if (!elevator->occupants[i].isOccupied) {
            elevator->occupants[i] = *occupant;
            elevator->destinationFloors[elevator->occupants[i].destinationFloor]++;
            break;
        }
    }
}

void removeOccupantFromElevator(Elevator* elevator, Occupant* occupant) {
    for (int i = 0; i < MAX_OCCUPANTS; i++) {
        if (elevator->occupants[i].isOccupied && 
            elevator->occupants[i].currentFloor == occupant->currentFloor && 
            elevator->occupants[i].destinationFloor == occupant->destinationFloor) {
            elevator->occupants[i].isOccupied = false;
            elevator->occupants[i].currentFloor = -1;
            elevator->occupants[i].destinationFloor = -1;
            elevator->destinationFloors[occupant->destinationFloor]--;
            break;
        }
    }
}

void moveElevator(Elevator* elevator) {
    int nextFloor;
    if (elevator->isMovingUp) {
        nextFloor = elevator->currentFloor + 1;
        if (nextFloor == NUM_OF_FLOORS) {
            elevator->isMovingUp = false;
            nextFloor = elevator->currentFloor - 1;
        }
    } else {
        nextFloor = elevator->currentFloor - 1;
        if (nextFloor < 0) {
            elevator->isMovingUp = true;
            nextFloor = elevator->currentFloor + 1;
        }
    }
    if (elevator->destinationFloors[nextFloor] > 0 || nextFloor == elevator->nextStop) {
        elevator->currentFloor = nextFloor;
        printf("Elevator stopped at floor %d\n", elevator->currentFloor);
        for (int i = 0; i < MAX_OCCUPANTS; i++) {
            if (elevator->occupants[i].isOccupied && elevator->occupants[i].destinationFloor == elevator->currentFloor) {
                removeOccupantFromElevator(elevator, &elevator->occupants[i]);
            } else if (!elevator->occupants[i].isOccupied && elevator->occupants[i].currentFloor == elevator->currentFloor) {
                addOccupantToElevator(elevator, &elevator->occupants[i]);
            }
        }
        elevator->nextStop = elevator->currentFloor;
    }
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    Occupant occupants[MAX_OCCUPANTS] = {
        {.isOccupied = true, .currentFloor = 0, .destinationFloor = 4},
        {.isOccupied = true, .currentFloor = 0, .destinationFloor = 9},
        {.isOccupied = true, .currentFloor = 5, .destinationFloor = 0},
        {.isOccupied = true, .currentFloor = 7, .destinationFloor = 2},
        {.isOccupied = true, .currentFloor = 8, .destinationFloor = 1},
        {.isOccupied = true, .currentFloor = 9, .destinationFloor = 4}
    };
    for (int i = 0; i < MAX_OCCUPANTS; i++) {
        addOccupantToElevator(&elevator, &occupants[i]);
    }
    while (true) {
        moveElevator(&elevator);
    }
}