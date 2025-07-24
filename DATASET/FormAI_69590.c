//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define MAX_CAPACITY 10

typedef struct {
    int currentFloor;
    int targetFloor;
    bool up;
    bool active;
    bool doorOpen;
    int passengers;
    int maxCapacity;
    pthread_mutex_t lock;
    pthread_cond_t elevatorMoved;
} Elevator;

typedef struct {
    int id;
    bool up[NUM_FLOORS];
    bool down[NUM_FLOORS];
    int passengers[NUM_FLOORS];
    pthread_mutex_t lock;
    pthread_cond_t elevatorArrived;
} Floor;

Elevator elevators[NUM_ELEVATORS];
Floor floors[NUM_FLOORS];

void initialize() {
    for(int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].targetFloor = 0;
        elevators[i].up = true;
        elevators[i].active = true;
        elevators[i].doorOpen = false;
        elevators[i].passengers = 0;
        elevators[i].maxCapacity = MAX_CAPACITY;
        pthread_mutex_init(&elevators[i].lock, NULL);
        pthread_cond_init(&elevators[i].elevatorMoved, NULL);
    }
    for(int i = 0; i < NUM_FLOORS; i++) {
        for(int j = 0; j < NUM_FLOORS; j++) {
            floors[i].up[j] = (j > i);
            floors[i].down[j] = (j < i);
            floors[i].passengers[j] = 0;
        }
        pthread_mutex_init(&floors[i].lock, NULL);
        pthread_cond_init(&floors[i].elevatorArrived, NULL);
    }
}

void* elevatorFunction(void* arg) {
    Elevator* elevator = (Elevator*)arg;
 
    while (elevator->active) {
        pthread_mutex_lock(&elevator->lock);
        if(elevator->doorOpen) {
            printf("Elevator at floor %d, door open\n", elevator-> currentFloor);
            sleep(2);
            elevator->doorOpen = false;
            printf("Elevator door at floor %d is now closed\n", elevator-> currentFloor);
        }
        if(elevator->currentFloor == elevator->targetFloor) {
            if(floors[elevator->currentFloor].passengers[elevator->currentFloor] > 0) {
                int passengersToTake = floors[elevator->currentFloor].passengers[elevator->currentFloor];
                if(passengersToTake <= (elevator->maxCapacity - elevator->passengers)) {
                    elevator->passengers += passengersToTake;
                    floors[elevator->currentFloor].passengers[elevator->currentFloor] = 0;
                } else {
                    elevator->passengers = elevator->maxCapacity;
                    floors[elevator->currentFloor].passengers[elevator->currentFloor] -= elevator->maxCapacity;
                }
            }
            if(elevator->up) {
                if(elevator->currentFloor < (NUM_FLOORS-1)) {
                    if(floors[elevator->currentFloor].up[elevator->currentFloor+1]) {
                        elevator->targetFloor = elevator->currentFloor + 1;
                        printf("Elevator %d going up to floor %d\n", elevator-elevators+1, elevator->targetFloor);
                    } else if(floors[elevator->currentFloor].down[elevator->currentFloor+1]) {
                        elevator->up = false;
                        elevator->targetFloor = elevator->currentFloor - 1;
                        printf("Elevator %d changing direction, going down to floor %d\n", elevator-elevators+1, elevator->targetFloor);
                    }
                } else {
                    elevator->up = false;
                    elevator->targetFloor = elevator->currentFloor - 1;
                    printf("Elevator %d changing direction, going down to floor %d\n", elevator-elevators+1, elevator->targetFloor);
                }
            } else {
                if(elevator->currentFloor > 0) {
                    if(floors[elevator->currentFloor].down[elevator->currentFloor-1]) {
                        elevator->targetFloor = elevator->currentFloor - 1;
                        printf("Elevator %d going down to floor %d\n", elevator-elevators+1, elevator->targetFloor);
                    } else if(floors[elevator->currentFloor].up[elevator->currentFloor-1]) {
                        elevator->up = true;
                        elevator->targetFloor = elevator->currentFloor + 1;
                        printf("Elevator %d changing direction, going up to floor %d\n", elevator-elevators+1, elevator->targetFloor);
                    }
                } else {
                    elevator->up = true;
                    elevator->targetFloor = elevator->currentFloor + 1;
                    printf("Elevator %d changing direction, going up to floor %d\n", elevator-elevators+1, elevator->targetFloor);
                }
            }
        }
        if(elevator->currentFloor < elevator->targetFloor) {
            elevator->currentFloor++;
        } else if(elevator->currentFloor > elevator->targetFloor) {
            elevator->currentFloor--;
        }
        pthread_mutex_unlock(&elevator->lock);
        pthread_cond_broadcast(&elevator->elevatorMoved);
        pthread_mutex_lock(&floors[elevator->currentFloor].lock);
        pthread_cond_signal(&floors[elevator->currentFloor].elevatorArrived);
        pthread_mutex_unlock(&floors[elevator->currentFloor].lock);
        sleep(1);
    }
    return NULL;
}

