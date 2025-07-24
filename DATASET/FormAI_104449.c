//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Constants
#define NUM_FLOORS 10
#define NUM_ELEVATORS 4
#define MAX_OCCUPANCY 10
#define SIMULATION_SPEED 2 // In seconds

// Shared variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
int occupancy[NUM_FLOORS][NUM_ELEVATORS];
int destination[NUM_ELEVATORS];
int current_floor[NUM_ELEVATORS];
int direction[NUM_ELEVATORS];
int stop[NUM_ELEVATORS];
int pass[NUM_ELEVATORS];
int floor_request[NUM_FLOORS];
int floor_request_dir[NUM_FLOORS];

// Helper functions
void wait_for_signal() {
    pthread_cond_wait(&cv, &mutex);
}

void broadcast_signal() {
    pthread_cond_broadcast(&cv);
}

int get_nearest_elevator(int floor, int dir) {
    int min_dist = 1000;
    int nearest_elevator = -1;
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (floor == current_floor[i] && direction[i] == dir && stop[i]) {
            return i;
        }
        if (stop[i] == 0) {
            int dist = abs(current_floor[i] - floor);
            if (dist < min_dist) {
                min_dist = dist;
                nearest_elevator = i;
            }
        }
    }
    return nearest_elevator;
}

void elevator_move(int id) {
    // Move the elevator
    if (direction[id] == 1) {
        current_floor[id]++;
    } else {
        current_floor[id]--;
    }
    printf("Elevator %d is now on floor %d\n", id, current_floor[id]);
    // Check if elevator reaches the destination floor
    if (current_floor[id] == destination[id]) {
        stop[id] = 1;
        printf("Elevator %d arrives at floor %d and opens its door\n", id, current_floor[id]);
        broadcast_signal();
    }
}

void* elevator(void* args) {
    int id = *(int*) args;
    free(args);
    // Initialize elevator
    current_floor[id] = 0;
    destination[id] = 0;
    direction[id] = 1;
    stop[id] = 0;
    pass[id] = 0;
    printf("Elevator %d starts at floor %d\n", id, current_floor[id]);
    while (1) {
        pthread_mutex_lock(&mutex);
        while (stop[id] == 0) {
            wait_for_signal();
        }
        // Unload passengers
        int num_pass = occupancy[current_floor[id]][id];
        if (num_pass > 0) {
            occupancy[current_floor[id]][id] = 0;
            pass[id] -= num_pass;
            printf("%d passengers exit the elevator %d on floor %d\n", num_pass, id, current_floor[id]);
        }
        // Load passengers
        int dest = floor_request[current_floor[id]];
        int dir = floor_request_dir[current_floor[id]];
        if (dest != -1 && dir == direction[id] && pass[id] < MAX_OCCUPANCY) {
            int num_pass = MAX_OCCUPANCY - pass[id];
            if (num_pass > dest) {
                num_pass = dest;
            }
            pass[id] += num_pass;
            floor_request[current_floor[id]] -= num_pass;
            occupancy[current_floor[id]][id] += num_pass;
            printf("%d passengers enter the elevator %d on floor %d\n", num_pass, id, current_floor[id]);
            destination[id] = floor_request_dir[current_floor[id]] == 1 ? NUM_FLOORS - 1 : 0;
        } else {
            // No passengers to load, so continue moving in the current direction
            destination[id] = direction[id] == 1 ? NUM_FLOORS - 1 : 0;
        }
        stop[id] = 0;
        pthread_mutex_unlock(&mutex);
        while (current_floor[id] != destination[id]) {
            sleep(SIMULATION_SPEED);
            pthread_mutex_lock(&mutex);
            elevator_move(id);
            pthread_mutex_unlock(&mutex);
        }
        if (current_floor[id] == NUM_FLOORS - 1) {
            direction[id] = -1;
        } else if (current_floor[id] == 0) {
            direction[id] = 1;
        }
    }
    return NULL;
}

int main() {
    // Initialize floor requests
    for (int i = 0; i < NUM_FLOORS; i++) {
        floor_request[i] = rand() % MAX_OCCUPANCY;
        floor_request_dir[i] = rand() % 2 == 0 ? 1 : -1;
    }
    // Create elevator threads
    pthread_t elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&elevators[i], NULL, &elevator, id);
    }
    // Main loop
    while (1) {
        // Generate new floor requests
        for (int i = 0; i < NUM_FLOORS; i++) {
            if (rand() % 2 == 0) {
                floor_request[i] += rand() % MAX_OCCUPANCY;
            }
        }
        // Assign floor requests to elevators
        for (int i = 0; i < NUM_FLOORS; i++) {
            int dir = floor_request_dir[i];
            if (dir == 1) {
                int e = get_nearest_elevator(i, dir);
                if (e != -1) {
                    destination[e] = i;
                    stop[e] = 1;
                }
            } else if (dir == -1) {
                int e = get_nearest_elevator(i, dir);
                if (e != -1) {
                    destination[e] = i;
                    stop[e] = 1;
                }
            }
        }
        sleep(SIMULATION_SPEED);
    }
    // Join elevator threads
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevators[i], NULL);
    }
    // Cleanup
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cv);
    return 0;
}