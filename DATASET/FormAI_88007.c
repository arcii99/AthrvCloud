//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define NUM_THREADS 2
#define BUFFER_SIZE 100

// Global variables
int buffer[BUFFER_SIZE];
size_t buffer_count = 0;
int finished = 0;

// Mutex declaration
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    int i;
    int item = 0;

    for (i = 0; i < BUFFER_SIZE; i++) {
        // Acquire mutex lock
        pthread_mutex_lock(&mutex);

        // Check if the buffer is full
        if (buffer_count == BUFFER_SIZE) {
            printf("Producer: buffer is full, waiting for consumer...\n");
            // Release the mutex lock
            pthread_mutex_unlock(&mutex);
            // Sleep for some time before trying again
            sleep(1);
            i--; // Try again with current i value
            continue;
        }

        // Add item to buffer
        buffer[buffer_count] = item;
        buffer_count++;

        printf("Producer: added item %d to buffer\n", item);
        item++;

        // Release the mutex lock
        pthread_mutex_unlock(&mutex);
    }

    // Set finished flag
    finished = 1;

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i;
    int item;

    while (!finished) {
        // Acquire mutex lock
        pthread_mutex_lock(&mutex);

        // Check if buffer is empty
        if (buffer_count == 0) {
            printf("Consumer: buffer is empty, waiting for producer...\n");
            // Release the mutex lock
            pthread_mutex_unlock(&mutex);
            // Sleep for some time before trying again
            sleep(1);
            continue;
        }

        // Remove item from buffer
        item = buffer[buffer_count - 1];
        buffer_count--;

        printf("Consumer: removed item %d from buffer\n", item);

        // Release the mutex lock
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(void) {
    int i;
    pthread_t threads[NUM_THREADS];

    // Create producer thread
    if (pthread_create(&threads[0], NULL, producer, NULL) != 0) {
        fprintf(stderr, "Error creating producer thread: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Create consumer thread
    if (pthread_create(&threads[1], NULL, consumer, NULL) != 0) {
        fprintf(stderr, "Error creating consumer thread: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    printf("Program finished successfully!\n");

    return 0;
}