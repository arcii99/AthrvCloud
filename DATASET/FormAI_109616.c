//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *printMessage(void *threadID) {
    long id = (long)threadID;
    printf("Thread %ld: Hello from thread #%ld!\n", id, id);
    pthread_exit(NULL); 
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc; 
    long t;

    for(t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, printMessage, (void *)t); 
        if(rc) {
            printf("Error: unable to create thread, %d\n", rc); 
            exit(-1); 
        }
    }

    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL); 
    }

    pthread_exit(NULL); 
    return 0; 
}