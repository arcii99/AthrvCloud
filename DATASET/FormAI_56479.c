//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: retro
/* Retro Style Threading Library Implementation */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

// Define thread struct
typedef struct {
    pthread_t tid;   // tid is the thread id
    int n;           // n is the thread number
} thread_data;

// Define global counter variable
int counter = 0;

// Define thread function
void *thread_func(void *arg) {
    int n = ((thread_data*) arg)->n;
    printf("Thread %d started\n", n);

    // Simulate some work
    int rand_num = rand() % 10 + 1;
    printf("Thread %d performing work for %d seconds\n", n, rand_num);
    sleep(rand_num);

    // Update the global counter
    printf("Thread %d updating counter\n", n);
    counter++;

    printf("Thread %d completed\n", n);
    return NULL;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare an array of thread_data structs
    thread_data threads[5];

    // Create 5 threads
    for (int i = 0; i < 5; i++) {
        threads[i].n = i;
        pthread_create(&threads[i].tid, NULL, thread_func, &threads[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i].tid, NULL);
    }

    // Print the final value of the counter
    printf("Final counter value: %d\n", counter);

    return 0;
}