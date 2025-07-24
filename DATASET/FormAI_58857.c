//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 3
#define MAX_CAPACITY 10

int floorRequests[FLOORS];
int elevatorFloors[ELEVATORS];
int elevatorDestinations[ELEVATORS];
int elevatorCapacities[ELEVATORS];

void initializeElevators() {
    for(int i=0; i<ELEVATORS; i++) {
        elevatorFloors[i] = 1;
        elevatorDestinations[i] = -1;
        elevatorCapacities[i] = 0;
    }
}

void addFloorRequest(int floor) {
    floorRequests[floor-1] = 1;
}

int getNextFloor(int elevator) {
    int currFloor = elevatorFloors[elevator];
    int nextFloor = -1;
    int direction = elevatorDestinations[elevator] - currFloor > 0 ? 1 : -1;
    if(direction == 1) {
        for(int i=currFloor+1; i<=FLOORS; i++) {
            if(floorRequests[i-1] == 1) {
                nextFloor = i;
                break;
            }
        }
    } else {
        for(int i=currFloor-1; i>=1; i--) {
            if(floorRequests[i-1] == 1) {
                nextFloor = i;
                break;
            }
        }
    }
    if(nextFloor == -1) {
        elevatorDestinations[elevator] = -1;
    }
    return nextFloor;
}

void moveElevators() {
    for(int i=0; i<ELEVATORS; i++) {
        if(elevatorDestinations[i] == -1) {
            elevatorDestinations[i] = getNextFloor(i);
        }
        if(elevatorDestinations[i] != -1) {
            elevatorFloors[i] += elevatorDestinations[i] - elevatorFloors[i] > 0 ? 1 : -1;
            if(elevatorFloors[i] == elevatorDestinations[i]) {
                floorRequests[elevatorDestinations[i]-1] = 0;
                elevatorDestinations[i] = -1;
            }
        }
    }
}

void addPassengerToElevator(int elevator, int floor) {
    if(elevatorCapacities[elevator] < MAX_CAPACITY) {
        elevatorCapacities[elevator]++;
        addFloorRequest(floor);
        printf("Passenger added to elevator %d, current capacity: %d\n", elevator+1, elevatorCapacities[elevator]);
    } else {
        printf("Elevator %d is full!\n", elevator+1);
    }
}

void simulateElevator() {
    int numPassengers = rand() % 3 + 1;
    for(int i=0; i<numPassengers; i++) {
        int floor = rand() % FLOORS + 1;
        int elevator = rand() % ELEVATORS;
        addPassengerToElevator(elevator, floor);
    }
    moveElevators();
}

void printElevatorStatus() {
    printf("Current elevator status:\n");
    for(int i=0; i<ELEVATORS; i++) {
        printf("Elevator %d: Floor - %d, Destination - %d, Capacity - %d/%d\n", i+1, elevatorFloors[i], elevatorDestinations[i], elevatorCapacities[i], MAX_CAPACITY);
    }
}

int main() {
    srand(time(NULL));
    initializeElevators();
    for(int i=0; i<10; i++) {
        printf("Simulating elevator...\n");
        simulateElevator();
        printf("\n");
        printElevatorStatus();
        printf("\n");
    }
    return 0;
}