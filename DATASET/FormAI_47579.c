//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BAGGAGE 5 // Maximum number of baggage a passenger can carry
#define MAX_PASSENGERS 10 // Maximum number of passengers in the airport
#define MAX_CHECKIN_DESKS 2 // Maximum number of check-in desks in the airport
#define MAX_BELTS 2 // Maximum number of baggage belts in the airport
#define MAX_CONVEYORS 2 // Maximum number of baggage conveyors in the airport

// Thread synchronization variables
pthread_mutex_t checkin_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t belt_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t conveyor_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t conveyor_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t passenger_checkin_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t belt_space_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t conveyor_space_cond_1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t conveyor_space_cond_2 = PTHREAD_COND_INITIALIZER;

// Global variables for tracking the state of the airport
int checkin_desks_available = MAX_CHECKIN_DESKS;
int baggage_on_belt = 0;
int baggage_on_conveyor_1 = 0;
int baggage_on_conveyor_2 = 0;

// Function prototypes
void *passenger(void *arg);
void *checkin_desk(void *arg);
void *baggage_belt(void *arg);
void *conveyor_1(void *arg);
void *conveyor_2(void *arg);

// Structure declaration for passenger thread arguments
typedef struct {
    int id;
    int num_baggage;
} passenger_args_t;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare the thread variables
    pthread_t passenger_threads[MAX_PASSENGERS];
    pthread_t checkin_threads[MAX_CHECKIN_DESKS];
    pthread_t belt_thread;
    pthread_t conveyor_thread_1, conveyor_thread_2;

    // Initialize the passenger thread arguments
    passenger_args_t passenger_args[MAX_PASSENGERS];
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        passenger_args[i].id = i;
        passenger_args[i].num_baggage = rand() % MAX_BAGGAGE + 1;
    }

    // Create the passenger threads
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        pthread_create(&passenger_threads[i], NULL, passenger, &passenger_args[i]);
    }

    // Create the check-in desk threads
    for (int i = 0; i < MAX_CHECKIN_DESKS; i++) {
        pthread_create(&checkin_threads[i], NULL, checkin_desk, NULL);
    }

    // Create the baggage belt thread
    pthread_create(&belt_thread, NULL, baggage_belt, NULL);

    // Create the conveyor threads
    pthread_create(&conveyor_thread_1, NULL, conveyor_1, NULL);
    pthread_create(&conveyor_thread_2, NULL, conveyor_2, NULL);

    // Wait for all threads to finish
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        pthread_join(passenger_threads[i], NULL);
    }
    for (int i = 0; i < MAX_CHECKIN_DESKS; i++) {
        pthread_join(checkin_threads[i], NULL);
    }
    pthread_join(belt_thread, NULL);
    pthread_join(conveyor_thread_1, NULL);
    pthread_join(conveyor_thread_2, NULL);

    return 0;
}

// Function for passenger thread
void *passenger(void *arg) {
    passenger_args_t *args = arg;
    printf("Passenger %d arrives in airport with %d bags\n", args->id, args->num_baggage);

    // Wait for a check-in desk to become available
    pthread_mutex_lock(&checkin_mutex);
    while (checkin_desks_available == 0) {
        pthread_cond_wait(&passenger_checkin_cond, &checkin_mutex);
    }

    // Use a check-in desk
    checkin_desks_available--;
    pthread_mutex_unlock(&checkin_mutex);
    printf("Passenger %d is using a check-in desk\n", args->id);

    // Wait for baggage belt space to become available and place bags on the belt
    pthread_mutex_lock(&belt_mutex);
    while (baggage_on_belt + args->num_baggage > MAX_BAGGAGE * MAX_PASSENGERS) {
        pthread_cond_wait(&belt_space_cond, &belt_mutex);
    }
    baggage_on_belt += args->num_baggage;
    pthread_mutex_unlock(&belt_mutex);
    printf("Passenger %d places %d bags on the baggage belt\n", args->id, args->num_baggage);

    // Wait for conveyors to become available and place bags on a conveyor
    int conveyor_num = rand() % 2 + 1;
    if (conveyor_num == 1) { // Use conveyor 1
        pthread_mutex_lock(&conveyor_mutex_1);
        while (baggage_on_conveyor_1 + args->num_baggage > MAX_BAGGAGE * MAX_PASSENGERS) {
            pthread_cond_wait(&conveyor_space_cond_1, &conveyor_mutex_1);
        }
        baggage_on_conveyor_1 += args->num_baggage;
        pthread_mutex_unlock(&conveyor_mutex_1);
        printf("Passenger %d places %d bags on conveyor 1\n", args->id, args->num_baggage);
    } else { // Use conveyor 2
        pthread_mutex_lock(&conveyor_mutex_2);
        while (baggage_on_conveyor_2 + args->num_baggage > MAX_BAGGAGE * MAX_PASSENGERS) {
            pthread_cond_wait(&conveyor_space_cond_2, &conveyor_mutex_2);
        }
        baggage_on_conveyor_2 += args->num_baggage;
        pthread_mutex_unlock(&conveyor_mutex_2);
        printf("Passenger %d places %d bags on conveyor 2\n", args->id, args->num_baggage);
    }

    // Signal that check-in desk is available
    pthread_mutex_lock(&checkin_mutex);
    checkin_desks_available++;
    pthread_cond_signal(&passenger_checkin_cond);
    pthread_mutex_unlock(&checkin_mutex);

    pthread_exit(NULL);
}

// Function for check-in desk thread
void *checkin_desk(void *arg) {
    while (1) {
        pthread_mutex_lock(&checkin_mutex);
        while (checkin_desks_available == MAX_CHECKIN_DESKS) {
            pthread_cond_wait(&passenger_checkin_cond, &checkin_mutex);
        }
        checkin_desks_available++;
        pthread_cond_broadcast(&passenger_checkin_cond);
        pthread_mutex_unlock(&checkin_mutex);

        sleep(1);
    }
}

// Function for baggage belt thread
void *baggage_belt(void *arg) {
    while (1) {
        pthread_mutex_lock(&belt_mutex);
        if (baggage_on_belt > 0) {
            baggage_on_belt--;
            pthread_cond_signal(&belt_space_cond);
        }
        pthread_mutex_unlock(&belt_mutex);

        sleep(1);
    }
}

// Function for conveyor 1 thread
void *conveyor_1(void *arg) {
    while (1) {
        pthread_mutex_lock(&conveyor_mutex_1);
        if (baggage_on_conveyor_1 > 0) {
            baggage_on_conveyor_1--;
            pthread_cond_signal(&conveyor_space_cond_1);
        }
        pthread_mutex_unlock(&conveyor_mutex_1);

        sleep(1);
    }
}

// Function for conveyor 2 thread
void *conveyor_2(void *arg) {
    while (1) {
        pthread_mutex_lock(&conveyor_mutex_2);
        if (baggage_on_conveyor_2 > 0) {
            baggage_on_conveyor_2--;
            pthread_cond_signal(&conveyor_space_cond_2);
        }
        pthread_mutex_unlock(&conveyor_mutex_2);

        sleep(1);
    }
}