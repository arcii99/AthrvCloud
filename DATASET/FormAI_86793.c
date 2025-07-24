//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 5

/* Define elevator struct */
typedef struct {
    int currentFloor;
    int destinationFloor;
    int passengers;
} Elevator;

/* Define floor struct */
typedef struct {
    int totalPassengers;
} Floor;

/* Function declaration */
void moveElevator(Elevator *elevator, int targetFloor);
void printElevatorStatus(Elevator *elevator, int id);

int main(void) {
    /* Initialize floors */
    Floor floors[NUM_FLOORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        floors[i].totalPassengers = 0;
    }
    
    /* Initialize elevators */
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].destinationFloor = 0;
        elevators[i].passengers = 0;
    }
    
    /* Main loop */
    while (1) {
        /* Randomly add passengers to each floor */
        for (int i = 0; i < NUM_FLOORS; i++) {
            floors[i].totalPassengers += (rand() % 5);
        }
        
        /* Check each elevator */
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            /* Move elevator to destination floor if necessary */
            if (elevators[i].destinationFloor != elevators[i].currentFloor) {
                moveElevator(&(elevators[i]), elevators[i].destinationFloor);
            }
            
            /* Check if elevator has passengers */
            if (elevators[i].passengers > 0) {
                /* Randomly decide if a passenger will leave */
                if ((rand() % 10) == 0) {
                    elevators[i].passengers--;
                }
            }
            /* Check if elevator is empty */
            else {
                /* Check each floor for passengers */
                for (int j = 0; j < NUM_FLOORS; j++) {
                    if (floors[j].totalPassengers > 0) {
                        /* Move elevator to floor with passengers */
                        elevators[i].destinationFloor = j;
                        /* Randomly decide how many passengers to pick up */
                        elevators[i].passengers = (rand() % (floors[j].totalPassengers + 1));
                        floors[j].totalPassengers -= elevators[i].passengers;
                        break;
                    }
                }
            }
            
            /* Print elevator status */
            printElevatorStatus(&(elevators[i]), i);
        }
        
        /* Pause for a moment */
        usleep(500000);
    }
    
    return 0;
}

void moveElevator(Elevator *elevator, int targetFloor) {
    if (elevator->currentFloor < targetFloor) {
        printf("Elevator at floor %d going up...\n", elevator->currentFloor);
        elevator->currentFloor++;
    }
    else {
        printf("Elevator at floor %d going down...\n", elevator->currentFloor);
        elevator->currentFloor--;
    }
}

void printElevatorStatus(Elevator *elevator, int id) {
    printf("Elevator %d: At floor %d, going to floor %d with %d passengers.\n", id, elevator->currentFloor, elevator->destinationFloor, elevator->passengers);
}