//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: active
// C Threading Library Implementation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 4

// Define the shared resource
int shared_resource = 0;

// Define the mutex lock
pthread_mutex_t mutex_lock;

// Define the thread function
void* thread_function(void* thread_id) {
    int id = *(int*)thread_id;
    printf("Thread %d has started\n", id);
    
    // Acquire the mutex lock
    pthread_mutex_lock(&mutex_lock);
    
    // Modify the shared resource
    for (int i = 0; i < 5; i++) {
        printf("Thread %d is modifying the shared resource...\n", id);
        shared_resource++;
    }
    
    // Release the mutex lock
    pthread_mutex_unlock(&mutex_lock);
    
    printf("Thread %d has finished\n", id);
    pthread_exit(NULL);
}

int main() {
    // Declare the array of threads
    pthread_t threads[NUM_THREADS];
    
    // Declare the array of thread IDs
    int thread_ids[NUM_THREADS];
    
    // Initialize the mutex lock
    pthread_mutex_init(&mutex_lock, NULL);
    
    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
        if (rc) {
            printf("Error: Return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }
    
    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print the final value of the shared resource
    printf("The final value of the shared resource is %d\n", shared_resource);
    
    // Destroy the mutex lock
    pthread_mutex_destroy(&mutex_lock);
    
    return 0;
}