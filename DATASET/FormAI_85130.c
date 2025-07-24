//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

#define NUM_FLOORS 10 // number of floors in the building
#define NUM_ELEVATORS 3 // number of elevators in the building
#define MAX_RIDERS 5 // maximum number of riders in an elevator

// Structs for the Elevator and Rider
typedef struct {
    int id; // id of the elevator
    int currentFloor; // current floor of the elevator
    int destinationFloor; // destination floor of the elevator
    int riders[MAX_RIDERS]; // array of rider ids in the elevator
    int numRiders; // number of riders in the elevator
    sem_t capacity; // semaphore to control capacity of the elevator
    sem_t mutex; // semaphore to control the access to the elevator
} Elevator;

typedef struct {
    int id; // id of the rider
    int currentFloor; // current floor of the rider
    int destinationFloor; // destination floor of the rider
    Elevator *elevator; // pointer to the elevator the rider is in
    bool hasArrived; // flag to indicate if the rider has arrived at their destination
} Rider;

// Function Prototypes
void* elevatorFunction(void* elevator);
void* riderFunction(void* rider);

// Global Variables
Elevator elevators[NUM_ELEVATORS]; // array of elevators in the building
Rider riders[MAX_RIDERS * NUM_FLOORS]; // array of all riders in the building
int numRiders = 0; // total number of riders in the building
sem_t riderSemaphore; // semaphore to control access to riders array
sem_t elevatorSemaphore; // semaphore to control access to elevators array

int main(int argc, char** argv) {
    // Initialize the elevator semaphores
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        sem_init(&(elevators[i].capacity), 0, MAX_RIDERS);
        sem_init(&(elevators[i].mutex), 0, 1);
    }

    // Initialize the rider and elevator semaphores
    sem_init(&riderSemaphore, 0, 1);
    sem_init(&elevatorSemaphore, 0, 1);

    // Create threads for each elevator
    pthread_t elevatorThreads[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].currentFloor = 1;
        elevators[i].destinationFloor = 1;
        elevators[i].numRiders = 0;
        pthread_create(&elevatorThreads[i], NULL, elevatorFunction, &elevators[i]);
    }

    // Create threads for each rider
    pthread_t riderThreads[MAX_RIDERS * NUM_FLOORS];
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < MAX_RIDERS; j++) {
            Rider *rider = &riders[numRiders];
            rider->id = numRiders;
            rider->currentFloor = i + 1;
            rider->destinationFloor = rand() % NUM_FLOORS + 1;
            rider->elevator = NULL;
            rider->hasArrived = false;
            sem_wait(&riderSemaphore);
            numRiders++;
            sem_post(&riderSemaphore);
            pthread_create(&riderThreads[numRiders], NULL, riderFunction, rider);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevatorThreads[i], NULL);
    }
    for (int i = 0; i < numRiders; i++) {
        pthread_join(riderThreads[i], NULL);
    }

    return 0;
}

