//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>

// Constants for maximum number of floors and elevator capacity
#define MAX_FLOORS 10
#define CAPACITY 10

// Function signatures
void initialize();
void simulate();
void enterElevator();
void exitElevator();
void moveToNextFloor();
void printElevator(int);

// Global variables
int currFloor, destFloor, numPassengers;
int elevator[MAX_FLOORS][CAPACITY];

int main() {
    initialize();
    simulate();
    return 0;
}

// Function to initialize variables
void initialize() {
    currFloor = 1;
    destFloor = 0;
    numPassengers = 0;
    for(int i = 0; i < MAX_FLOORS; i++) {
        for(int j = 0; j < CAPACITY; j++) {
            elevator[i][j] = 0;
        }
    }
}

// Function to simulate elevator behavior
void simulate() {
    while(1) {
        printf("\nCurrently on floor %d\n", currFloor);
        if(destFloor == currFloor) {
            printf("Elevator has reached destination floor %d\n", destFloor);
            exitElevator();
        }
        else if(numPassengers == 0) {
            printf("Elevator is currently empty. Waiting for passengers...\n");
            enterElevator();
        }
        else {
            printf("Elevator is currently on its way to floor %d\n", destFloor);
            moveToNextFloor();
        }
    }
}

// Function for passengers to enter the elevator
void enterElevator() {
    printf("How many passengers would like to enter? ");
    int numEntered;
    scanf("%d", &numEntered);
    if(numEntered > CAPACITY - numPassengers) {
        printf("Sorry, the elevator cannot hold that many passengers.\n");
    }
    else {
        for(int i = 0; i < numEntered; i++) {
            for(int j = 0; j < CAPACITY; j++) {
                if(elevator[currFloor - 1][j] == 0) {
                    elevator[currFloor - 1][j] = 1;
                    numPassengers++;
                    break;
                }
            }
        }
        printf("Passengers have entered the elevator.\n");
        printf("Which floor would you like to go to? ");
        scanf("%d", &destFloor);
        printf("Elevator is now going to floor %d\n", destFloor);
    }
}

// Function for passengers to exit the elevator
void exitElevator() {
    printf("Passengers are now exiting the elevator.\n");
    for(int i = 0; i < CAPACITY; i++) {
        if(elevator[destFloor - 1][i] == 1) {
            elevator[destFloor - 1][i] = 0;
            numPassengers--;
        }
    }
    printElevator(destFloor - 1);
    printf("Elevator is now empty. Waiting for passengers...\n");
    enterElevator();
}

// Function to move the elevator to the next floor
void moveToNextFloor() {
    if(currFloor < destFloor) {
        currFloor++;
    }
    else {
        currFloor--;
    }
    printElevator(currFloor - 1);
}

// Function to print the elevator on a given floor
void printElevator(int floor) {
    printf("\nElevator on floor %d:\n", floor + 1);
    for(int i = 0; i < CAPACITY; i++) {
        if(elevator[floor][i] == 1) {
            printf(" [P]");
        }
        else {
            printf(" [ ]");
        }
    }
    printf("\n");
}