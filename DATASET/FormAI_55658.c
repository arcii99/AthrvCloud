//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        int *thread_num = (int *) malloc(sizeof(int)); // Allocate memory for thread number
        *thread_num = i;
        pthread_create(&threads[i], NULL, thread_function, (void *) thread_num); // Create thread with thread number as argument
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to finish executing
    }

    printf("Final counter value: %d\n", counter); // Print final value of counter variable
    pthread_mutex_destroy(&mutex1); // Destroy mutex
    return 0;
}

void *thread_function(void *arg) {
    int thread_num = *((int *) arg);
    printf("Thread %d starting...\n", thread_num);
    free(arg); // Free memory allocated for thread number
    int i;

    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex1); // Lock mutex
        counter++; // Increment counter
        pthread_mutex_unlock(&mutex1); // Unlock mutex
        printf("Thread %d counter value: %d\n", thread_num, counter);
    }

    printf("Thread %d exiting...\n", thread_num);
    pthread_exit(NULL);
}