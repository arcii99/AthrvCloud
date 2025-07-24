//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 // number of threads

void *printHello(void *threadID) {
    int *id = (int *)threadID;
    printf("Thread %d: Hello World!\n", *id); // print hello world statement
    pthread_exit(NULL);
}

int main () {
    pthread_t threads[NUM_THREADS]; // array of threads
    int threadIDs[NUM_THREADS]; // array of thread IDs
    int rc, t;
    
    // loop through threads and create each one
    for (t = 0; t < NUM_THREADS; t++) {
        threadIDs[t] = t;
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, printHello, (void *)&threadIDs[t]);
        if (rc) { // if error, exit
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    // wait for all threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) { // if error, exit
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Thread %d has completed.\n", t);
    }
    
    pthread_exit(NULL); // exit main thread
}