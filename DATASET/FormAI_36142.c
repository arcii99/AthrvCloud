//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *printMessage(void *threadId) {
    long id = (long)threadId;
    printf("Hello from thread %ld!\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, printMessage, (void *)t);
        if(rc) {
            printf("Error creating thread %ld.\n", t);
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}