//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 5

int floors[MAX_FLOORS][MAX_ELEVATORS]; // Array representing floors and elevators
pthread_mutex_t lock[MAX_FLOORS]; // Array of mutex locks for each floor
pthread_cond_t cond[MAX_FLOORS]; // Array of condition variables for each floor
pthread_t elevators[MAX_ELEVATORS]; // Array of elevator threads

// Struct representing a passenger
typedef struct {
    int from_floor;
    int to_floor;
} Passenger;

// Elevator function
void *elevator(void *arg) {
    int id = *(int *) arg;

    while (1) {
        // Move the elevator up
        for (int i = 0; i < MAX_FLOORS; i++) {
            // Lock the current floor
            pthread_mutex_lock(&lock[i]);

            // Check if there are any passengers on this floor that need to go up
            int passengers = 0;
            for (int j = 0; j < MAX_ELEVATORS; j++) {
                if (floors[i][j] == 1) {
                    passengers++;
                }
            }

            if (passengers > 0) {
                printf("Elevator %d: stopping at floor %d to pick up %d passengers\n", id, i, passengers);
                sleep(2); // Wait for passengers to get on

                // Move the passengers onto the elevator
                for (int j = 0; j < MAX_ELEVATORS; j++) {
                    if (floors[i][j] == 1) {
                        printf("Elevator %d: passenger on board from floor %d\n", id, i);
                        floors[i][j] = 0;
                    }
                }

                // Move the elevator up to the next floor
                printf("Elevator %d: moving up to floor %d\n", id, i+1);
                sleep(1);
            }

            // Unlock the current floor
            pthread_mutex_unlock(&lock[i]);

            // Check if this is the top floor
            if (i == MAX_FLOORS-1) {
                break;
            }
        }

        // Move the elevator down
        for (int i = MAX_FLOORS-1; i >= 0; i--) {
            // Lock the current floor
            pthread_mutex_lock(&lock[i]);

            // Check if there are any passengers on this floor that need to go down
            int passengers = 0;
            for (int j = 0; j < MAX_ELEVATORS; j++) {
                if (floors[i][j] == -1) {
                    passengers++;
                }
            }

            if (passengers > 0) {
                printf("Elevator %d: stopping at floor %d to pick up %d passengers\n", id, i, passengers);
                sleep(2); // Wait for passengers to get on

                // Move the passengers onto the elevator
                for (int j = 0; j < MAX_ELEVATORS; j++) {
                    if (floors[i][j] == -1) {
                        printf("Elevator %d: passenger on board from floor %d\n", id, i);
                        floors[i][j] = 0;
                    }
                }

                // Move the elevator down to the next floor
                printf("Elevator %d: moving down to floor %d\n", id, i-1);
                sleep(1);
            }

            // Unlock the current floor
            pthread_mutex_unlock(&lock[i]);

            // Check if this is the bottom floor
            if (i == 0) {
                break;
            }
        }
    }
}

// Function for passenger thread
void *passenger(void *arg) {
    Passenger *p = (Passenger *) arg;

    // Lock the from_floor mutex
    pthread_mutex_lock(&lock[p->from_floor]);

    // Wait for elevator to arrive
    while (1) {
        if (floors[p->from_floor][0] == 0) {
            floors[p->from_floor][0] = p->to_floor - p->from_floor;
            printf("Passenger: waiting on floor %d for elevator\n", p->from_floor);
            break;
        }
        pthread_cond_wait(&cond[p->from_floor], &lock[p->from_floor]);
    }

    // Unlock the from_floor mutex
    pthread_mutex_unlock(&lock[p->from_floor]);

    // Signal the elevator to move
    pthread_cond_signal(&cond[p->from_floor]);

    // Wait for elevator door to open
    sleep(1);

    // Lock the to_floor mutex
    pthread_mutex_lock(&lock[p->to_floor]);

    // Wait for elevator to arrive
    while (1) {
        if (floors[p->to_floor][0] == 0) {
            floors[p->to_floor][0] = 0 - (p->to_floor - p->from_floor);
            printf("Passenger: on elevator going from floor %d to floor %d\n", p->from_floor, p->to_floor);
            break;
        }
        pthread_cond_wait(&cond[p->to_floor], &lock[p->to_floor]);
    }

    // Unlock the to_floor mutex
    pthread_mutex_unlock(&lock[p->to_floor]);

    // Signal the elevator to move
    pthread_cond_signal(&cond[p->to_floor]);

    return NULL;
}

// Main function
int main() {
    // Initialize the mutex locks and condition variables
    for (int i = 0; i < MAX_FLOORS; i++) {
        pthread_mutex_init(&lock[i], NULL);
        pthread_cond_init(&cond[i], NULL);
    }

    // Initialize the elevators array
    int elevator_ids[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevator_ids[i] = i;
        pthread_create(&elevators[i], NULL, elevator, &elevator_ids[i]);
    }

    // Create some passengers
    Passenger p1 = {2, 7};
    Passenger p2 = {5, 0};
    Passenger p3 = {8, 4};
    pthread_t passenger_threads[3];
    pthread_create(&passenger_threads[0], NULL, passenger, &p1);
    pthread_create(&passenger_threads[1], NULL, passenger, &p2);
    pthread_create(&passenger_threads[2], NULL, passenger, &p3);

    // Wait for the passenger threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    // Wait for the elevator threads to finish
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_join(elevators[i], NULL);
    }

    // Destroy the mutex locks and condition variables
    for (int i = 0; i < MAX_FLOORS; i++) {
        pthread_mutex_destroy(&lock[i]);
        pthread_cond_destroy(&cond[i]);
    }

    return 0;
}