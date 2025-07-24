//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 4

// Elevator structure
typedef struct Elevator {
    int id;
    int current_floor;
    int direction; // 1 for up; -1 for down; 0 for idle
    int destination;
    int passengers;
    pthread_mutex_t lock;
    pthread_cond_t arrived;
} Elevator;

// Floor structure
typedef struct Floor {
    int floor_number;
    pthread_mutex_t lock;
    pthread_cond_t waiting;
} Floor;

Elevator elevators[MAX_ELEVATORS];
Floor floors[MAX_FLOORS];

// Initialize elevators
void init_elevators() {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = rand() % MAX_FLOORS; // Random starting floor
        elevators[i].direction = 0;
        elevators[i].destination = -1;
        elevators[i].passengers = 0;
        pthread_mutex_init(&elevators[i].lock, NULL);
        pthread_cond_init(&elevators[i].arrived, NULL);
    }
}

// Initialize floors
void init_floors() {
    for (int i = 0; i < MAX_FLOORS; i++) {
        floors[i].floor_number = i;
        pthread_mutex_init(&floors[i].lock, NULL);
        pthread_cond_init(&floors[i].waiting, NULL);
    }
}

// Move elevator to a floor
void move_elevator_to_floor(Elevator *elevator, int floor_number) {
    printf("Elevator %d moving from floor %d to floor %d.\n", elevator->id, elevator->current_floor, floor_number);
    usleep(abs(elevator->current_floor - floor_number) * 1000000); // simulate travel time
    elevator->current_floor = floor_number;
}

// Find closest elevator to a floor
Elevator *find_closest_elevator(int floor_number) {
    Elevator *closest_elevator = NULL;
    int min_distance = MAX_FLOORS;
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        Elevator *elevator = &elevators[i];
        int distance = abs(elevator->current_floor - floor_number);
        if (distance < min_distance) {
            closest_elevator = elevator;
            min_distance = distance;
        }
    }
    return closest_elevator;
}

// Elevator thread function
void *elevator_thread(void *arg) {
    Elevator *elevator = (Elevator *) arg;
    while (1) {
        // Wait for a destination
        pthread_mutex_lock(&elevator->lock);
        while (elevator->destination == -1) {
            pthread_cond_wait(&elevator->arrived, &elevator->lock);
        }

        // Move to destination
        move_elevator_to_floor(elevator, elevator->destination);
        printf("Elevator %d has arrived at floor %d.\n", elevator->id, elevator->destination);

        // Open doors and let passengers exit
        pthread_mutex_lock(&floors[elevator->destination].lock);
        elevator->passengers = 0;
        pthread_cond_broadcast(&floors[elevator->destination].waiting);
        pthread_mutex_unlock(&floors[elevator->destination].lock);

        // Wait for passengers to enter
        pthread_mutex_lock(&elevator->lock);
        while (elevator->passengers == 0) {
            pthread_cond_wait(&elevator->arrived, &elevator->lock);
        }

        // Set direction and find next destination
        if (elevator->destination > elevator->current_floor) {
            elevator->direction = 1;
            for (int i = elevator->destination + 1; i < MAX_FLOORS; i++) {
                if (floors[i].waiting.__align == 0) { // Check if floor is not locked
                    elevator->destination = i;
                    break;
                }
            }
        } else {
            elevator->direction = -1;
            for (int i = elevator->destination - 1; i >= 0; i--) {
                if (floors[i].waiting.__align == 0) { // Check if floor is not locked
                    elevator->destination = i;
                    break;
                }
            }
        }
        if (elevator->destination == elevator->current_floor) {
            elevator->direction = 0;
        }

        // Release lock and signal arrival
        pthread_mutex_unlock(&elevator->lock);
        pthread_cond_signal(&elevator->arrived);
    }
}

// Floor thread function
void *floor_thread(void *arg) {
    Floor *floor = (Floor *) arg;
    while (1) {
        // Wait for an elevator
        pthread_mutex_lock(&floor->lock);
        Elevator *elevator = find_closest_elevator(floor->floor_number);
        while (elevator->destination != -1) {
            pthread_cond_wait(&elevator->arrived, &floor->lock);
            elevator = find_closest_elevator(floor->floor_number);
        }

        // Enter elevator
        printf("Passenger on floor %d entering elevator %d.\n", floor->floor_number, elevator->id);
        pthread_mutex_lock(&elevator->lock);
        elevator->passengers++;
        elevator->destination = floor->floor_number;
        pthread_mutex_unlock(&elevator->lock);

        // Signal elevator arrival
        pthread_mutex_unlock(&floor->lock);
        pthread_cond_signal(&elevator->arrived);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    init_elevators();
    init_floors();

    pthread_t elevator_threads[MAX_ELEVATORS];
    pthread_t floor_threads[MAX_FLOORS];

    // Start elevator threads
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, elevator_thread, &elevators[i]);
    }

    // Start floor threads
    for (int i = 0; i < MAX_FLOORS; i++) {
        pthread_create(&floor_threads[i], NULL, floor_thread, &floors[i]);
    }

    // Join threads (never happens)
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }
    for (int i = 0; i < MAX_FLOORS; i++) {
        pthread_join(floor_threads[i], NULL);
    }

    return 0;
}