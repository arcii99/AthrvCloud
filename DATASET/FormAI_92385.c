//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
/* Welcome to the Threading Library! 
Here, we have created a unique implementation of a threading library in C.
Our library allows multiple threads to run simultaneously on a single processor, making programming efficient and fun! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 // the number of threads we want to create
#define MAX_COUNT 10 // the max count the threads will increment to
int count = 0; // global count variable that all threads will modify

void *threadFunction(void *id) {
    int tid = (int)id; // casting the thread ID to an int
    printf("Thread #%d starting...\n", tid);

    for (int i = 0; i < MAX_COUNT; i++) { // increment count variable MAX_COUNT times
        count++; // increment count by 1
        printf("Thread #%d: count = %d\n", tid, count);
    }

    printf("Thread #%d finished.\n", tid);
    pthread_exit(NULL); // exit the thread
}

int main() {
    pthread_t threads[NUM_THREADS]; // array of threads
    int tids[NUM_THREADS]; // array of thread IDs

    printf("Creating %d threads...\n", NUM_THREADS);
    for (int i = 0; i < NUM_THREADS; i++) {
        tids[i] = i + 1; // set the thread ID to its index + 1
        pthread_create(&threads[i], NULL, threadFunction, (void *)tids[i]); // create the threads
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL); // join the threads back together after they finish
    }

    printf("Total count: %d\n", count);
    printf("Main thread exiting.\n");

    return 0;
}