//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

int counter = 0;
pthread_mutex_t mutex;

void *increment_counter(void *thread_id) {
    long tid = (long) thread_id;
    // Acquire the lock to execute the critical section
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread %ld incremented counter to %d\n", tid, counter);
    // Release the lock after executing the critical section
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    // Initialize the mutex lock
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for (long t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, increment_counter, (void *) t);
        if (rc) {
            printf("ERROR; pthread_create() returned %d\n", rc);
            exit(-1);
        }
    }

    // Join threads
    for (long t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR; pthread_join() returned %d\n", rc);
            exit(-1);
        }
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&mutex);

    printf("Final value of counter: %d\n", counter);

    pthread_exit(NULL);
}