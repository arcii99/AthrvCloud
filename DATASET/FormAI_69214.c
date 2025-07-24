//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10   //Number of Floors
#define ELEVATORS 3 //Number of Elevators

//Elevator Structure
typedef struct Elevator {
    int id;             //Elevator Id
    int currentFloor;   //Current Floor
    int destination;    //Final Destination
    bool isMoving;      //True if Elevator is moving
    bool isAvailable;   //True if Elevator is available
} Elevator;

// Global Variable for Elevators
Elevator elevators[ELEVATORS];

//Function to initialize Elevator at the Ground Floor
void initElevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].id = i + 1;
        elevators[i].currentFloor = 0;
        elevators[i].destination = 0;
        elevators[i].isMoving = false;
        elevators[i].isAvailable = true;
    }
}

//Function to simulate the Elevator Movement
void moveElevator(int elevatorIndex) {
    Elevator* elevator = &elevators[elevatorIndex];

    // Elevator has reached the Destination Floor
    if (elevator->currentFloor == elevator->destination) {
        printf("Elevator %d has reached its destination of floor %d\n", elevator->id, elevator->destination);
        elevator->isMoving = false;
        elevator->isAvailable = true;
    }
    else {
        // Elevator is moving up
        if (elevator->currentFloor < elevator->destination) {
            printf("Elevator %d is moving up to floor %d\n", elevator->id, elevator->currentFloor + 1);
            elevator->currentFloor++;
        }
        // Elevator is moving down
        else if (elevator->currentFloor > elevator->destination) {
            printf("Elevator %d is moving down to floor %d\n", elevator->id, elevator->currentFloor -1);
            elevator->currentFloor--;
        }

        elevator->isMoving = true;
        elevator->isAvailable = false;
    }
}

int main() {
    initElevators();
    srand(time(0));

    //Simulate Multiple Requests
    for (int i = 0; i < 5; i++) {
        int sourceFloor = rand() % FLOORS;
        int destinationFloor = rand() % FLOORS;

        //Make sure Source Floor and Destination Floor are not the same
        while (sourceFloor == destinationFloor) {
            destinationFloor = rand() % FLOORS;
        }

        printf("Request received to go from floor %d to floor %d\n", sourceFloor, destinationFloor);

        int elevatorIndex = -1;
        int minDistance = FLOORS + 1;

        //Check the Availability of Elevators
        for (int j = 0; j < ELEVATORS; j++) {
            Elevator* elevator = &elevators[j];
            
            //Elevator is Available and is Closer to the Source Floor than Others
            if (elevator->isAvailable && abs(elevator->currentFloor - sourceFloor) < minDistance) {
                minDistance = abs(elevator->currentFloor - sourceFloor);
                elevatorIndex = j;
            }
        }

        //No Elevator Available. Wait...
        if (elevatorIndex == -1) {
            printf("Sorry, all elevators are busy at the moment. Please wait...\n\n");
        }
        else {
            elevators[elevatorIndex].destination = destinationFloor;
            moveElevator(elevatorIndex);
            printf("\n");
        }
    }

    return 0;
}