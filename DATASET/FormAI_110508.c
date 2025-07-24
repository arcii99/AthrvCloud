//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // This is the Threading Library we are using

#define NUM_THREADS 5

void *printHello(void *threadID) { // This is the function that each thread will call
    long tid;
    tid = (long) threadID;
    printf("Hello from thread %ld!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    int rc;
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, printHello, (void *) i); // Creating a new thread
        if (rc) {
            printf("Error: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}