void* passengerFunction(void* arg) {
    int passengerSource = rand() % NUM_FLOORS;
    int passengerDestination = rand() % NUM_FLOORS;
    while (passengerSource == passengerDestination) {
        passengerDestination = rand() % NUM_FLOORS;
    }
    printf("New passenger wants to go from %d to %d\n", passengerSource, passengerDestination);

    int elevatorDestination;
    while(1) {
        int shortestDistance = NUM_FLOORS + 1;
        Elevator* bestElevator = NULL;

        for(int i = 0; i < NUM_ELEVATORS; i++) {
            pthread_mutex_lock(&elevators[i].lock);
            if(!elevators[i].active) {
                pthread_mutex_unlock(&elevators[i].lock);
                continue;
            }
            if(elevators[i].doorOpen) {
                pthread_cond_wait(&elevators[i].elevatorMoved, &elevators[i].lock);
            }
            if((elevators[i].up && floors[passengerSource].up[elevators[i].currentFloor]) 
                    || (!elevators[i].up && floors[passengerSource].down[elevators[i].currentFloor])) {
                int elevatorDistance = abs(elevators[i].currentFloor - passengerSource);
                if(elevatorDistance < shortestDistance && elevators[i].passengers < elevators[i].maxCapacity) {
                    shortestDistance = elevatorDistance;
                    bestElevator = &elevators[i];
                    elevatorDestination = passengerDestination;
                }
            }
            pthread_mutex_unlock(&elevators[i].lock);
        }
        if(bestElevator != NULL) {
            pthread_mutex_lock(&bestElevator->lock);
            floors[passengerSource].passengers[passengerSource]++;
            printf("Passenger waiting at floor %d, calling elevator %d\n", passengerSource, bestElevator-elevators+1);
            while(bestElevator->currentFloor != passengerSource || bestElevator->doorOpen) {
                pthread_cond_wait(&bestElevator->elevatorMoved, &bestElevator->lock);
            }
            bestElevator->targetFloor = elevatorDestination;
            printf("Passenger enters elevator %d at floor %d going to floor %d\n", bestElevator-elevators+1, bestElevator->currentFloor, elevatorDestination);
            while(bestElevator->currentFloor != elevatorDestination || bestElevator->doorOpen) {
                pthread_cond_wait(&bestElevator->elevatorMoved, &bestElevator->lock);
            }
            bestElevator->passengers--;
            printf("Passenger leaves elevator %d at floor %d\n", bestElevator-elevators+1, bestElevator->currentFloor);
            pthread_mutex_unlock(&bestElevator->lock);
            pthread_exit(NULL);
        }
    }
}

int main() {
    srand(time(NULL));
    initialize();
    pthread_t elevatorThreads[NUM_ELEVATORS];
    for(int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_create(&elevatorThreads[i], NULL, elevatorFunction, &elevators[i]);
    }
    pthread_t passengerThreads[NUM_FLOORS*10];
    for(int i = 0; i < NUM_FLOORS*10; i++) {
        pthread_create(&passengerThreads[i], NULL, passengerFunction, NULL);
        usleep(10000);
    }
    sleep(60);
    for(int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].active = false;
    }
    for(int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevatorThreads[i], NULL);
    }
    return 0;
}