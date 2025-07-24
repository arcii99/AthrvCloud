//FormAI DATASET v1.0 Category: Funny ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

// Define the struct for passing data to the threaded function
typedef struct {
    int thread_id;
    int sleep_time;
} ThreadData;

// Define the threaded function
void* SleepyThread(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    printf("Thread %d is going to sleep for %d seconds.\n", data->thread_id, data->sleep_time);
    sleep(data->sleep_time);
    printf("Thread %d has woken up after sleeping for %d seconds.\n", data->thread_id, data->sleep_time);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    ThreadData data[NUM_THREADS];
    
    // Initialize the thread data
    for (t = 0; t < NUM_THREADS; t++) {
        data[t].thread_id = t;
        data[t].sleep_time = rand() % 10 + 1; // Randomly choose a sleep time between 1 and 10 seconds
    }
    
    // Create the threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %d.\n", t);
        rc = pthread_create(&threads[t], NULL, SleepyThread, (void*) &data[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    // Wait for the threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
        printf("Thread %d has finished.\n", t);
    }
    
    printf("All threads have finished.\n");
    pthread_exit(NULL);
}