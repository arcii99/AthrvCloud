//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 3

typedef struct {
    int currentFloor;
    int destinationFloor;
    bool inUse;
} Elevator;

void printElevatorStatus(Elevator elevators[]) {
    printf("Elevator Status:\n");
    for(int i = 0; i < ELEVATORS; i++) {
        printf("Elevator %d: ", i+1);
        if(elevators[i].inUse) {
            printf("On floor %d, going to floor %d\n", elevators[i].currentFloor, elevators[i].destinationFloor);
        } else {
            printf("Not in use\n");
        }
    }
}

int getNextFloor(int currentFloor, int destinationFloor) {
    if(currentFloor < destinationFloor) {
        return currentFloor + 1;
    } else {
        return currentFloor - 1;
    }
}

int main() {

    Elevator elevators[ELEVATORS];
    for(int i = 0; i < ELEVATORS; i++) {
        elevators[i].inUse = false;
    }

    srand(time(NULL));

    int passengersWaiting[FLOORS];
    for(int i = 0; i < FLOORS; i++) {
        passengersWaiting[i] = 0;
    }

    int numberOfPassengers = 0;
    int maxNumberOfPassengers = 20;

    while(true) {

        for(int i = 0; i < FLOORS; i++) {
            if(rand() % 100 < 10) {
                passengersWaiting[i] += 1;
                numberOfPassengers += 1;
            }
        }

        printElevatorStatus(elevators);
        printf("Number of Passengers Waiting: %d\n", numberOfPassengers);

        for(int i = 0; i < ELEVATORS; i++) {
            if(elevators[i].inUse) {
                int nextFloor = getNextFloor(elevators[i].currentFloor, elevators[i].destinationFloor);
                printf("Elevator %d moving from floor %d to floor %d\n", i+1, elevators[i].currentFloor, nextFloor);
                elevators[i].currentFloor = nextFloor;

                if(elevators[i].currentFloor == elevators[i].destinationFloor) {
                    elevators[i].inUse = false;
                }
            } else {
                for(int j = 0; j < FLOORS; j++) {
                    if(passengersWaiting[j] > 0) {
                        elevators[i].destinationFloor = j;
                        elevators[i].inUse = true;
                        elevators[i].currentFloor = rand() % FLOORS;
                        passengersWaiting[j] -= 1;
                        numberOfPassengers -= 1;

                        printf("Elevator %d picked up a passenger from floor %d, going to floor %d\n", i+1, elevators[i].currentFloor, elevators[i].destinationFloor);

                        break;
                    }
                }
            }
        }

    }

    return 0;
}