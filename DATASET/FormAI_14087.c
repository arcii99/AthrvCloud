//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Struct to hold information about thread creation
typedef struct thread_data_struct {
    int thread_id;
    int sleep_time;
} thread_data_t;

// Mutex lock to protect the shared resource
pthread_mutex_t lock;

// Shared resource
int counter = 0;

// Function for the thread to execute
void* thread_function(void* thread_data)
{
    thread_data_t* data = (thread_data_t*) thread_data;

    printf("Thread %d starting...\n", data->thread_id);
    usleep(data->sleep_time); // Sleeps for some time

    // Critical Section (Accessing the shared resource)
    pthread_mutex_lock(&lock); // Locks the shared resource
    counter++; // Increments the counter
    printf("Thread %d incremented counter to %d\n", data->thread_id, counter);
    pthread_mutex_unlock(&lock); // Unlocks the shared resource

    printf("Thread %d exiting...\n", data->thread_id);
    pthread_exit(NULL);
}

int main()
{
    // Initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    pthread_t threads[5];
    thread_data_t thread_data[5];

    int i;
    for (i = 0; i < 5; i++) {
        thread_data[i].thread_id = i+1;
        thread_data[i].sleep_time = (i+1)*100000;

        // Create a new thread
        int rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_data[i]);
        if (rc) {
            printf("ERROR: Unable to create thread %d\n", i+1);
            exit(1);
        }
    }

    // Wait for threads to complete
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", counter);

    // Destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}