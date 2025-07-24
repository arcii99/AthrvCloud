//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 4

int floors[MAX_FLOORS], elevators[MAX_ELEVATORS];

void startSimulation(int numFloors, int numElevators);
int getNextDestination(int elevatorIndex);
void reportElevators(int numElevators, int time);

int main() {
    const int numFloors = 10;
    const int numElevators = 2;

    startSimulation(numFloors, numElevators);

    return 0;
}

void startSimulation(int numFloors, int numElevators) {
    int i, j, time, minFloor = 1, maxFloor = numFloors;
    for (i = 0; i < numElevators; i++) {
        elevators[i] = minFloor;
    }

    time = 0;
    while (time < 60) { // simulated time = 60 seconds
        for (i = 0; i < numElevators; i++) {
            int currentFloor = elevators[i];
            while (floors[currentFloor-1] != 0 && currentFloor >= minFloor && currentFloor <= maxFloor) { // check if there are people to pick up on the current floor
                int destinationFloor = getNextDestination(i);
                if (floors[currentFloor-1] == destinationFloor) { // arrived at destination floor
                    printf("Elevator %d arrived at floor %d at time %d.\n", i+1, currentFloor, time);
                    floors[currentFloor-1] = 0;
                    elevators[i] = currentFloor;
                    break;
                } else { // move to next floor
                    printf("Elevator %d moving from floor %d to floor %d at time %d.\n", i+1, currentFloor, destinationFloor, time);
                    currentFloor = destinationFloor;
                    elevators[i] = currentFloor;
                }
            }
        }
        reportElevators(numElevators, time);
        time++;
    }
}

int getNextDestination(int elevatorIndex) {
    int i;
    int destinationFloor = elevators[elevatorIndex];
    for (i = 0; i < MAX_FLOORS; i++) {
        if (floors[i] == destinationFloor) { // someone is waiting on this floor
            break;
        }
    }
    if (i == MAX_FLOORS) { // no one is waiting on the current floor
        if (destinationFloor == 1) {
            destinationFloor = MAX_FLOORS;
        } else {
            destinationFloor--;
        }
    } else { // someone is waiting on the current floor
        floors[i] = 0; // they have now entered the elevator
        destinationFloor = i+1;
    }
    return destinationFloor;
}

void reportElevators(int numElevators, int time) {
    int i;
    printf("\n");
    printf("Time: %d\n", time);
    for (i = 0; i < numElevators; i++) {
        printf("Elevator %d current floor: %d\n", i+1, elevators[i]);
    }
    printf("\n");
}