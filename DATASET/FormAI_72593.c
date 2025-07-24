//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ARRAY_SIZE 1000

int array[ARRAY_SIZE];
int key = 42;
int result = -1;

pthread_mutex_t lock;

struct ThreadData {
    int thread_id;
    int start;
    int end;
};

void *searchArray(void *arg) {
    struct ThreadData *data;
    data = (struct ThreadData *) arg;

    int start = data->start;
    int end = data->end;
    int i = start;

    while(i < end && result == -1) {
        if(array[i] == key) {
            pthread_mutex_lock(&lock);
            result = i;
            pthread_mutex_unlock(&lock);
        }
        i++;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData[NUM_THREADS];

    // Fill array with random integers
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }

    // Divide array into sections for each thread
    int sectionSize = ARRAY_SIZE / NUM_THREADS;
    for(int i = 0; i < NUM_THREADS; i++) {
        threadData[i].thread_id = i;
        threadData[i].start = i * sectionSize;
        threadData[i].end = (i + 1) * sectionSize;

        if(i == NUM_THREADS - 1) {
            threadData[i].end = ARRAY_SIZE;
        }
    }

    // Create threads to search array
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, searchArray, &threadData[i]);
    }

    // Wait for threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print result
    if(result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    pthread_exit(NULL);
}