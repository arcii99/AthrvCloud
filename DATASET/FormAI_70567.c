//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef struct {
    int id;
    int currentFloor;
    int targetFloor;
    int isMoving;
} Elevator;

typedef struct {
    int id;
    int currentFloor;
} Request;

int main() {
    Elevator elevators[NUM_ELEVATORS];
    Request requests[NUM_FLOORS];
    srand(time(0));
    int i;

    // initialize elevators
    for (i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].currentFloor = rand() % NUM_FLOORS;
        elevators[i].targetFloor = elevators[i].currentFloor;
        elevators[i].isMoving = 0;
    }

    // initialize requests
    for (i = 0; i < NUM_FLOORS; i++) {
        requests[i].id = i;
        requests[i].currentFloor = i;
    }

    // loop continuously
    while (1) {
        // check for floor requests
        for (i = 0; i < NUM_FLOORS; i++) {
            if (requests[i].currentFloor == i) {
                printf("Request for floor %d\n", i);
            }
        }

        // move elevators
        for (i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].isMoving) {
                if (elevators[i].currentFloor < elevators[i].targetFloor) {
                    elevators[i].currentFloor++;
                } else if (elevators[i].currentFloor > elevators[i].targetFloor) {
                    elevators[i].currentFloor--;
                } else {
                    elevators[i].isMoving = 0;
                }
            }
        }

        // assign elevators to requests
        for (i = 0; i < NUM_FLOORS; i++) {
            if (requests[i].currentFloor == i) {
                int nearestElevator = -1;
                int minDist = NUM_FLOORS;
                int j;

                for (j = 0; j < NUM_ELEVATORS; j++) {
                    int dist = abs(elevators[j].currentFloor - i);
                    if (!elevators[j].isMoving && dist < minDist) {
                        minDist = dist;
                        nearestElevator = j;
                    }
                }

                if (nearestElevator != -1) {
                    elevators[nearestElevator].targetFloor = i;
                    elevators[nearestElevator].isMoving = 1;
                    printf("Elevator %d assigned to floor %d\n", nearestElevator, i);
                }
            }
        }

        // wait and repeat
        sleep(1);
    }

    return 0;
}