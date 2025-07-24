//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

typedef struct {
    int currentFloor;
    int floorRequests[MAX_FLOORS];
    bool isMoving;
} Elevator;

void requestElevator(Elevator elevators[], int numElevators, int origin) {
    int closestElevator = -1;
    int closestDistance = MAX_FLOORS;
    for (int i = 0; i < numElevators; i++) {
        if (!elevators[i].isMoving) {
            int distance = abs(elevators[i].currentFloor - origin);
            if (distance < closestDistance) {
                closestElevator = i;
                closestDistance = distance;
            }
        }
    }
    if (closestElevator == -1) {
        printf("All elevators are currently busy. Please try again later.\n");
    } else {
        elevators[closestElevator].floorRequests[origin] = 1;
        elevators[closestElevator].isMoving = true;
        printf("Elevator %d is now moving.\n", closestElevator + 1);
    }
}

void moveElevators(Elevator elevators[], int numElevators) {
    for (int i = 0; i < numElevators; i++) {
        if (elevators[i].isMoving) {
            bool shouldStop = elevators[i].floorRequests[elevators[i].currentFloor];
            if (shouldStop) {
                printf("Elevator %d has stopped at Floor %d.\n", i + 1, elevators[i].currentFloor);
                elevators[i].floorRequests[elevators[i].currentFloor] = 0;
                elevators[i].isMoving = false;
            } else {
                if (elevators[i].currentFloor < MAX_FLOORS) {
                    elevators[i].currentFloor++;
                }
                printf("Elevator %d is now on Floor %d.\n", i + 1, elevators[i].currentFloor);
            }
        }
    }
}

int main() {
    Elevator elevators[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].isMoving = false;
        for (int j = 0; j < MAX_FLOORS; j++) {
            elevators[i].floorRequests[j] = 0;
        }
    }

    requestElevator(elevators, MAX_ELEVATORS, 3);
    requestElevator(elevators, MAX_ELEVATORS, 7);

    moveElevators(elevators, MAX_ELEVATORS);
    moveElevators(elevators, MAX_ELEVATORS);

    requestElevator(elevators, MAX_ELEVATORS, 1);

    moveElevators(elevators, MAX_ELEVATORS);
    moveElevators(elevators, MAX_ELEVATORS);

    return 0;
}