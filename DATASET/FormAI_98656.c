//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_FLOORS 6
#define NUM_ELEVATORS 3

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool in_service;
    int current_floor;
    int destination_floor;
} Elevator;

Elevator elevators[NUM_ELEVATORS];

pthread_t elevator_threads[NUM_ELEVATORS];

pthread_mutex_t floor_mutex[NUM_FLOORS];
pthread_cond_t floor_cond[NUM_FLOORS];
int floor_requests[NUM_FLOORS];

bool simulating = true;

void initialize_elevator(Elevator *elevator) {
    pthread_mutex_init(&(elevator->mutex), NULL);
    pthread_cond_init(&(elevator->cond), NULL);
    elevator->in_service = false;
    elevator->current_floor = 0;
    elevator->destination_floor = 0;
}

void request_elevator(int floor) {
    int closest_elevator_id = -1;
    int closest_elevator_distance = 999;

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].in_service == false) {
            if (abs(floor - elevators[i].current_floor) < closest_elevator_distance) {
                closest_elevator_id = i;
                closest_elevator_distance = abs(floor - elevators[i].current_floor);
            }
        }
    }

    if (closest_elevator_id != -1) {
        pthread_mutex_lock(&(elevators[closest_elevator_id].mutex));
        elevators[closest_elevator_id].destination_floor = floor;
        pthread_cond_signal(&(elevators[closest_elevator_id].cond));
        pthread_mutex_unlock(&(elevators[closest_elevator_id].mutex));
    }
}

void *elevator_routine(void *elevator_arg) {
    Elevator * current_elevator = (Elevator *) elevator_arg;

    while (simulating) {
        // Lock on elevator mutex
        pthread_mutex_lock(&(current_elevator->mutex));
        current_elevator->in_service = true;

        // Wait for request
        while (current_elevator->current_floor != current_elevator->destination_floor) {
            pthread_cond_wait(&(current_elevator->cond), &(current_elevator->mutex));
        }

        current_elevator->in_service = false;

        // Unlock elevator mutex
        pthread_mutex_unlock(&(current_elevator->mutex));
    }

    return NULL;
}

void initialize() {
    for (int i = 0; i < NUM_FLOORS; i++) {
        pthread_mutex_init(&(floor_mutex[i]), NULL);
        pthread_cond_init(&(floor_cond[i]), NULL);
        floor_requests[i] = 0;
    }

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        initialize_elevator(&(elevators[i]));
        pthread_create(&(elevator_threads[i]), NULL, elevator_routine, &(elevators[i]));
    }
}

int main() {
    initialize();

    while (simulating) {
        // Check for pending requests on floors
        for (int i = 0; i < NUM_FLOORS; i++) {
            pthread_mutex_lock(&(floor_mutex[i]));
            if (floor_requests[i] == 1) {
                request_elevator(i);
                floor_requests[i] = 0;
            }
            pthread_mutex_unlock(&(floor_mutex[i]));
        }

        // Sleep for 1 second
        usleep(1000000);
    }

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    return 0;
}