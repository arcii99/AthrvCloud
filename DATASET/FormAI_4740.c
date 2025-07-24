//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BAGS 100
#define THREADS_COUNT 5

typedef struct {
    int bag_number;
    int weight;
} Baggage;

Baggage baggage_queue[MAX_BAGS]; // Global queue to hold the bags

pthread_mutex_t baggage_mutex;

sem_t bag_count;
sem_t conveyor_space;

int index_in = 0; // Conveyor input pointer
int index_out = 0; // Conveyor output pointer

void *passenger_handler(void *arg) {
    int i, passenger_id = *(int *) arg;

    while (1) {
        sem_wait(&bag_count); // Decrement number of bags
        pthread_mutex_lock(&baggage_mutex); // Lock mutex for modification
        Baggage bag = baggage_queue[index_out % MAX_BAGS]; // Get the next bag in the queue
        index_out++; // Move the output pointer to the next bag

        printf("Passenger %d got baggage number %d, with weight %d kgs\n", 
            passenger_id, bag.bag_number, bag.weight);

        pthread_mutex_unlock(&baggage_mutex); // Unlock mutex
        sem_post(&conveyor_space); // Increment the number of empty spaces in the conveyor belt

        // Simulate processing the bag
        int wait_time = rand() % 3 + 1;
        sleep(wait_time);
    }
}

void *conveyor_handler(void *arg) {
    int i, conveyor_id = *(int *) arg;

    while (1) {
        sem_wait(&conveyor_space); // Decrement the number of empty spaces
        pthread_mutex_lock(&baggage_mutex); // Modify the queue
        Baggage new_bag;
        new_bag.bag_number = index_in + 1;
        new_bag.weight = rand() % 20 + 5; // Random weight between 5 - 24 kgs
        baggage_queue[index_in % MAX_BAGS] = new_bag; // Add the bag to the queue
        index_in++; // Move the input pointer to the next slot

        printf("Conveyor %d added baggage number %d, with weight %d kgs\n", 
            conveyor_id, new_bag.bag_number, new_bag.weight);

        pthread_mutex_unlock(&baggage_mutex); // Unlock the mutex
        sem_post(&bag_count); // Increment the number of bags in the queue

        // Simulate the time to add the bag
        int wait_time = rand() % 2;
        sleep(wait_time);
    }
}

int main() {
    int i, passenger_ids[THREADS_COUNT], conveyor_ids[THREADS_COUNT];
    pthread_t passenger_threads[THREADS_COUNT], conveyor_threads[THREADS_COUNT];

    // Initialize mutex and semaphores
    pthread_mutex_init(&baggage_mutex, NULL);
    sem_init(&bag_count, 0, 0);
    sem_init(&conveyor_space, 0, MAX_BAGS);

    // Start passenger threads
    for (i = 0; i < THREADS_COUNT; i++) {
        passenger_ids[i] = i;
        pthread_create(&passenger_threads[i], NULL, passenger_handler, &passenger_ids[i]);
    }

    // Start conveyor threads
    for (i = 0; i < THREADS_COUNT; i++) {
        conveyor_ids[i] = i;
        pthread_create(&conveyor_threads[i], NULL, conveyor_handler, &conveyor_ids[i]);
    }

    // Join threads
    for (i = 0; i < THREADS_COUNT; i++) {
        pthread_join(passenger_threads[i], NULL);
        pthread_join(conveyor_threads[i], NULL);
    }

    // Cleanup mutex and semaphores
    pthread_mutex_destroy(&baggage_mutex);
    sem_destroy(&bag_count);
    sem_destroy(&conveyor_space);

    return 0;
}