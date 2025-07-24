//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: distributed
// This program simulates the baggage handling system in an airport using a distributed style

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of passengers and handlers
#define NUM_PASSENGERS 100
#define NUM_HANDLERS 5

// Declare a structure to represent the baggage of a passenger
struct baggage {
    int passenger_id;
    int weight;
};

// Declare a structure to represent the belt
struct belt {
    struct baggage *baggage;
    int occupied;
};

// Declare a structure to represent the scanner
struct scanner {
    struct baggage *baggage;
    int occupied;
    pthread_mutex_t lock;
};

// Declare a structure to represent the loading area
struct loading_area {
    struct baggage *baggage;
    int occupied;
    pthread_mutex_t lock;
};

// Declare global variables
struct baggage passenger_baggage[NUM_PASSENGERS];
struct belt baggage_belt = {NULL, 0};
struct scanner baggage_scanner = {NULL, 0, PTHREAD_MUTEX_INITIALIZER};
struct loading_area baggage_loading_area = {NULL, 0, PTHREAD_MUTEX_INITIALIZER};

// Declare functions
void *passenger(void *arg);
void *handler(void *arg);
void handle_baggage(struct baggage *baggage);
void scan_baggage(struct scanner *scanner);
void load_baggage(struct loading_area *loading_area);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create threads for the passengers and handlers
    pthread_t passenger_threads[NUM_PASSENGERS];
    pthread_t handler_threads[NUM_HANDLERS];
    int i;
    for (i = 0; i < NUM_PASSENGERS; i++) {
        passenger_baggage[i].passenger_id = i;
        passenger_baggage[i].weight = (rand() % 20) + 5;
        pthread_create(&passenger_threads[i], NULL, passenger, &passenger_baggage[i]);
    }
    for (i = 0; i < NUM_HANDLERS; i++) {
        pthread_create(&handler_threads[i], NULL, handler, NULL);
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_PASSENGERS; i++) {
        pthread_join(passenger_threads[i], NULL);
    }
    for (i = 0; i < NUM_HANDLERS; i++) {
        pthread_join(handler_threads[i], NULL);
    }

    return 0;
}

void *passenger(void *arg) {
    struct baggage *baggage = (struct baggage *)arg;
    printf("Passenger %d arrives at the airport with baggage weighing %d kg\n", baggage->passenger_id, baggage->weight);

    // Wait for the baggage belt to be available
    while (baggage_belt.occupied) {
        usleep(1000);
    }

    // Put the baggage on the belt
    baggage_belt.baggage = baggage;
    baggage_belt.occupied = 1;
    printf("Passenger %d puts their baggage on the belt\n", baggage->passenger_id);

    // Wait for the baggage to be scanned
    while (baggage_scanner.occupied) {
        usleep(1000);
    }

    // Send the baggage to the scanner
    baggage_scanner.baggage = baggage_belt.baggage;
    baggage_scanner.occupied = 1;
    baggage_belt.occupied = 0;
    printf("Passenger %d's baggage is sent to the scanner\n", baggage->passenger_id);

    // Wait for the baggage to be loaded onto the plane
    while (baggage_loading_area.occupied) {
        usleep(1000);
    }

    // Wait for the handler to load the baggage
    while (baggage_scanner.occupied) {
        usleep(1000);
    }

    // Put the baggage in the loading area
    baggage_loading_area.baggage = baggage_scanner.baggage;
    baggage_loading_area.occupied = 1;
    baggage_scanner.occupied = 0;
    printf("Passenger %d's baggage is loaded onto the plane\n", baggage->passenger_id);

    return NULL;
}

void *handler(void *arg) {
    while (1) {
        // Wait for baggage to be scanned
        while (!baggage_scanner.occupied) {
            usleep(1000);
        }

        // Handle the baggage
        handle_baggage(baggage_scanner.baggage);
        baggage_scanner.baggage = NULL;
        baggage_scanner.occupied = 0;
    }
}

void handle_baggage(struct baggage *baggage) {
    printf("Handler handles baggage from passenger %d\n", baggage->passenger_id);
    scan_baggage(&baggage_scanner);
    load_baggage(&baggage_loading_area);
}

void scan_baggage(struct scanner *scanner) {
    pthread_mutex_lock(&scanner->lock);
    printf("Scanner scans baggage from passenger %d\n", scanner->baggage->passenger_id);
    pthread_mutex_unlock(&scanner->lock);
}

void load_baggage(struct loading_area *loading_area) {
    pthread_mutex_lock(&loading_area->lock);
    printf("Handler loads baggage from passenger %d onto the plane\n", loading_area->baggage->passenger_id);
    loading_area->baggage = NULL;
    loading_area->occupied = 0;
    pthread_mutex_unlock(&loading_area->lock);
}