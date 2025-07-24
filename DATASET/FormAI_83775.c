//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include <stdio.h>

//Define constants
#define NUMBER_OF_FLOORS 10
#define ELEVATOR_MAX_CAPACITY 10

//Define variables
int currentFloor = 1;
int numPassengers = 0;
int elevDirection = 1; //1 represents going up and -1 represents going down
int passengersToFloor[NUMBER_OF_FLOORS] = {0}; //initialize all values to zero

//Function to print elevator status
void printStatus() {
    printf("Current Floor: %d\n", currentFloor);
    printf("Number of Passengers: %d\n", numPassengers);
    printf("Elevator Direction: %s\n", elevDirection == 1 ? "Up" : "Down");
    printf("Passengers to Floor:\n");
    for (int i = 0; i < NUMBER_OF_FLOORS; i++) {
        printf("%d: %d\n", i+1, passengersToFloor[i]);
    }
    printf("\n");
}

//Function to move elevator up one floor
void moveUp() {
    if (currentFloor < NUMBER_OF_FLOORS) {
        currentFloor++;
    } else {
        elevDirection = -1;
        currentFloor--;
    }
}

//Function to move elevator down one floor
void moveDown() {
    if (currentFloor > 1) {
        currentFloor--;
    } else {
        elevDirection = 1;
        currentFloor++;
    }
}

//Function to handle passengers getting on elevator
void getOnElevator(int floorNum, int numPeople) {
    if (numPassengers + numPeople > ELEVATOR_MAX_CAPACITY) {
        printf("Sorry, elevator is full\n");
    } else {
        passengersToFloor[floorNum-1] += numPeople;
        numPassengers += numPeople;
        printf("%d passengers get on the elevator to go to floor %d\n", numPeople, floorNum);
    }
}

//Function to handle passengers getting off elevator
void getOffElevator() {
    if (passengersToFloor[currentFloor-1] > 0) {
        printf("%d passengers get off the elevator on floor %d\n", passengersToFloor[currentFloor-1], currentFloor);
        numPassengers -= passengersToFloor[currentFloor-1];
        passengersToFloor[currentFloor-1] = 0;
    }
}

int main() {
    printStatus();
    getOnElevator(3, 2);
    moveUp();
    printStatus();
    getOnElevator(5, 3);
    moveUp();
    moveUp();
    printStatus();
    getOffElevator();
    moveDown();
    moveDown();
    moveDown();
    printStatus();
    return 0;
}