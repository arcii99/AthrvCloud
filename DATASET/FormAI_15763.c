//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0; // global variable to be incremented by threads
pthread_mutex_t lock; // mutex lock to synchronize access to the counter

// function to be executed by threads
void* thread_function(void* arg) {
    // acquire the lock before accessing the counter
    pthread_mutex_lock(&lock);
    
    // increment the counter
    counter++;
    
    // release the lock
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main() {
    // initialize the mutex lock
    pthread_mutex_init(&lock, NULL);
    
    // create threads
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }
    
    // wait for threads to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // display the final value of the counter
    printf("Final counter value: %d\n", counter);
    
    // destroy the mutex lock
    pthread_mutex_destroy(&lock);
    
    return 0;
}