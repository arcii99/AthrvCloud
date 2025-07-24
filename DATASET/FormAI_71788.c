//FormAI DATASET v1.0 Category: Funny ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *threadnum) {
    int *tnum;
    tnum = (int *) threadnum;
    printf("Thread #%d reporting for duty!\n", *tnum);
    free(tnum); // free the allocated memory
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[NUM_THREADS];
    int *tnums[NUM_THREADS];

    // create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        tnums[i] = malloc(sizeof(int)); // allocate memory for the thread number
        *tnums[i] = i; // set the thread number
        pthread_create(&threads[i], NULL, print_message, (void *) tnums[i]); // create the thread
    }

    // wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed!\n");

    return 0;
}