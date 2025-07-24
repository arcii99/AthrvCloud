//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_COUNT 5

// The shared resource
int shared_resource = 0;

// Mutex lock for the shared resource
pthread_mutex_t lock;

// Thread function
void* thread_function(void* arg)
{
    int thread_id = *(int *) arg;
    int increment = 10 - thread_id * 2;

    printf("Thread %d started\n", thread_id);

    // Loop to access the shared resource 
    for (int i = 0; i < 5; i++) {
        
        // Lock the mutex before accessing the shared resource
        pthread_mutex_lock(&lock);
        
        shared_resource += increment;
        printf("Thread %d incremented the shared resource to %d\n", thread_id, shared_resource);
        
        // Unlock the mutex after accessing the shared resource
        pthread_mutex_unlock(&lock);
        
        // Sleep for a random time
        int sleep_time = rand() % 3;
        sleep(sleep_time);
    }

    printf("Thread %d finished\n", thread_id);

    pthread_exit(NULL);
}

int main()
{
    // Initialize the mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Error: failed to initialize mutex lock\n");
        return 1;
    }

    // Create an array to hold the thread IDs
    pthread_t threads[THREADS_COUNT];
    int thread_ids[THREADS_COUNT];

    // Create the threads
    for (int i = 0; i < THREADS_COUNT; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            printf("Error: failed to create thread %d\n", i);
            return 1;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < THREADS_COUNT; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error: failed to join thread %d\n", i);
            return 1;
        }
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}