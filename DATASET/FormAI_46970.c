//FormAI DATASET v1.0 Category: Browser Plugin ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 5

// global counter variable to update from threads
int counter = 0;

// thread function to update counter variable
void *updateCounter(void *threadID) {
    long longID = (long) threadID;
    printf("Thread %ld starting...\n", longID);
    int i;
    for (i = 0; i < 10; i++) {
        counter++;
        printf("Thread %ld counter value: %d\n", longID, counter);
    }
    printf("Thread %ld ending...\n", longID);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    printf("Initializing browser plugin...\n");
    for (t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, updateCounter, (void *) t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    // wait for all the threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    printf("All threads completed. Final counter value is: %d\n", counter);
    printf("Shutting down browser plugin...\n");
    pthread_exit(NULL);
}