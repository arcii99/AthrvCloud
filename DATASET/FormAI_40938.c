//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4

// Shared Data between threads
int sharedData = 0;

// Mutex Lock for synchronization
pthread_mutex_t sharedDataLock;

// Thread function that adds 1 to the shared data
void* addOne(void* arg) {
    // Lock the mutex so that only one thread can access sharedData at a time
    pthread_mutex_lock(&sharedDataLock);
    // Add 1 to sharedData
    sharedData += 1;
    printf("Thread %ld added 1 to sharedData. Current value is %d\n", (long)arg, sharedData);
    // Unlock the mutex
    pthread_mutex_unlock(&sharedDataLock);
    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Initialize the mutex lock
    pthread_mutex_init(&sharedDataLock, NULL);
    // Array of thread IDs
    pthread_t threads[THREAD_COUNT];
    // Create the threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, &addOne, (void*)(long)i);
    }
    // Wait for all threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    // Destroy the mutex lock
    pthread_mutex_destroy(&sharedDataLock);
    // Display the final value of sharedData
    printf("Final value of sharedData is %d\n", sharedData);
    return 0;
}