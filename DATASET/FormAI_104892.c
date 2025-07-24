//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 50

// Mutex locks for the elevator
pthread_mutex_t elevator_mutex;
pthread_mutex_t passenger_mutex;

// Condition variables for the elevator
pthread_cond_t elevator_full_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t elevator_empty_cond = PTHREAD_COND_INITIALIZER;

// Condition variable for each passenger
pthread_cond_t passenger_finished_cond[MAX_PASSENGERS];

// Passenger struct
typedef struct {
    int locked; // 1 if the passenger is locked in a floor
    int floor;  // current floor of the passenger
    int dest;   // destination floor of the passenger
} Passenger;

// Elevator struct
typedef struct {
    int floor;      // current floor of the elevator
    int capacity;   // max capacity of the elevator
    int count;      // current number of passengers inside the elevator
    Passenger *passengers[MAX_PASSENGERS]; // list of passengers inside the elevator
} Elevator;

// Elevator object
Elevator elevator;

// List of passengers waiting on each floor
Passenger floor_passengers[MAX_FLOORS][MAX_PASSENGERS];

// Array to track the number of passengers waiting on each floor
int floor_passenger_count[MAX_FLOORS];

// Function to simulate the passenger actions
void *simulate_passenger(void *passenger_arg) {
    Passenger *passenger = (Passenger *) passenger_arg;
    pthread_mutex_lock(&passenger_mutex);
    // Wait until the passenger is locked on a floor
    while(!passenger->locked) {
        pthread_cond_wait(&passenger_finished_cond[passenger - floor_passengers[passenger->floor]], &passenger_mutex);
    }
    // Passenger is locked on a floor
    printf("Passenger on floor %d is waiting for elevator to go to floor %d\n", passenger->floor, passenger->dest);
    // Check if the elevator is on the same floor as the passenger
    if(elevator.floor == passenger->floor) {
        pthread_mutex_lock(&elevator_mutex);
        // Wait until there is capacity in the elevator for the passenger
        while(elevator.count == elevator.capacity) {
            pthread_cond_wait(&elevator_full_cond, &elevator_mutex);
        }
        // Add the passenger to the elevator
        elevator.passengers[elevator.count] = passenger;
        elevator.count++;
        // Remove the passenger from the floor list
        floor_passenger_count[passenger->floor]--;
        passenger->locked = 0;
        pthread_mutex_unlock(&passenger_mutex);
        printf("Passenger on floor %d entered the elevator\n", passenger->floor);
        // Notify the elevator that it's not empty anymore
        pthread_cond_signal(&elevator_empty_cond);
        pthread_mutex_unlock(&elevator_mutex);
        // Wait until the passenger arrives at their destination
        pthread_mutex_lock(&passenger_mutex);
        while(passenger->floor != passenger->dest) {
            pthread_cond_wait(&passenger_finished_cond[passenger - floor_passengers[passenger->floor]], &passenger_mutex);
        }
        printf("Passenger arrived at destination: %d\n", passenger->dest);
        pthread_mutex_unlock(&passenger_mutex);
    } else {
        pthread_mutex_unlock(&passenger_mutex);
    }
    return NULL;
}

// Function to simulate the elevator actions
void *simulate_elevator(void *args) {
    while(1) {
        pthread_mutex_lock(&elevator_mutex);
        // Check if there are passengers in the elevator
        if(elevator.count > 0) {
            // Move the elevator to the next floor
            if(elevator.floor < elevator.passengers[0]->dest) {
                elevator.floor++;
            } else if(elevator.floor > elevator.passengers[0]->dest) {
                elevator.floor--;
            } else {
                // Passenger arrived at destination
                elevator.passengers[0]->floor = elevator.passengers[0]->dest;
                // Notify the passenger
                pthread_cond_signal(&passenger_finished_cond[elevator.passengers[0] - floor_passengers[elevator.passengers[0]->floor]]);
                // Remove the passenger from the elevator and update count
                elevator.count--;
                elevator.passengers[0] = NULL;
                for(int i = 0; i < elevator.count; i++) {
                    elevator.passengers[i] = elevator.passengers[i + 1];
                }
                pthread_cond_signal(&elevator_full_cond);
            }
        }
        // Check if the elevator is empty and there are passengers waiting
        if(elevator.count == 0) {
            // Check each floor for waiting passengers
            for(int i = 0; i < MAX_FLOORS; i++) {
                if(floor_passenger_count[i] > 0) {
                    // Move the elevator to the waiting floor
                    if(elevator.floor < i) {
                        elevator.floor++;
                    } else if(elevator.floor > i) {
                        elevator.floor--;
                    }
                    // Notify the passengers on the floor
                    for(int j = 0; j < floor_passenger_count[i]; j++) {
                        floor_passengers[i][j].locked = 1;
                        pthread_cond_signal(&passenger_finished_cond[j]);
                    }
                    // Wait until the elevator is full or all passengers are inside
                    while(elevator.count < elevator.capacity && floor_passenger_count[i] > 0) {
                        pthread_cond_wait(&elevator_empty_cond, &elevator_mutex);
                    }
                    // Add passengers to the elevator
                    for(int j = 0; j < floor_passenger_count[i]; j++) {
                        if(elevator.count < elevator.capacity) {
                            elevator.passengers[elevator.count] = &floor_passengers[i][j];
                            elevator.count++;
                            printf("Passenger on floor %d entered the elevator\n", i);
                            floor_passenger_count[i]--;
                            floor_passengers[i][j].locked = 0;
                        } else {
                            break;
                        }
                    }
                    // Notify the elevator that it's not empty anymore
                    pthread_cond_signal(&elevator_full_cond);
                    break;
                }
            }
        }
        pthread_mutex_unlock(&elevator_mutex);
        usleep(500000);
    }
}

int main(int argc, char *argv[]) {
    // Initialize the elevator
    elevator.floor = 0;
    elevator.capacity = 10;
    elevator.count = 0;

    // Initialize the passenger floors
    for(int i = 0; i < MAX_FLOORS; i++) {
        floor_passenger_count[i] = 0;
    }

    // Create the passenger threads
    pthread_t passenger_threads[MAX_PASSENGERS];
    for(int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger *passenger = &floor_passengers[0][i];
        passenger->floor = rand() % MAX_FLOORS;
        passenger->dest = rand() % MAX_FLOORS;
        if(passenger->floor != passenger->dest) {
            floor_passenger_count[passenger->floor]++;
            passenger->locked = 1;
            pthread_create(&passenger_threads[i], NULL, simulate_passenger, passenger);
        }
    }

    // Create the elevator thread
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, simulate_elevator, NULL);

    // Wait for all passenger threads to finish
    for(int i = 0; i < MAX_PASSENGERS; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    // Wait for the elevator thread to finish
    pthread_join(elevator_thread, NULL);

    return 0;
}