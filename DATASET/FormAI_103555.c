//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 20

// Struct to represent a passenger
typedef struct Passenger {
    int currentFloor;
    int destinationFloor;
    bool isInsideElevator;
} Passenger;

// Struct to represent an elevator
typedef struct Elevator {
    int currentFloor;
    int direction;
    int capacity;
    int occupied;
    bool doorsOpen;
    bool moving;
    Passenger* occupants[MAX_PEOPLE];
} Elevator;

// Function to add a passenger to the elevator
void addOccupant(Elevator* elevator, Passenger* passenger) {
    elevator->occupants[elevator->occupied] = passenger;
    elevator->occupied++;
    passenger->isInsideElevator = true;
}

// Function to remove a passenger from the elevator
void removeOccupant(Elevator* elevator, int index) {
    for (int i = index; i < elevator->occupied - 1; i++) {
        elevator->occupants[i] = elevator->occupants[i+1];
    }
    elevator->occupants[elevator->occupied - 1] = NULL;
    elevator->occupied--;
}

// Function to move the elevator up or down
void moveElevator(Elevator* elevator) {
    elevator->currentFloor += elevator->direction;
    printf("Elevator is now on floor %d\n", elevator->currentFloor);
}

int main(void) {
    srand(time(NULL));
    Elevator elevator = {1, 1, 10, 0, false, false, {NULL}};
    Passenger passengers[MAX_PEOPLE];
    int numPassengers = rand() % MAX_PEOPLE + 1;

    // Generate passengers with random destinations
    for (int i = 0; i < numPassengers; i++) {
        passengers[i].currentFloor = rand() % MAX_FLOORS + 1;
        passengers[i].destinationFloor = rand() % MAX_FLOORS + 1;
        passengers[i].isInsideElevator = false;
    }

    bool stillRunning = true;

    while (stillRunning) {
        // Check if elevator should change direction
        if (elevator.direction == 1 && elevator.currentFloor == MAX_FLOORS) {
            elevator.direction = -1;
        } else if (elevator.direction == -1 && elevator.currentFloor == 1) {
            elevator.direction = 1;
        }

        // Check if elevator should stop at any of the floors
        bool shouldStop = false;
        for (int i = 0; i < numPassengers; i++) {
            if (passengers[i].currentFloor == elevator.currentFloor) {
                addOccupant(&elevator, &passengers[i]);
                printf("Passenger %d entered the elevator on floor %d\n", i+1, elevator.currentFloor);
                shouldStop = true;
            }
            if (passengers[i].destinationFloor == elevator.currentFloor && passengers[i].isInsideElevator) {
                removeOccupant(&elevator, i);
                printf("Passenger %d left the elevator on floor %d\n", i+1, elevator.currentFloor);
                shouldStop = true;
            }
        }
        elevator.doorsOpen = shouldStop;

        // Move the elevator if necessary
        if (!shouldStop) {
            moveElevator(&elevator);
        }

        // Check if all passengers have reached their destinations
        bool allArrived = true;
        for (int i = 0; i < numPassengers; i++) {
            if (!passengers[i].isInsideElevator && passengers[i].destinationFloor != 0) {
                allArrived = false;
            }
        }
        if (allArrived && elevator.occupied == 0) {
            stillRunning = false;
        }
    }

    printf("All passengers have reached their destinations!\n");

    return 0;
}