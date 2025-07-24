//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define FLOORS 10
#define ELEVATORS 3

// define constants for the different states of an elevator:
#define IDLE 0
#define MOVING_UP 1
#define MOVING_DOWN 2

// elevator struct
struct Elevator {
    int id;
    int floor;
    int state;
    bool doorsOpen;
};

// global variables
struct Elevator elevators[ELEVATORS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *elevatorThread(void *arg) {
    struct Elevator *elevator = (struct Elevator *) arg;
    printf("Elevator %d started on floor %d.\n", elevator->id, elevator->floor);
    while (true) {
        // wait 1 second before performing elevator actions
        usleep(1000000);

        // get the current floor of the elevator
        int currentFloor = elevator->floor;

        // lock the mutex to access the other elevator's states
        pthread_mutex_lock(&mutex);

        // check if the elevator is idle
        if (elevator->state == IDLE) {
            // check if there are any requests on floors above or below the current floor
            int nextFloor = -1;
            for (int i = 1; i <= FLOORS; i++) {
                if (i != currentFloor) {
                    if (elevator->floor < i) {
                        // elevator needs to move up
                        elevator->state = MOVING_UP;
                        nextFloor = i;
                        break;
                    } else if (elevator->floor > i) {
                        // elevator needs to move down
                        elevator->state = MOVING_DOWN;
                        nextFloor = i;
                        break;
                    }
                }
            }
            if (nextFloor != -1) {
                printf("Elevator %d is moving %s to floor %d.\n", elevator->id, elevator->state == MOVING_UP ? "up" : "down", nextFloor);
            }
        } else {
            // check if the elevator has reached the requested floor
            bool reachedFloor = false;
            if (elevator->state == MOVING_UP) {
                elevator->floor++;
                if (elevator->floor == FLOORS) {
                    // reached the top floor, change direction
                    elevator->state = MOVING_DOWN;
                } else {
                    reachedFloor = true;
                }
            } else if (elevator->state == MOVING_DOWN) {
                elevator->floor--;
                if (elevator->floor == 1) {
                    // reached the bottom floor, change direction
                    elevator->state = MOVING_UP;
                } else {
                    reachedFloor = true;
                }
            }
            if (reachedFloor) {
                printf("Elevator %d reached floor %d.\n", elevator->id, elevator->floor);
            } else {
                printf("Elevator %d is moving %s to floor %d.\n", elevator->id, elevator->state == MOVING_UP ? "up" : "down", elevator->floor);
            }
        }

        // unlock the mutex after accessing the other elevator's states
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t elevatorThreads[ELEVATORS];
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].floor = 1;
        elevators[i].state = IDLE;
        elevators[i].doorsOpen = false;
        pthread_create(&elevatorThreads[i], NULL, elevatorThread, &elevators[i]);
    }
    for (int i = 0; i < ELEVATORS; i++) {
        pthread_join(elevatorThreads[i], NULL);
    }
    return 0;
}