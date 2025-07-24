//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *thread_func(void *thread_id) {
    long id = (long) thread_id;
    printf("Thread %ld is running\n", id);
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t thread[NUM_THREADS];

    for(i=0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        int ret = pthread_create(&thread[i], NULL, thread_func, (void *) i);

        if(ret) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, ret);
            exit(-1);
        }
    }

    printf("All threads created successfully\n");

    // Wait for all threads to finish
    for(i=0; i < NUM_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("All threads finished execution\n");

    pthread_exit(NULL);
}