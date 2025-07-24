//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10 // Total number of floors in the building
#define NUM_ELEVATORS 3 // Total number of elevators in the building

typedef struct {
    int currentFloor; // The current floor the elevator is on
    bool isOccupied; // Whether or not there are passengers in the elevator
} Elevator;

// Initializes all elevators with a current floor of 0 and isOccupied set to false
void initElevators(Elevator elevators[]) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].isOccupied = false;
    }
}

// Prints the current status of all elevators
void printElevatorStatus(Elevator elevators[]) {
    printf("\n\nElevator Status:\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d is currently on floor %d", i, elevators[i].currentFloor);
        if (elevators[i].isOccupied) {
            printf(" and has passengers onboard.\n");
        } else {
            printf(" and is currently empty.\n");
        }
    }
    printf("\n");
}

int main(void) {
    Elevator elevators[NUM_ELEVATORS];
    initElevators(elevators);
    printElevatorStatus(elevators);
    return 0;
}