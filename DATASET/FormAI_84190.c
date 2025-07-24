//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int currentFloor;
    bool isMoving;
} Elevator;

void initialize(Elevator *elevator) {
    elevator->currentFloor = 1;
    elevator->isMoving = false;
}

void move(Elevator *elevator, int floor) {
    elevator->isMoving = true;
    int diff = elevator->currentFloor - floor;
    if(diff > 0) {
        for(int i = diff; i > 0; i--) {
            printf("Moving down. Floor %d\n", elevator->currentFloor--);
        }
    } else if(diff < 0) {
        for(int i = diff; i < 0; i++) {
            printf("Moving up. Floor %d\n", elevator->currentFloor++);
        }
    }
    elevator->isMoving = false;
}

int main() {
    Elevator elevator;
    initialize(&elevator);

    printf("Elevator at floor %d\n", elevator.currentFloor);
    move(&elevator, 3);
    printf("Elevator at floor %d\n", elevator.currentFloor);
    move(&elevator, 5);
    printf("Elevator at floor %d\n", elevator.currentFloor);
    move(&elevator, 1);
    printf("Elevator at floor %d\n", elevator.currentFloor);

    return 0;
}