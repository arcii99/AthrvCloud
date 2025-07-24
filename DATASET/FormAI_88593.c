//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define ELEVATOR_CAPACITY 10

// Mutexes and semaphores
sem_t floor_semaphores[NUM_FLOORS]; // One semaphore per floor to signal elevator arrival
pthread_mutex_t mutex_elevator[NUM_ELEVATORS]; // One mutex per elevator to limit elevator access
pthread_mutex_t mutex_passengers[NUM_FLOORS]; // One mutex per floor to limit passenger access
pthread_t elevators[NUM_ELEVATORS]; // One thread per elevator

// Elevator structure
typedef struct {
    int capacity;
    int current_floor;
    int destination_floor;
    bool moving;
    int passengers[ELEVATOR_CAPACITY];
    int num_passengers;
} Elevator;

// Passenger structure
typedef struct {
    int current_floor;
    int destination_floor;
} Passenger;

// Array to hold passenger waiting on each floor
Passenger floors[NUM_FLOORS][100];
int num_floor_passengers[NUM_FLOORS];

// Elevator functions
void* operate_elevator(void* arg) {
    Elevator* elevator = (Elevator*) arg;
    while (true) {
        sleep(2); // Wait for passengers to board
        pthread_mutex_lock(&mutex_elevator[elevator->current_floor]);
        printf("Elevator %d arrived at floor %d\n", (int) elevator - (int) elevators, elevator->current_floor);
        sem_post(&floor_semaphores[elevator->current_floor]);
        pthread_mutex_unlock(&mutex_elevator[elevator->current_floor]);

        // Wait until passenger selects a floor
        sem_wait(&floor_semaphores[elevator->current_floor]);
        pthread_mutex_lock(&mutex_elevator[elevator->current_floor]);
        printf("Elevator %d door closed at floor %d\n", (int) elevator - (int) elevators, elevator->current_floor);

        // Drop off passengers at this floor
        for (int i = 0; i < elevator->num_passengers; ++i) {
            if (elevator->passengers[i] == elevator->current_floor) {
                elevator->passengers[i] = -1;
                elevator->num_passengers--;
                printf("Passenger dropped off at floor %d\n", elevator->current_floor);
            }
        }

        // Pick up passengers from this floor
        elevator->destination_floor = -1;
        for (int i = 0; i < num_floor_passengers[elevator->current_floor]; ++i) {
            Passenger* passenger = &floors[elevator->current_floor][i];
            if (elevator->num_passengers < elevator->capacity &&
                    (elevator->destination_floor == -1 || elevator->destination_floor == elevator->current_floor
                            || abs(elevator->destination_floor - elevator->current_floor) > abs(passenger->destination_floor - elevator->current_floor))) {
                elevator->passengers[elevator->num_passengers++] = elevator->current_floor;
                elevator->destination_floor = passenger->destination_floor;
                printf("Passenger picked up at floor %d\n", elevator->current_floor);
                pthread_mutex_unlock(&mutex_passengers[elevator->current_floor]);
            }
        }

        // Move elevator to next floor
        printf("Elevator %d moving from floor %d to floor %d\n", (int) elevator - (int) elevators, elevator->current_floor, elevator->destination_floor);
        elevator->moving = true;
        while (elevator->current_floor != elevator->destination_floor) {
            sleep(1);
            if (elevator->current_floor < elevator->destination_floor) {
                ++elevator->current_floor;
            } else {
                --elevator->current_floor;
            }
            printf("Elevator %d arrived at floor %d\n", (int) elevator - (int) elevators, elevator->current_floor);
            sem_post(&floor_semaphores[elevator->current_floor]);
            pthread_mutex_unlock(&mutex_elevator[elevator->current_floor]);
            pthread_mutex_lock(&mutex_elevator[elevator->current_floor]);
            sem_wait(&floor_semaphores[elevator->current_floor]);
        }
        elevator->moving = false;
    }
}

// Main function
int main() {
    // Initialize semaphores and mutexes
    for (int i = 0; i < NUM_FLOORS; ++i) {
        sem_init(&floor_semaphores[i], 0, 0);
        pthread_mutex_init(&mutex_passengers[i], NULL);
    }
    for (int i = 0; i < NUM_ELEVATORS; ++i) {
        pthread_mutex_init(&mutex_elevator[i], NULL);
    }

    // Initialize elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; ++i) {
        elevators[i].capacity = ELEVATOR_CAPACITY;
        elevators[i].current_floor = 0;
        elevators[i].destination_floor = -1;
        elevators[i].moving = false;
        elevators[i].num_passengers = 0;
    }

    // Spawn elevator threads
    for (int i = 0; i < NUM_ELEVATORS; ++i) {
        pthread_create(&elevators[i], NULL, operate_elevator, &elevators[i]);
    }

    // Generate random passengers
    while (true) {
        int floor = rand() % NUM_FLOORS;
        Passenger passenger = { floor, rand() % NUM_FLOORS };
        pthread_mutex_lock(&mutex_passengers[floor]);
        if (num_floor_passengers[floor] == 0) {
            pthread_mutex_lock(&mutex_elevator[floor]);
        }
        floors[floor][num_floor_passengers[floor]++] = passenger;
        pthread_mutex_unlock(&mutex_passengers[floor]);
        if (num_floor_passengers[floor] == 1) {
            sem_post(&floor_semaphores[floor]);
        }
        sleep(3);
    }
    return 0;
}