//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: ephemeral
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 10
#define MAX_COUNT 20

// Define a global mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define a thread-safe counter
int counter = 0;

// Define the thread function
void *thread_func(void *thread_id)
{
    int tid = *(int*)thread_id;

    for (int i = 0; i < MAX_COUNT; i++)
    {
        // Acquire the lock
        pthread_mutex_lock(&mutex);

        // Update the counter
        counter++;

        // Print the counter value
        printf("Thread %d: Counter value is %d\n", tid, counter);

        // Release the lock
        pthread_mutex_unlock(&mutex);
    }

    // Return the thread result
    pthread_exit(NULL);
}

int main()
{
    // Define an array of thread ids
    pthread_t threads[NUM_THREADS];

    // Define an array of thread ids to pass to the thread function
    int thread_ids[NUM_THREADS];

    // Initialize the thread ids
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
    }

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, (void*)&thread_ids[i]);
    }

    // Wait for the threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}