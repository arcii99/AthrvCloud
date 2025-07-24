//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 1
#define NUM_ELEVATORS 3

typedef struct {
    int currentFloor;
    int direction;
    int isMoving;
    int numPassengers;
    int maxPassengers;
} Elevator;

Elevator elevators[NUM_ELEVATORS];
int passengerRequests[MAX_FLOOR];

void initializeElevators() {
    int i;
    for(i=0; i<NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 1;
        elevators[i].direction = 1;
        elevators[i].isMoving = 0;
        elevators[i].numPassengers = 0;
        elevators[i].maxPassengers = 10;
    }
}

void initializePassengers() {
    int i;
    for(i=0; i<MAX_FLOOR; i++) {
        passengerRequests[i] = 0;
    }
}

void printElevatorStatus() {
    int i;
    for(i=0; i<NUM_ELEVATORS; i++) {
        printf("Elevator %d: Floor %d, Direction %d, Moving %d, Passengers %d/%d\n", i+1, elevators[i].currentFloor, elevators[i].direction, elevators[i].isMoving, elevators[i].numPassengers, elevators[i].maxPassengers);
    }
}

void printPassengerRequests() {
    int i;
    for(i=0; i<MAX_FLOOR; i++) {
        printf("Floor %d: %d\n", i+1, passengerRequests[i]);
    }
}

int isElevatorFull(int elevatorNum) {
    Elevator e = elevators[elevatorNum];
    if (e.numPassengers >= e.maxPassengers) {
        return 1;
    }
    return 0;
}

int getElevatorIndex(int floorNum) {
    int i;
    for(i=0; i<NUM_ELEVATORS; i++) {
        Elevator e = elevators[i];
        if (e.isMoving == 0 && e.currentFloor == floorNum) {
            return i;
        }
    }
    return -1; // No available elevators
}

void moveElevator(Elevator* e) {
    if (e->direction == 1) {
        e->currentFloor++;
    } else {
        e->currentFloor--;
    }
}

void processRequests() {
    int i;
    for(i=0; i<MAX_FLOOR; i++) {
        if (passengerRequests[i] > 0) {
            int elevatorIndex = getElevatorIndex(i+1);
            if (elevatorIndex != -1) {
                Elevator* e = &elevators[elevatorIndex];
                if (!isElevatorFull(elevatorIndex)) {
                    e->isMoving = 1;
                    if (e->currentFloor > i+1) {
                        e->direction = -1;
                    } else {
                        e->direction = 1;
                    }
                    while (e->currentFloor != i+1) {
                        moveElevator(e);
                    }
                    // Open doors and let passengers on
                    int passengers = passengerRequests[i];
                    if (e->maxPassengers - e->numPassengers >= passengers) {
                        e->numPassengers += passengers;
                        passengerRequests[i] = 0;
                    } else {
                        e->numPassengers = e->maxPassengers;
                        passengerRequests[i] -= (e->maxPassengers - e->numPassengers);
                    }
                    // Close doors and move to next floor
                    e->isMoving = 0;
                }
            }
        }
    }
}

int main() {
    initializeElevators();
    initializePassengers();

    // Simulate passengers arriving
    passengerRequests[3] = 4;
    passengerRequests[5] = 3;
    passengerRequests[2] = 2;
    passengerRequests[7] = 1;

    printf("Initial status:\n");
    printElevatorStatus();
    printPassengerRequests();

    // Simulate elevator movement and passenger pickup
    processRequests();
    printf("\nAfter one round:\n");
    printElevatorStatus();
    printPassengerRequests();

    return 0;
}