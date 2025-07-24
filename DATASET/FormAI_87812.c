//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define MAX_PASSENGERS 10
#define MAX_ELEVATORS 3

pthread_mutex_t lock;

typedef struct {
    int floor;
    bool isGoingUp;
} Request;

typedef struct {
    int id;
    int currentFloor;
    int destinationFloor;
    int numPassengers;
    bool isGoingUp;
    bool inService;
    pthread_t thread;
} Elevator;

Elevator elevators[MAX_ELEVATORS];
int floorRequests[NUM_FLOORS][2] = {{0}};
int numPassengersWaiting = 0;
bool simulationOver = false;

void* handleElevator(void* data) {
    Elevator* elevator = (Elevator*) data;

    while (!simulationOver) {
        if (elevator->inService) {
            // move elevator
            if (elevator->isGoingUp) {
                elevator->currentFloor++;
            } else {
                elevator->currentFloor--;
            }

            // check if elevator reached destination floor
            if (elevator->currentFloor == elevator->destinationFloor) {
                // drop off passengers
                elevator->numPassengers = 0;
                elevator->isGoingUp = !elevator->isGoingUp;
                elevator->inService = false;
                printf("Elevator %d arrived at floor %d\n", elevator->id, elevator->currentFloor);
            }
        } else {
            // check if there are floor requests
            bool foundRequest = false;

            pthread_mutex_lock(&lock);

            for (int i = 0; i < NUM_FLOORS; i++) {
                if (floorRequests[i][0] > 0) {
                    // check if there are passengers waiting that need to be picked up
                    if (elevator->isGoingUp) {
                        if (i >= elevator->currentFloor && i <= elevator->destinationFloor) {
                            foundRequest = true;
                            break;
                        }
                    } else {
                        if (i <= elevator->currentFloor && i >= elevator->destinationFloor) {
                            foundRequest = true;
                            break;
                        }
                    }
                }
            }

            if (!foundRequest) {
                pthread_mutex_unlock(&lock);
                continue;
            }

            // pick up passengers
            elevator->inService = true;
            elevator->destinationFloor = elevator->isGoingUp ? NUM_FLOORS : 1;
            printf("Elevator %d is picking up passengers on floor %d\n", elevator->id, elevator->currentFloor);

            // wait for passengers to board
            while (elevator->numPassengers < MAX_PASSENGERS && floorRequests[elevator->currentFloor][0] > 0) {
                elevator->numPassengers++;
                floorRequests[elevator->currentFloor][0]--;
                numPassengersWaiting--;
            }

            pthread_mutex_unlock(&lock);
        }

        // sleep for 1 second for elevator movement
        sleep(1);
    }

    return NULL;
}

void* handleRequests(void* data) {
    int* numRequests = (int*) data;

    while (*numRequests > 0) {
        // randomly generate new requests
        Request request = {
            .floor = rand() % NUM_FLOORS,
            .isGoingUp = rand() % 2 == 0
        };

        // add request to floor requests
        pthread_mutex_lock(&lock);

        if (request.isGoingUp && request.floor < NUM_FLOORS - 1) {
            floorRequests[request.floor][0]++;
        } else if (!request.isGoingUp && request.floor > 0) {
            floorRequests[request.floor][1]++;
        }

        *numRequests = *numRequests - 1;

        numPassengersWaiting++;

        pthread_mutex_unlock(&lock);

        // sleep for random amount of time before generating new request
        sleep(rand() % 3 + 1);
    }

    simulationOver = true;

    return NULL;
}

int main() {
    // initialize elevators
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i] = (Elevator) {
            .id = i,
            .currentFloor = 1,
            .destinationFloor = 1,
            .numPassengers = 0,
            .isGoingUp = true,
            .inService = false
        };

        pthread_create(&elevators[i].thread, NULL, handleElevator, &elevators[i]);
    }

    // generate requests
    int numRequests = rand() % 50 + 50;

    pthread_t requestThread;
    pthread_create(&requestThread, NULL, handleRequests, &numRequests);

    while (!simulationOver) {
        // print floor requests and elevators status
        printf("\nFloor requests:\n");

        for (int i = NUM_FLOORS - 1; i >= 0; i--) {
            printf("Floor %d requests going up: %d, going down: %d\n", i + 1, floorRequests[i][0], floorRequests[i][1]);
        }

        printf("\nElevator status:\n");

        for (int i = 0; i < MAX_ELEVATORS; i++) {
            Elevator elevator = elevators[i];
            printf("Elevator %d at floor %d, heading to floor %d with %d passengers\n", elevator.id, elevator.currentFloor, elevator.destinationFloor, elevator.numPassengers);
        }

        printf("\n%d passengers waiting\n", numPassengersWaiting);

        // sleep for 1 second before printing again
        sleep(1);
    }

    // join threads
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_join(elevators[i].thread, NULL);
    }

    pthread_join(requestThread, NULL);

    return 0;
}