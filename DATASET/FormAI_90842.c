//FormAI DATASET v1.0 Category: Scientific ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h> 

// Global variables
int counter = 0;
bool is_running = true;
pthread_mutex_t lock;

// Thread function
void *increment_counter(void *arg) {
    while(is_running) {
        pthread_mutex_lock(&lock); // Lock the mutex
        counter++;
        printf("Counter incremented to: %d by Thread %d\n", counter, *(int*)arg);
        pthread_mutex_unlock(&lock); // Unlock the mutex
        usleep(500000); // Sleep for 500ms
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    int thread1_id = 1, thread2_id = 2;
    // Create threads
    if (pthread_create(&thread1, NULL, increment_counter, &thread1_id) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }
    if (pthread_create(&thread2, NULL, increment_counter, &thread2_id) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }

    // Sleep for 5 seconds
    sleep(5);

    // Stop the threads
    is_running = false;

    // Join threads
    if (pthread_join(thread1, NULL) != 0) {
        printf("Thread joining failed.\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        printf("Thread joining failed.\n");
        return 1;
    }

    printf("Counter Value: %d\n", counter);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}