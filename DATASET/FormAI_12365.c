//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_FLOORS 10 // number of floors in the building
#define MAX_CAPACITY 10 // maximum number of people the elevator can carry

// definition of a floor
typedef struct __floor_t {
    int current_passengers; // number of passengers currently on the floor
    int requested_direction; // 0 if no requests, -1 if down, and 1 if up
    int visited; // 0 if not visited by the elevator, and 1 if visited
    pthread_mutex_t wait_mutex; // mutex used to synchronize access to the wait condition
    pthread_cond_t wait_condition; // condition variable used to wait for the elevator
} floor_t;

// definition of the elevator
typedef struct __elevator_t {
    int current_floor; // current floor number
    int direction; // 0 for stopped, -1 for down, and 1 for up
    int current_passengers; // number of passengers currently in the elevator
    int passengers[MAX_CAPACITY]; // array holding the IDs of the passengers
    pthread_mutex_t run_mutex; // mutex used to synchronize access to the run condition
    pthread_cond_t run_condition; // condition variable used to wait for the run thread
} elevator_t;

floor_t floors[MAX_FLOORS]; // array of floors
elevator_t elevator; // the elevator

int get_random_floor() {
    return rand() % MAX_FLOORS;
}

void *passenger_thread(void *args) {
    int id = *(int *) args;
    int current_floor = get_random_floor();
    int destination_floor;

    while (1) {
        do {
            destination_floor = get_random_floor();
        } while (destination_floor == current_floor);

        printf("Passenger %d wants to go from floor %d to floor %d.\n", id, current_floor, destination_floor);

        pthread_mutex_lock(&floors[current_floor].wait_mutex);
        floors[current_floor].current_passengers++;
        floors[current_floor].requested_direction = (destination_floor > current_floor) ? 1 : -1;

        while (floors[current_floor].visited == 0 || elevator.current_floor != current_floor || elevator.direction != floors[current_floor].requested_direction || (elevator.current_passengers == MAX_CAPACITY) || (elevator.current_passengers > 0 && elevator.passengers[0] > id)) {
            pthread_cond_wait(&floors[current_floor].wait_condition, &floors[current_floor].wait_mutex);
        }

        floors[current_floor].current_passengers--;
        printf("Passenger %d gets into the elevator at floor %d.\n", id, current_floor);

        pthread_mutex_lock(&elevator.run_mutex);
        elevator.current_passengers++;
        int i, j;
        for (i = 0; i < elevator.current_passengers - 1; i++) {
            if (elevator.passengers[i] > id) {
                for (j = elevator.current_passengers - 1; j >= i; j--) {
                    elevator.passengers[j + 1] = elevator.passengers[j];
                }
                break;
            }
        }
        elevator.passengers[i] = id;

        if (elevator.current_passengers == 1) {
            elevator.direction = floors[current_floor].requested_direction;
        }

        if (elevator.current_passengers == MAX_CAPACITY) {
            pthread_cond_signal(&elevator.run_condition);
        }

        pthread_mutex_unlock(&floors[current_floor].wait_mutex);
        pthread_mutex_unlock(&elevator.run_mutex);

        while (elevator.current_floor != destination_floor) {
            usleep(100);
        }

        pthread_mutex_lock(&elevator.run_mutex);
        printf("Passenger %d gets out of the elevator at floor %d.\n", id, elevator.current_floor);
        int k;
        for (k = 0; k < elevator.current_passengers; k++) {
            if (elevator.passengers[k] == id) {
                break;
            }
        }
        for (i = k; i < elevator.current_passengers - 1; i++) {
            elevator.passengers[i] = elevator.passengers[i + 1];
        }
        elevator.current_passengers--;

        if (elevator.current_passengers == 0) {
            elevator.direction = 0;
        }

        pthread_mutex_unlock(&elevator.run_mutex);

        current_floor = destination_floor;
    }
}

void *run_thread(void *args) {
    while (1) {
        pthread_mutex_lock(&elevator.run_mutex);

        if (elevator.current_passengers == 0) {
            pthread_cond_wait(&elevator.run_condition, &elevator.run_mutex);
        }

        elevator.direction = (elevator.direction == 1) ? -1 : 1;

        printf("Elevator is now moving %s.\n", (elevator.direction == 1) ? "up" : "down");

        int i;
        for (i = 0; i < MAX_FLOORS; i++) {
            if (elevator.direction == 1) {
                int j;
                for (j = 0; j < floors[i].current_passengers; j++) {
                    if (floors[i].requested_direction == 1 && elevator.current_passengers < MAX_CAPACITY) {
                        pthread_mutex_lock(&floors[i].wait_mutex);
                        floors[i].visited = 1;
                        printf("Elevator picks up passenger %d at floor %d.\n", floors[i].current_passengers + 1, i);
                        pthread_cond_signal(&floors[i].wait_condition);
                        pthread_mutex_unlock(&floors[i].wait_mutex);
                    }
                }
            } else {
                int j;
                for (j = floors[i].current_passengers - 1; j >= 0; j--) {
                    if (floors[i].requested_direction == -1 && elevator.current_passengers < MAX_CAPACITY) {
                        pthread_mutex_lock(&floors[i].wait_mutex);
                        floors[i].visited = 1;
                        printf("Elevator picks up passenger %d at floor %d.\n", floors[i].current_passengers + 1, i);
                        pthread_cond_signal(&floors[i].wait_condition);
                        pthread_mutex_unlock(&floors[i].wait_mutex);
                    }
                }
            }
        }

        printf("Elevator arrives at floor %d.\n", elevator.current_floor);

        pthread_mutex_unlock(&elevator.run_mutex);

        usleep(500000);
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));

    pthread_t passenger_threads[100];
    pthread_t run_thread_id;

    int i;
    for (i = 0; i < MAX_FLOORS; i++) {
        floors[i].current_passengers = 0;
        floors[i].requested_direction = 0;
        floors[i].visited = 0;
        pthread_mutex_init(&floors[i].wait_mutex, NULL);
        pthread_cond_init(&floors[i].wait_condition, NULL);
    }

    elevator.current_floor = 0;
    elevator.direction = 0;
    elevator.current_passengers = 0;
    pthread_mutex_init(&elevator.run_mutex, NULL);
    pthread_cond_init(&elevator.run_condition, NULL);

    pthread_create(&run_thread_id, NULL, run_thread, NULL);

    for (i = 0; i < 100; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&passenger_threads[i], NULL, passenger_thread, (void *) id);
    }

    pthread_join(run_thread_id, NULL);

    for (i = 0; i < 100; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    return 0;
}