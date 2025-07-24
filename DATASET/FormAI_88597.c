//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdbool.h>

// Elevator struct to keep track of elevator status
typedef struct {
    int currentFloor;
    bool isGoingUp;
    bool isOpen;
} Elevator;

// Function to print elevator status
void printElevatorStatus(Elevator elevator) {
    printf("Current floor: %d\n", elevator.currentFloor);
    printf("Direction: %s\n", elevator.isGoingUp ? "up" : "down");
    printf("Door status: %s\n", elevator.isOpen ? "open" : "closed");
}

// Function to simulate elevator movement
void moveElevator(Elevator *elevator, int destination) {
    while (elevator->currentFloor != destination) {
        if (elevator->currentFloor < destination) {
            printf("Moving up...\n");
            elevator->currentFloor++;
            elevator->isGoingUp = true;
        } else {
            printf("Moving down...\n");
            elevator->currentFloor--;
            elevator->isGoingUp = false;
        }
        printf("Current floor: %d\n", elevator->currentFloor);
    }
    printf("Arrived at floor %d\n", destination);
}

int main() {
    Elevator elevator = {1, true, true};
    printElevatorStatus(elevator);

    // Move the elevator to floor 5
    printf("\nMoving elevator to floor 5...\n");
    moveElevator(&elevator, 5);
    printf("Opening door...\n");
    elevator.isOpen = true;
    printElevatorStatus(elevator);

    // Move the elevator to floor 3
    printf("\nMoving elevator to floor 3...\n");
    moveElevator(&elevator, 3);
    printf("Opening door...\n");
    elevator.isOpen = true;
    printElevatorStatus(elevator);

    return 0;
}