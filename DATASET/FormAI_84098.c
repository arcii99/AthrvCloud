//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

//common variables for elevator
#define MAX_FLOOR 10
#define MIN_FLOOR 0
#define MAX_USERS 10

int current_floor = 0;
int destinations[MAX_USERS];
int num_passengers = 0;

//mutex locks for elevator access
pthread_mutex_t elevator_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t passenger_lock = PTHREAD_MUTEX_INITIALIZER;

//condition variables for elevator and passengers
pthread_cond_t elevator_move = PTHREAD_COND_INITIALIZER;
pthread_cond_t elevator_arrive = PTHREAD_COND_INITIALIZER;
pthread_cond_t passenger_queue = PTHREAD_COND_INITIALIZER;

//passenger struct
struct passenger {
    int id;
    int from_floor;
    int to_floor;
    int on_elevator;
};

//functions for elevator and passengers
void *elevator_function(void *arg);
void *passenger_function(void *arg);

int main() {
    //initialize elevator thread
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_function, NULL);
    printf("Elevator thread created!\n");

    //initialize passenger threads
    pthread_t passenger_threads[MAX_USERS];
    struct passenger passengers[MAX_USERS];

    for (int i = 0; i < MAX_USERS; i++) {
        passengers[i].id = i;
        passengers[i].from_floor = rand() % MAX_FLOOR;
        passengers[i].to_floor = rand() % MAX_FLOOR;
        passengers[i].on_elevator = 0;
        pthread_create(&passenger_threads[i], NULL, passenger_function, (void *) &passengers[i]);
        printf("Passenger thread %d created!\n", i);
        sleep(1);
    }

    //join passenger threads
    for (int i = 0; i < MAX_USERS; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    //cancel elevator thread
    pthread_cancel(elevator_thread);

    return 0;
}

void *elevator_function(void *arg) {
    while (1) { //infinite loop for elevator movement
        //wait for passengers to queue
        pthread_mutex_lock(&passenger_lock);
        while (num_passengers == 0) {
            pthread_cond_wait(&passenger_queue, &passenger_lock);
        }

        //load passengers on elevator
        pthread_mutex_lock(&elevator_lock);
        for (int i = 0; i < num_passengers; i++) {
            destinations[i] = rand() % MAX_FLOOR;
            pthread_cond_signal(&elevator_move);
        }
        pthread_mutex_unlock(&elevator_lock);

        //wait for elevator to arrive at destination floor
        pthread_mutex_lock(&elevator_lock);
        while (current_floor != destinations[num_passengers - 1]) {
            pthread_cond_wait(&elevator_arrive, &elevator_lock);
        }

        //unload passengers from elevator
        pthread_mutex_lock(&passenger_lock);
        num_passengers = 0;
        pthread_mutex_unlock(&passenger_lock);

        printf("Elevator has arrived at floor %d!\n", current_floor);
    }
}

void *passenger_function(void *arg) {
    //access passenger struct
    struct passenger *passenger = (struct passenger *) arg;

    //queue up for elevator
    pthread_mutex_lock(&passenger_lock);
    printf("Passenger %d has queued up at floor %d!\n", passenger->id, passenger->from_floor);
    num_passengers++;
    pthread_cond_signal(&passenger_queue);
    pthread_mutex_unlock(&passenger_lock);

    //wait for elevator to arrive at destination floor
    pthread_mutex_lock(&elevator_lock);
    while (passenger->on_elevator == 0 && current_floor != passenger->from_floor) {
        pthread_cond_wait(&elevator_move, &elevator_lock);
    }

    //get on elevator
    passenger->on_elevator = 1;
    printf("Passenger %d has boarded the elevator at floor %d!\n", passenger->id, passenger->from_floor);

    //wait for elevator to arrive at destination floor
    while (current_floor != passenger->to_floor) {
        pthread_cond_wait(&elevator_arrive, &elevator_lock);
    }

    //get off elevator
    passenger->on_elevator = 0;
    printf("Passenger %d has arrived at floor %d!\n", passenger->id, passenger->to_floor);

    //update elevator that passenger has arrived
    pthread_mutex_lock(&passenger_lock);
    num_passengers--;
    pthread_mutex_unlock(&passenger_lock);

    pthread_mutex_unlock(&elevator_lock);
}