//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 10

int current_floor = 0;
int elevator_capacity = 0;
int passengers_waiting[MAX_FLOORS] = {0};
int passengers_elevator = 0;
int elevator_direction = 1; // 1 for UP, -1 for DOWN

pthread_mutex_t mutex;

void *elevator_function(void *args) {
    while(1) {
        pthread_mutex_lock(&mutex);

        // Check if there are passengers inside the elevator
        if(elevator_capacity > 0) {
            // Move the elevator to the next floor
            current_floor += elevator_direction;

            // Check if the elevator has reached its destination floor
            if(current_floor == 0 || current_floor == MAX_FLOORS-1) {
                // Change the direction of the elevator
                elevator_direction *= -1;
            }

            // Check if there are passengers that need to get off at this floor
            if(passengers_elevator > 0 && passengers_elevator <= elevator_capacity && passengers_waiting[current_floor] > 0) {
                printf("Elevator reached floor %d. %d passengers got off.\n", current_floor, passengers_waiting[current_floor]);
                passengers_waiting[current_floor] = 0;
                elevator_capacity -= passengers_elevator;
                passengers_elevator = 0;
            }

            // Check if there are passengers waiting at this floor
            if(passengers_waiting[current_floor] > 0 && passengers_elevator < ELEVATOR_CAPACITY) {
                int passengers_boarded = ELEVATOR_CAPACITY - passengers_elevator > passengers_waiting[current_floor] ? passengers_waiting[current_floor] : ELEVATOR_CAPACITY - passengers_elevator;
                printf("Elevator reached floor %d. %d passengers got in.\n", current_floor, passengers_boarded);
                passengers_waiting[current_floor] -= passengers_boarded;
                elevator_capacity += passengers_boarded;
                passengers_elevator += passengers_boarded;
            }

            printf("Elevator is at floor %d with %d passengers, going %s.\n", current_floor, elevator_capacity, elevator_direction == 1 ? "UP" : "DOWN");
        }

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *passenger_function(void *args) {
    int *floor = (int *) args;

    pthread_mutex_lock(&mutex);

    passengers_waiting[*floor]++;
    printf("Passenger arrived at floor %d. Total waiting: %d.\n", *floor, passengers_waiting[*floor]);

    pthread_mutex_unlock(&mutex);
    sleep(1);

    pthread_mutex_lock(&mutex);

    // Wait for the elevator and board it
    while(passengers_elevator == ELEVATOR_CAPACITY || current_floor != *floor || passengers_waiting[*floor] > 0) {
        pthread_mutex_unlock(&mutex);
        usleep(500);
        pthread_mutex_lock(&mutex);
    }

    passengers_waiting[*floor]--;
    passengers_elevator++;
    printf("Passenger boarded elevator at floor %d. Total in elevator: %d.\n", *floor, passengers_elevator);

    pthread_mutex_unlock(&mutex);
    sleep(1);

    // Wait for the elevator and get off
    while(current_floor != 0 && current_floor != MAX_FLOORS-1) {
        pthread_mutex_unlock(&mutex);
        usleep(500);
        pthread_mutex_lock(&mutex);
    }

    passengers_elevator--;
    printf("Passenger got off elevator at floor %d. Total in elevator: %d.\n", current_floor, passengers_elevator);

    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t elevator_thread;
    pthread_t passenger_threads[MAX_FLOORS * 2];
    int floors[] = {4, 2, 5, 8, 4, 1, 3, 7, 6, 9};

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&elevator_thread, NULL, elevator_function, NULL);

    for(int i = 0; i < MAX_FLOORS * 2; i++) {
        pthread_create(&passenger_threads[i], NULL, passenger_function, &floors[i%MAX_FLOORS]);
        usleep(250);
    }

    pthread_join(elevator_thread, NULL);

    for(int i = 0; i < MAX_FLOORS * 2; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}