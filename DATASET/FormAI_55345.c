//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEVATORS 4
#define MAX_FLOORS 10

// elevator struct
typedef struct {
    int currentFloor;
    int destinationFloor;
    int passengers;
    int capacity;
} Elevator;

// floor struct
typedef struct {
    int floorNumber;
    int numPassengers;
} Floor;

// function prototypes
void simulate(Elevator[], Floor[]);
void printStatus(Elevator[]);
void generatePassengers(Floor[]);
void updateElevators(Elevator[], Floor[]);

int main() {
    // seed randomizer
    srand((unsigned int) time(NULL));

    // initialize elevators and floors
    Elevator elevators[MAX_ELEVATORS];
    Floor floors[MAX_FLOORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].currentFloor = 1;
        elevators[i].destinationFloor = -1;
        elevators[i].passengers = 0;
        elevators[i].capacity = 10;
    }
    for (int i = 0; i < MAX_FLOORS; i++) {
        floors[i].floorNumber = i + 1;
        floors[i].numPassengers = 0;
    }

    // start simulation
    simulate(elevators, floors);

    return 0;
}

void simulate(Elevator elevators[], Floor floors[]) {
    // simulate incoming passengers and elevator movement for 10 time steps
    for (int t = 1; t <= 10; t++) {
        // generate new passengers for each floor
        generatePassengers(floors);

        // update elevator status
        updateElevators(elevators, floors);

        // print elevator status
        printf("Time Step %d\n", t);
        printStatus(elevators);
    }
}

void printStatus(Elevator elevators[]) {
    // print status for each elevator
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        printf("Elevator %d: Floor %d, Passengers %d\n", i+1, elevators[i].currentFloor, elevators[i].passengers);
    }
}

void generatePassengers(Floor floors[]) {
    // generate random number of passengers for each floor between 0 and 5
    for (int i = 0; i < MAX_FLOORS; i++) {
        floors[i].numPassengers += rand()%6;
    }
}

void updateElevators(Elevator elevators[], Floor floors[]) {
    // loop through each elevator
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        // check if elevator has reached its destination floor
        if (elevators[i].currentFloor == elevators[i].destinationFloor) {
            // drop off passengers
            floors[elevators[i].currentFloor-1].numPassengers += elevators[i].passengers;
            elevators[i].passengers = 0;

            // check if there are passengers waiting on the current floor
            if (floors[elevators[i].currentFloor-1].numPassengers > 0) {
                // pick up passengers
                elevators[i].passengers = floors[elevators[i].currentFloor-1].numPassengers;
                floors[elevators[i].currentFloor-1].numPassengers = 0;

                // choose random destination floor
                elevators[i].destinationFloor = rand()%MAX_FLOORS + 1;
            }
            else {
                // choose random destination floor
                elevators[i].destinationFloor = rand()%MAX_FLOORS + 1;
            }
        }
        else {
            // move elevator towards destination floor
            if (elevators[i].currentFloor < elevators[i].destinationFloor) {
                elevators[i].currentFloor++;
            }
            else {
                elevators[i].currentFloor--;
            }
        }
    }
}