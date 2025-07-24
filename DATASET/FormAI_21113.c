//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define FLOORS 10
#define ELEVATORS 2
#define PASSENGERS 20

sem_t elvSem[ELEVATORS];   // semaphore for each elevator, 0 when stopped, 1 when moving
sem_t floorSem[FLOORS];    // semaphore for each floor, 0 when no passenger, 1 when passenger waiting
sem_t elvReady[ELEVATORS]; // semaphore for each elevator, 0 when not ready to board, 1 when ready
sem_t elvFull[ELEVATORS];  // semaphore for each elevator, 0 when not full, 1 when full
sem_t elvEmpty[ELEVATORS]; // semaphore for each elevator, 0 when not empty, 1 when empty
pthread_t elvThd[ELEVATORS];
pthread_t pasThd[PASSENGERS];

// elevator struct
typedef struct elevator {
    int currFloor; // current floor
    int destFloor; // destination floor
    int dir;       // direction, 1 for up, -1 for down, 0 for stopped
    int cap;       // capacity
    int occ;       // occupancy
} Elevator;

Elevator elv[ELEVATORS] = {
        {.currFloor = 0, .destFloor = 0, .dir = 0, .cap = 5, .occ = 0},
        {.currFloor = 0, .destFloor = 0, .dir = 0, .cap = 5, .occ = 0}
};

// passenger struct
typedef struct passenger {
    int id;        // passenger id
    int currFloor; // current floor
    int destFloor; // destination floor
} Passenger;

Passenger pas[PASSENGERS] = {
        {.id = 0, .currFloor = 0, .destFloor = 4}, {.id = 1, .currFloor = 7, .destFloor = 2},
        {.id = 2, .currFloor = 5, .destFloor = 3}, {.id = 3, .currFloor = 2, .destFloor = 6},
        {.id = 4, .currFloor = 5, .destFloor = 9}, {.id = 5, .currFloor = 8, .destFloor = 1},
        {.id = 6, .currFloor = 9, .destFloor = 1}, {.id = 7, .currFloor = 0, .destFloor = 8},
        {.id = 8, .currFloor = 7, .destFloor = 0}, {.id = 9, .currFloor = 1, .destFloor = 7},
        {.id = 10, .currFloor = 3, .destFloor = 8}, {.id = 11, .currFloor = 4, .destFloor = 1},
        {.id = 12, .currFloor = 2, .destFloor = 7}, {.id = 13, .currFloor = 6, .destFloor = 0},
        {.id = 14, .currFloor = 1, .destFloor = 3}, {.id = 15, .currFloor = 9, .destFloor = 3},
        {.id = 16, .currFloor = 8, .destFloor = 0}, {.id = 17, .currFloor = 0, .destFloor = 2},
        {.id = 18, .currFloor = 6, .destFloor = 4}, {.id = 19, .currFloor = 9, .destFloor = 5}
};

// move elevator up/down
void moveElevator(int i) {
    if (elv[i].currFloor == FLOORS - 1) {
        elv[i].dir = -1; // change direction to down
    } else if (elv[i].currFloor == 0) {
        elv[i].dir = 1;  // change direction to up
    }
    elv[i].currFloor += elv[i].dir; // move elevator
}

// board passenger to elevator
void boardPassenger(int i, int j) {
    printf("Passenger %d boarded Elevator %d on Floor %d\n", pas[i].id, j, pas[i].currFloor);
    elv[j].occ++;
    if (elv[j].occ == elv[j].cap) {
        sem_post(&elvFull[j]); // elevator is full
        sem_wait(&elvEmpty[j]); // wait for elevator to empty
    }
}

// unboard passenger from elevator
void unboardPassenger(int i, int j) {
    printf("Passenger %d unboarded Elevator %d on Floor %d\n", pas[i].id, j, pas[i].destFloor);
    elv[j].occ--;
    if (elv[j].occ == 0) {
        sem_post(&elvEmpty[j]); // elevator is empty
        sem_wait(&elvReady[j]); // wait for elevator to load passengers
    }
}

