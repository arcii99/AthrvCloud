//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// define constants
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// define elevator struct
typedef struct {
    int currentFloor;
    int goalFloor;
    int moving;
} Elevator;

// main function
int main() {

    // initialize elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 1;
        elevators[i].goalFloor = 1;
        elevators[i].moving = 0;
    }

    // initialize floor queue for each floor
    int floorQueue[NUM_FLOORS][NUM_ELEVATORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < NUM_ELEVATORS; j++) {
            floorQueue[i][j] = 0;
        }
    }

    // run simulation for 100 ticks
    for (int tick = 1; tick <= 100; tick++) {

        // print current tick
        printf("Tick %d:\n", tick);

        // handle floor requests
        for (int floor = 1; floor <= NUM_FLOORS; floor++) {
            for (int elevator = 0; elevator < NUM_ELEVATORS; elevator++) {
                if (floorQueue[floor-1][elevator] == tick) {
                    printf("Elevator %d is at Floor %d\n", elevator, floor);
                    elevators[elevator].goalFloor = floor;
                }
            }
        }

        // move elevators
        for (int elevator = 0; elevator < NUM_ELEVATORS; elevator++) {
            if (!elevators[elevator].moving && elevators[elevator].currentFloor != elevators[elevator].goalFloor) {
                if (elevators[elevator].currentFloor < elevators[elevator].goalFloor) {
                    elevators[elevator].currentFloor++;
                    printf("Elevator %d is moving up to Floor %d\n", elevator, elevators[elevator].currentFloor);
                } else {
                    elevators[elevator].currentFloor--;
                    printf("Elevator %d is moving down to Floor %d\n", elevator, elevators[elevator].currentFloor);
                }
                elevators[elevator].moving = 1;
            } else if (elevators[elevator].moving && elevators[elevator].currentFloor == elevators[elevator].goalFloor) {
                printf("Elevator %d has arrived at Floor %d\n", elevator, elevators[elevator].goalFloor);
                elevators[elevator].moving = 0;
            }
        }

        // clear floor requests
        for (int floor = 1; floor <= NUM_FLOORS; floor++) {
            for (int elevator = 0; elevator < NUM_ELEVATORS; elevator++) {
                if (floorQueue[floor-1][elevator] == tick) {
                    floorQueue[floor-1][elevator] = 0;
                }
            }
        }

        // generate new floor requests
        if (tick % 5 == 0) {
            int floor = rand() % NUM_FLOORS + 1;
            int elevator = rand() % NUM_ELEVATORS;
            printf("Someone on Floor %d has requested elevator %d\n", floor, elevator);
            if (!elevators[elevator].moving) {
                elevators[elevator].goalFloor = floor;
            } else {
                floorQueue[floor-1][elevator] = tick + 50;
            }
        }

        // print elevator status
        for (int elevator = 0; elevator < NUM_ELEVATORS; elevator++) {
            printf("Elevator %d is at Floor %d and ", elevator, elevators[elevator].currentFloor);
            if (elevators[elevator].moving) {
                printf("is moving\n");
            } else {
                printf("is idle\n");
            }
        }

        // print separator
        printf("----------\n");
    }

    // end program
    return 0;
}