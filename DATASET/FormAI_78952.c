//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: lively
// Welcome to the world of threading with our unique C Threading Library Implementation example program!

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;

// A thread function that increments a shared integer variable
void* increment(void* arg) {
    int* shared_int = (int*) arg;
    int i;

    for (i = 0; i < 5; i++) {
        // Lock the mutex so only one thread can access the shared integer at a time
        pthread_mutex_lock(&lock);

        (*shared_int)++;

        printf("Thread %lu is incrementing shared integer to %d\n", pthread_self(), *shared_int);

        // Unlock the mutex to allow other threads to access the shared integer
        pthread_mutex_unlock(&lock);

        usleep(500000); // Sleep for 0.5s to allow other threads to execute
    }

    pthread_exit(NULL);
}

// Main function that creates and joins two threads
int main() {
    pthread_t thread1, thread2;
    int shared_int = 0;

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create two threads that will execute the increment function with shared_int as argument
    if (pthread_create(&thread1, NULL, increment, (void*)&shared_int) != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        exit(1);
    }

    if (pthread_create(&thread2, NULL, increment, (void*)&shared_int) != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        exit(1);
    }

    // Wait for the threads to finish executing
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    printf("Final shared integer value: %d\n", shared_int);

    return 0;
}