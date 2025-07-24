//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

// Shared bounded buffer
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;

// Mutex lock for buffer
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variables for buffer
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER;

// Function declarations
void *producer(void *args);
void *consumer(void *args);

int main()
{
    // Initialize pthreads
    pthread_t producer_thread, consumer_thread;

    // Create producer thread
    if (pthread_create(&producer_thread, NULL, producer, NULL) != 0) {
        fprintf(stderr, "Error creating producer thread\n");
        return EXIT_FAILURE;
    }

    // Create consumer thread
    if (pthread_create(&consumer_thread, NULL, consumer, NULL) != 0) {
        fprintf(stderr, "Error creating consumer thread\n");
        return EXIT_FAILURE;
    }

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return EXIT_SUCCESS;
}

void *producer(void *args)
{
    int item;

    for (int i = 0; i < 20; i++) {
        // Generate item
        item = rand() % 100;

        // Lock buffer
        pthread_mutex_lock(&mutex);

        // Wait until buffer not full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&buffer_not_full, &mutex);
        }

        // Add item to buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        printf("Produced item: %d\n", item);

        // Signal consumer that buffer not empty
        pthread_cond_signal(&buffer_not_empty);

        // Unlock buffer
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void *consumer(void *args)
{
    int item;

    for (int i = 0; i < 20; i++) {
        // Lock buffer
        pthread_mutex_lock(&mutex);

        // Wait until buffer not empty
        while (count == 0) {
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }

        // Remove item from buffer
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;

        printf("Consumed item: %d\n", item);

        // Signal producer that buffer not full
        pthread_cond_signal(&buffer_not_full);

        // Unlock buffer
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}