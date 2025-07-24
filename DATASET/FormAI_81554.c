//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a shared counter variable
int shared_counter = 0;

// Define mutex to protect the counter
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to increment the counter
void *increment_counter(void *thread_id) {
    // Acquire the lock
    pthread_mutex_lock(&mutex);
    
    // Increment the shared counter
    shared_counter++;

    // Print the new value of the shared counter
    printf("Thread %ld: shared counter = %d\n", (long)thread_id, shared_counter);

    // Release the lock
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main() {
    // Define variables to hold the thread IDs and pointers
    pthread_t thread_ids[5];
    int i;

    // Create 5 threads
    for(i=0; i<5; i++) {
        pthread_create(&thread_ids[i], NULL, increment_counter, (void *)i+1);
    }

    // Wait for all threads to complete
    for(i=0; i<5; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // Print the final value of the shared counter
    printf("Final shared counter value = %d\n", shared_counter);

    // Exit the program
    exit(0);
}