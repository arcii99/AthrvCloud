//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void* printHello(void* threadID) {
    long tid = *(long*)threadID;
    printf("Thread %ld: Hello, world!\n", tid);
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // create threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);

        rc = pthread_create(&threads[t], NULL, printHello, (void*)&t);

        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1); // exit program
        }
    }

    // wait for threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads have completed their tasks.\n");

    pthread_exit(NULL);
    return 0;
}