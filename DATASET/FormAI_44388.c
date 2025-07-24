//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

//Struct definition for the elevator object
typedef struct Elevator {
    int currentFloor;
    int direction; //0: stationary, 1: up, -1: down
    int capacity;
    int numPassengers;
} Elevator;

//Function to initialize the elevator object
void initializeElevator(Elevator *elevator, int capacity) {
    elevator->currentFloor = 1;
    elevator->direction = 0;
    elevator->capacity = capacity;
    elevator->numPassengers = 0;
}

//Function to move the elevator to a given floor
void moveElevator(Elevator *elevator, int floor) {
    if (floor > elevator->currentFloor) {
        elevator->direction = 1;
    } else if (floor < elevator->currentFloor) {
        elevator->direction = -1;
    }
    printf("Elevator moving ");
    if (elevator->direction == 1) {
        printf("up");
    } else if (elevator->direction == -1) {
        printf("down");
    } else {
        printf("nowhere");
    }
    printf(" to floor %d\n", floor);
    elevator->currentFloor = floor;
}

//Function to add passengers to the elevator
void addPassengers(Elevator *elevator, int numPassengers) {
    if (elevator->numPassengers + numPassengers > elevator->capacity) {
        printf("Sorry, the elevator cannot fit %d more passengers.\n", numPassengers);
        return;
    }
    printf("Adding %d passengers to the elevator.\n", numPassengers);
    elevator->numPassengers += numPassengers;
}

//Function to remove passengers from the elevator
void removePassengers(Elevator *elevator, int numPassengers) {
    if (elevator->numPassengers - numPassengers < 0) {
        printf("There are not enough passengers in the elevator to remove %d.\n", numPassengers);
        return;
    }
    printf("Removing %d passengers from the elevator.\n", numPassengers);
    elevator->numPassengers -= numPassengers;
}

int main() {
    Elevator elevator;

    initializeElevator(&elevator, 10);

    //Scenario 1
    moveElevator(&elevator, 5);
    addPassengers(&elevator, 6);
    moveElevator(&elevator, 10);
    removePassengers(&elevator, 3);
    moveElevator(&elevator, 1);

    //Scenario 2
    moveElevator(&elevator, 8);
    addPassengers(&elevator, 5);
    moveElevator(&elevator, 2);
    removePassengers(&elevator, 2);
    moveElevator(&elevator, 7);

    return 0;
}