//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Declare a global int variable x
int x = 0;

// Define the mutex lock
pthread_mutex_t lock;

void *increment_x(void *arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        // Lock the mutex before accessing the shared variable x
        pthread_mutex_lock(&lock);
        x++;
        // Unlock the mutex after accessing the shared variable x
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *decrement_x(void *arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        // Lock the mutex before accessing the shared variable x
        pthread_mutex_lock(&lock);
        x--;
        // Unlock the mutex after accessing the shared variable x
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);

    printf("x before threads: %d\n", x);

    // Create two threads to manipulate x
    pthread_create(&t1, NULL, increment_x, NULL);
    pthread_create(&t2, NULL, decrement_x, NULL);

    // Wait for the threads to finish execution
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("x after threads: %d\n", x);

    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}