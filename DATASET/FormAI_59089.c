//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

int numPeopleWaiting[MAX_FLOORS] = {0};
int numPeopleInElevator = 0;

bool goingUp = true;
int currentFloor = 1;

// Function prototypes
void printBuildingStatus();
void boardElevator(int floor);
void exitElevator(int floor);
void moveElevator();
bool elevatorFull();
bool isEmptyBuilding();

int main(void) {
    srand(time(NULL));
    int numMoves = 0;
    
    while (!isEmptyBuilding()) { // Loop until no one is waiting or on the elevator
        printf("Current floor: %d\n", currentFloor);
        printBuildingStatus();
        
        if (numMoves > 100) { // No one is getting on or off, so just move the elevator
            goingUp = !goingUp;
            numMoves = 0;
        }
        
        if (goingUp) {
            for (int i = currentFloor+1; i <= MAX_FLOORS; i++) {
                if (numPeopleWaiting[i-1] > 0) { // Someone is waiting to go up at the current floor
                    boardElevator(i);
                }
            }
        } else {
            for (int i = currentFloor-1; i >= 1; i--) {
                if (numPeopleWaiting[i-1] > 0) { // Someone is waiting to go down at the current floor
                    boardElevator(i);
                }
            }
        }
        
        moveElevator();
        numMoves++;
        
        if (numPeopleInElevator > 0) {
            int randFloor = rand() % MAX_FLOORS + 1; // Randomly select a floor for people to exit
            exitElevator(randFloor);
        }
    }
    
    printf("Everyone has reached their destination!\n");
    
    return 0;
}

// Prints the number of people waiting at each floor and the number of people on the elevator
void printBuildingStatus() {
    printf("People waiting on each floor: ");
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("%d ", numPeopleWaiting[i]);
    }
    printf("\n");
    printf("People on elevator: %d\n", numPeopleInElevator);
}

// Attempt to board the elevator from a given floor
void boardElevator(int floor) {
    while (numPeopleInElevator < MAX_PEOPLE && numPeopleWaiting[floor-1] > 0) {
        numPeopleWaiting[floor-1]--;
        numPeopleInElevator++;
    }
}

// Exit the elevator at a given floor
void exitElevator(int floor) {
    while (numPeopleInElevator > 0) {
        numPeopleInElevator--;
    }
}

// Move the elevator up or down one floor
void moveElevator() {
    if (goingUp) {
        currentFloor++;
    } else {
        currentFloor--;
    }
}

// Returns true if the elevator is full
bool elevatorFull() {
    return numPeopleInElevator >= MAX_PEOPLE;
}

// Returns true if there are no people waiting or on the elevator
bool isEmptyBuilding() {
    for (int i = 0; i < MAX_FLOORS; i++) {
        if (numPeopleWaiting[i] > 0) {
            return false;
        }
    }
    
    if (numPeopleInElevator > 0) {
        return false;
    }
    
    return true;
}