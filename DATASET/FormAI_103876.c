//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: modular
#include <stdio.h>
#include <pthread.h>

// Declare the mutex variable
pthread_mutex_t lock;

void* thread_function(void* arg) {
    int i, num = *(int*)arg;
    for (i = 0; i < 5; i++) {
        // Lock the mutex before accessing the shared resource
        pthread_mutex_lock(&lock);
        printf("Thread %d enters the critical section\n", num);
        sleep(1);
        printf("Thread %d leaves the critical section\n", num);
        // Unlock the mutex after accessing the shared resource
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_1, thread_2;
    int value_1 = 1, value_2 = 2;
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);
    // Create the first thread
    pthread_create(&thread_1, NULL, thread_function, &value_1);
    // Create the second thread
    pthread_create(&thread_2, NULL, thread_function, &value_2);
    // Wait for both threads to finish
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    // Destroy the mutex
    pthread_mutex_destroy(&lock);
    return 0;
}