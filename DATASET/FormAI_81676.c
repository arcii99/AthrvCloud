//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 15
#define NUM_ELEVATORS 3

// Enumeration for the direction of elevator movement
enum Direction {
    UP,
    DOWN,
    IDLE
};

// Structure to represent a Passenger
struct Passenger {
    int id;
    int source_floor;
    int dest_floor;
};

// Structure to represent the Elevator
struct Elevator {
    int id;
    int current_floor;
    int dest_floor;
    bool is_busy;
    enum Direction direction;
    pthread_mutex_t lock;
};

// Global variables to keep track of passengers waiting at each floor and the elevators
struct Passenger waiting_passengers[MAX_FLOORS] = {0};
struct Elevator elevators[NUM_ELEVATORS];

// Function to move the elevator up or down
void move_elevator(struct Elevator *elevator) {
    while(elevator->current_floor != elevator->dest_floor) {
        printf("Elevator %d moving from floor %d to floor %d\n", elevator->id, elevator->current_floor, elevator->dest_floor);
        if(elevator->dest_floor > elevator->current_floor) {
            elevator->current_floor++;
            elevator->direction = UP;
        } else {
            elevator->current_floor--;
            elevator->direction = DOWN;
        }
        sleep(1);
    }
}

// Function to handle elevator requests
void* handle_elevator(void* arg) {
    struct Elevator *elevator = (struct Elevator*) arg;
    while(true) {
        // Check if there are passengers waiting at the current floor
        if(waiting_passengers[elevator->current_floor].id != 0) {
            printf("Elevator %d stopping at floor %d\n", elevator->id, elevator->current_floor);

            // Stop the elevator and pick up the passenger
            pthread_mutex_lock(&elevator->lock);
            elevator->is_busy = true;
            elevator->dest_floor = waiting_passengers[elevator->current_floor].dest_floor;
            printf("Elevator %d picked up passenger %d from floor %d going to floor %d\n", elevator->id, waiting_passengers[elevator->current_floor].id, elevator->current_floor, elevator->dest_floor);
            waiting_passengers[elevator->current_floor].id = 0;
            pthread_mutex_unlock(&elevator->lock);

            // Move the elevator to the destination floor
            move_elevator(elevator);

            // Drop off the passenger
            pthread_mutex_lock(&elevator->lock);
            printf("Elevator %d dropped off passenger %d at floor %d\n", elevator->id, waiting_passengers[elevator->current_floor].id, elevator->dest_floor);
            elevator->is_busy = false;
            elevator->direction = IDLE;
            pthread_mutex_unlock(&elevator->lock);
            continue;
        }

        // If there are no passengers waiting and the elevator is idle, wait for a request
        if(elevator->direction == IDLE) {
            printf("Elevator %d is idle at floor %d\n", elevator->id, elevator->current_floor);
            sleep(1);
            continue;
        }

        // If there are no passengers waiting at the current floor, move the elevator to the next floor
        if(elevator->direction == UP) {
            elevator->current_floor++;
            if(elevator->current_floor == MAX_FLOORS) {
                elevator->direction = DOWN;
            }
        } else {
            elevator->current_floor--;
            if(elevator->current_floor == 1) {
                elevator->direction = UP;
            }
        }
        printf("Elevator %d moving from floor %d to floor %d\n", elevator->id, elevator->current_floor - elevator->direction, elevator->current_floor);
        sleep(1);
    }
}

// Function to generate a random integer between min and max
int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize the elevators
    for(int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = 1;
        elevators[i].is_busy = false;
        elevators[i].direction = IDLE;
        pthread_mutex_init(&elevators[i].lock, NULL);
    }

    // Generate passengers
    for(int i = 0; i < MAX_FLOORS; i++) {
        int num_passengers = get_random_int(0, 5);
        for(int j = 0; j < num_passengers; j++) {
            int dest_floor = get_random_int(1, MAX_FLOORS);
            if(dest_floor == i + 1) {
                dest_floor = (dest_floor + 1) % MAX_FLOORS;
            }
            int k = 0;
            while(waiting_passengers[i].id != 0) {
                i = (i + 1) % MAX_FLOORS;
                k++;
                if(k == MAX_FLOORS) {
                    break;
                }
            }
            waiting_passengers[i].id = j + 1;
            waiting_passengers[i].source_floor = i + 1;
            waiting_passengers[i].dest_floor = dest_floor;
        }
    }

    // Create threads for each elevator
    pthread_t elevator_threads[NUM_ELEVATORS];
    for(int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, handle_elevator, (void*) &elevators[i]);
    }

    // Wait for threads to finish
    for(int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    return 0;
}