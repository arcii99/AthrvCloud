//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_SENSORS 10
#define NUM_SORTING_MACHINES 5
#define NUM_STORES 20

sem_t conveyor_mutex;
sem_t sensor[NUM_SENSORS];
sem_t sorting_machine[NUM_SORTING_MACHINES];
sem_t store[NUM_STORES];

void* sensor_thread(void* arg) {
    int id = *(int*) arg;
    while(1) {
        // generate a random bag and send it to the conveyor
        sem_wait(&sensor[id]);
        sem_wait(&conveyor_mutex);
        // send bag
        sem_post(&conveyor_mutex);
    }
}

void* sorting_machine_thread(void* arg) {
    int id = *(int*) arg;
    while(1) {
        // receive a bag from conveyor and sort it
        sem_wait(&sorting_machine[id]);
        sem_wait(&conveyor_mutex);
        // sort bag
        sem_post(&conveyor_mutex);
        sem_post(&store[id % NUM_STORES]); // send to a random store
    }
}

void* store_thread(void* arg) {
    int id = *(int*) arg;
    while(1) {
        // bag arrives at store
        sem_wait(&store[id]);
        // store the bag
    }
}

int main() {
    // initialize semaphores
    sem_init(&conveyor_mutex, 0, 1);
    for(int i = 0; i < NUM_SENSORS; i++) {
        sem_init(&sensor[i], 0, 0);
    }
    for(int i = 0; i < NUM_SORTING_MACHINES; i++) {
        sem_init(&sorting_machine[i], 0, 0);
    }
    for(int i = 0; i < NUM_STORES; i++) {
        sem_init(&store[i], 0, 0);
    }
    // create threads
    pthread_t sensor_threads[NUM_SENSORS];
    pthread_t sorting_machine_threads[NUM_SORTING_MACHINES];
    pthread_t store_threads[NUM_STORES];
    for(int i = 0; i < NUM_SENSORS; i++) {
        int* arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&sensor_threads[i], NULL, sensor_thread, arg);
    }
    for(int i = 0; i < NUM_SORTING_MACHINES; i++) {
        int* arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&sorting_machine_threads[i], NULL, sorting_machine_thread, arg);
    }
    for(int i = 0; i < NUM_STORES; i++) {
        int* arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&store_threads[i], NULL, store_thread, arg);
    }
    // join threads
    for(int i = 0; i < NUM_SENSORS; i++) {
        pthread_join(sensor_threads[i], NULL);
    }
    for(int i = 0; i < NUM_SORTING_MACHINES; i++) {
        pthread_join(sorting_machine_threads[i], NULL);
    }
    for(int i = 0; i < NUM_STORES; i++) {
        pthread_join(store_threads[i], NULL);
    }
    // destroy semaphores
    sem_destroy(&conveyor_mutex);
    for(int i = 0; i < NUM_SENSORS; i++) {
        sem_destroy(&sensor[i]);
    }
    for(int i = 0; i < NUM_SORTING_MACHINES; i++) {
        sem_destroy(&sorting_machine[i]);
    }
    for(int i = 0; i < NUM_STORES; i++) {
        sem_destroy(&store[i]);
    }
    return 0;
}