//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Declare a global variable that will be shared between threads
int shared_variable = 0;

// Declare a mutex to control access to the shared variable
pthread_mutex_t mutex;

// Define a function for the first thread to run
void* increment(void* arg) {
    int i;
    
    // Lock the mutex to access the shared variable
    pthread_mutex_lock(&mutex);
    
    // Increment the shared variable 10 times
    for (i = 0; i < 10; i++) {
        shared_variable++;
        printf("Incremented to %d\n", shared_variable);
    }
    
    // Unlock the mutex to release access to the shared variable
    pthread_mutex_unlock(&mutex);
    
    // Terminate the thread
    pthread_exit(NULL);
}

// Define a function for the second thread to run
void* decrement(void* arg) {
    int i;
    
    // Lock the mutex to access the shared variable
    pthread_mutex_lock(&mutex);
    
    // Decrement the shared variable 10 times
    for (i = 0; i < 10; i++) {
        shared_variable--;
        printf("Decremented to %d\n", shared_variable);
    }
    
    // Unlock the mutex to release access to the shared variable
    pthread_mutex_unlock(&mutex);
    
    // Terminate the thread
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);
    
    // Create the two threads
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);
    
    // Wait for both threads to finish executing
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Destroy the mutex
    pthread_mutex_destroy(&mutex);
    
    // Print the final value of the shared variable
    printf("Final value of shared variable: %d\n", shared_variable);
    
    // Exit the program
    return 0;
}