// passenger thread function
void *passengerFunc(void *arg) {
    int i = *(int *) arg;
    while (1) {
        // wait for elevator or floor semaphore
        sem_wait(&floorSem[pas[i].currFloor]);
        printf("Passenger %d is waiting on Floor %d\n", pas[i].id, pas[i].currFloor);
        int j;
        for (j = 0; j < ELEVATORS; ++j) {
            // wait for elevator semaphore if elevator is moving
            if (elv[j].dir && elv[j].currFloor == pas[i].currFloor) {
                sem_wait(&elvSem[j]);
            }
            // check if elevator is on same floor or stopped
            if (!elv[j].dir || elv[j].currFloor == pas[i].currFloor) {
                // wait for elevator to be ready
                sem_wait(&elvReady[j]);
                if (elv[j].occ < elv[j].cap) {
                    boardPassenger(i, j); // board passenger to elevator
                    sem_post(&floorSem[pas[i].currFloor]); // signal floor semaphore
                    sem_post(&elvSem[j]); // signal elevator semaphore
                    sem_wait(&floorSem[pas[i].destFloor]); // wait for destination floor semaphore
                    unboardPassenger(i, j); // unboard passenger from elevator
                    sem_post(&floorSem[pas[i].destFloor]); // signal destination floor semaphore
                    pas[i].currFloor = pas[i].destFloor; // update current floor
                    break;
                }
            }
            // signal elevator semaphore if elevator is stopped
            if (!elv[j].dir) {
                sem_post(&elvSem[j]);
            }
        }
    }
}

// elevator thread function
void *elevatorFunc(void *arg) {
    int i = *(int *) arg;
    while (1) {
        // wait for elevator semaphore
        sem_wait(&elvSem[i]);
        if (elv[i].occ == 0) {
            sem_post(&elvReady[i]); // elevator is ready to board
        } else if (elv[i].occ == elv[i].cap) {
            sem_post(&elvFull[i]);  // elevator is full
        }
        if (!sem_trywait(&elvFull[i])) {
            sem_post(&elvReady[i]); // elevator is emptied, ready to board
        }
        moveElevator(i); // move elevator
        usleep(500000); // wait
    }
}

int main() {
    // initialize semaphores
    int i, j;
    for (i = 0; i < ELEVATORS; ++i) {
        sem_init(&elvSem[i], 0, 1);
        sem_init(&elvReady[i], 0, 0);
        sem_init(&elvFull[i], 0, 0);
        sem_init(&elvEmpty[i], 0, 1);
    }
    for (i = 0; i < FLOORS; ++i) {
        sem_init(&floorSem[i], 0, 0);
    }
    // create passenger threads
    int pasIds[PASSENGERS];
    for (i = 0; i < PASSENGERS; ++i) {
        pasIds[i] = i;
        pthread_create(&pasThd[i], NULL, passengerFunc, (void *) &pasIds[i]);
    }
    // create elevator threads
    int elvIds[ELEVATORS];
    for (i = 0; i < ELEVATORS; ++i) {
        elvIds[i] = i;
        pthread_create(&elvThd[i], NULL, elevatorFunc, (void *) &elvIds[i]);
    }
    // wait for threads to complete
    for (i = 0; i < PASSENGERS; ++i) {
        pthread_join(pasThd[i], NULL);
    }
    for (i = 0; i < ELEVATORS; ++i) {
        pthread_join(elvThd[i], NULL);
    }
    // destroy semaphores
    for (i = 0; i < ELEVATORS; ++i) {
        sem_destroy(&elvSem[i]);
        sem_destroy(&elvReady[i]);
        sem_destroy(&elvFull[i]);
        sem_destroy(&elvEmpty[i]);
    }
    for (i = 0; i < FLOORS; ++i) {
        sem_destroy(&floorSem[i]);
    }
    return 0;
}