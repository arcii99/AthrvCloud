//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Define some global variables and constants */
#define NUM_THREADS 5    // Number of threads to create
int counter = 0;         // Global counter
pthread_mutex_t mutex;   // Mutex to protect access to the counter

/* The thread function */
void *threadFunc(void *arg) {
    int tid = *((int *) arg);    // Get the thread ID

    // Loop 10 times and increment the counter
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);     // Lock the mutex
        counter++;                      // Increment the counter
        printf("Thread %d: counter = %d\n", tid, counter);
        pthread_mutex_unlock(&mutex);   // Unlock the mutex
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];   // Array of thread IDs
    int threadIds[NUM_THREADS];       // Array of thread IDs (for passing as arguments)

    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Error initializing mutex!\n");
        return 1;
    }

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i + 1;
        if (pthread_create(&threads[i], NULL, threadFunc, &threadIds[i]) != 0) {
            printf("Error creating thread %d!\n", i+1);
            return 1;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread %d!\n", i+1);
            return 1;
        }
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}