// Elevator Thread Function
void* elevatorFunction(void* elevatorArg) {
    Elevator *elevator = (Elevator*)elevatorArg;
    printf("Elevator %d starting on floor %d\n", elevator->id, elevator->currentFloor);
    while (1) {
        // Check if there are riders waiting to be picked up or riders inside the elevator need to get off
        bool foundRider = false;
        sem_wait(&(elevator->mutex));
        for (int i = 0; i < numRiders; i++) {
            Rider *rider = &riders[i];
            if (rider->hasArrived) {
                // Rider has arrived at their destination, remove rider from elevator
                for (int j = 0; j < elevator->numRiders; j++) {
                    if (elevator->riders[j] == rider->id) {
                        elevator->riders[j] = -1;
                        elevator->numRiders--;
                        sem_post(&(elevator->capacity));
                        printf("Rider %d has left elevator %d on floor %d\n", rider->id, elevator->id, elevator->currentFloor);
                        rider->elevator = NULL;
                        rider->hasArrived = false;
                        break;
                    }
                }
            } else if (rider->currentFloor == elevator->currentFloor) {
                // Rider is waiting at this floor and wants to go in the same direction the elevator is going
                sem_wait(&(elevator->capacity));
                elevator->riders[elevator->numRiders] = rider->id;
                elevator->numRiders++;
                foundRider = true;
                printf("Rider %d has entered elevator %d on floor %d\n", rider->id, elevator->id, elevator->currentFloor);
                rider->elevator = elevator;
                break;
            }
        }
        sem_post(&(elevator->mutex));

        // If no rider is found, keep moving in the same direction
        if (!foundRider) {
            // Change direction if we reach the top or bottom floor
            if (elevator->currentFloor == NUM_FLOORS) {
                elevator->destinationFloor = elevator->currentFloor - 1;
            } else if (elevator->currentFloor == 1) {
                elevator->destinationFloor = elevator->currentFloor + 1;
            }

            // Move the elevator in the current direction
            if (elevator->currentFloor < elevator->destinationFloor) {
                elevator->currentFloor++;
                printf("Elevator %d moving up to floor %d\n", elevator->id, elevator->currentFloor);
            } else if (elevator->currentFloor > elevator->destinationFloor) {
                elevator->currentFloor--;
                printf("Elevator %d moving down to floor %d\n", elevator->id, elevator->currentFloor);
            }

            // Sleep for some time to simulate the time it takes to move to the next floor
            sleep(1);
        } else {
            // Rider is found, move the elevator to the rider's destination floor
            elevator->destinationFloor = riders[elevator->riders[elevator->numRiders - 1]].destinationFloor;
            while (elevator->currentFloor != elevator->destinationFloor) {
                // Move the elevator in the direction of the rider's destination floor
                if (elevator->currentFloor < elevator->destinationFloor) {
                    elevator->currentFloor++;
                    printf("Elevator %d moving up to floor %d\n", elevator->id, elevator->currentFloor);
                } else if (elevator->currentFloor > elevator->destinationFloor) {
                    elevator->currentFloor--;
                    printf("Elevator %d moving down to floor %d\n", elevator->id, elevator->currentFloor);
                }

                // Sleep for some time to simulate the time it takes to move to the next floor
                sleep(1);
            }
        }
    }
}

// Rider Thread Function
void* riderFunction(void* riderArg) {
    Rider *rider = (Rider*)riderArg;
    printf("Rider %d waiting on floor %d to go to floor %d\n", rider->id, rider->currentFloor, rider->destinationFloor);
    while (!rider->hasArrived) {
        // If an elevator has not arrived yet, wait for one to arrive
        if (rider->elevator == NULL) {
            sem_wait(&elevatorSemaphore);
            for (int i = 0; i < NUM_ELEVATORS; i++) {
                if (elevators[i].currentFloor == rider->currentFloor) {
                    sem_wait(&(elevators[i].mutex));
                    if (elevators[i].numRiders < MAX_RIDERS) {
                        printf("Elevator %d arriving on floor %d\n", elevators[i].id, elevators[i].currentFloor);
                        elevators[i].riders[elevators[i].numRiders] = rider->id;
                        elevators[i].numRiders++;
                        rider->elevator = &elevators[i];
                        sem_post(&(elevators[i].capacity));
                        sem_post(&(elevators[i].mutex));
                        sem_post(&elevatorSemaphore);
                        break;
                    }
                    sem_post(&(elevators[i].mutex));
                }
            }
            sem_post(&elevatorSemaphore);
        } else {
            // If rider is already in the elevator, wait to arrive at the destination floor
            sem_wait(&(rider->elevator->mutex));
            if (rider->elevator->currentFloor == rider->destinationFloor) {
                rider->hasArrived = true;
                printf("Rider %d has arrived at their destination floor %d\n", rider->id, rider->currentFloor);
            }
            sem_post(&(rider->elevator->mutex));
        }

        // Sleep for some time to simulate the time it takes to wait for an elevator or travel in an elevator
        sleep(1);
    }
}