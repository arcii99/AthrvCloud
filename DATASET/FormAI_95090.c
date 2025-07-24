//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Define a struct to hold the mutex and shared data */
typedef struct {
    pthread_mutex_t mutex;
    int sharedData;
} SharedData;

/* Define a thread function to increment the shared data */
void *increment(void *data) {
    SharedData *shared = (SharedData*) data;
    int i;
    for (i = 0; i < 100000; i++) {
        /* Lock the mutex to safely access sharedData */
        pthread_mutex_lock(&shared->mutex);
        shared->sharedData++;
        /* Unlock the mutex to allow other threads to access sharedData */
        pthread_mutex_unlock(&shared->mutex);
    }
    pthread_exit(NULL);
}

int main() {
    /* Initialize the shared data */
    SharedData shared;
    shared.sharedData = 0;
    /* Initialize the mutex */
    pthread_mutex_init(&shared.mutex, NULL);
    
    /* Create the threads */
    pthread_t thread1, thread2;
    int rc;
    if ((rc = pthread_create(&thread1, NULL, increment, (void*) &shared))) {
        fprintf(stderr, "Error creating thread 1: %d\n", rc);
        exit(EXIT_FAILURE);
    }
    if ((rc = pthread_create(&thread2, NULL, increment, (void*) &shared))) {
        fprintf(stderr, "Error creating thread 2: %d\n", rc);
        exit(EXIT_FAILURE);
    }
    
    /* Wait for the threads to finish */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    /* Destroy the mutex */
    pthread_mutex_destroy(&shared.mutex);
    
    /* Print the final value of sharedData */
    printf("Final value of sharedData: %d\n", shared.sharedData);
    
    return 0;
}