//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *thread_function(void *arg) {
    printf("Thread %ld is starting...\n", (long)arg);
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += i;
    }
    printf("Thread %ld is stopping with sum of %d\n", (long)arg, sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    
    for (long t=0; t<NUM_THREADS; t++) {
        printf("Creating thread %ld...\n", t);
        rc = pthread_create(&threads[t], NULL, thread_function, (void*)t);
        if (rc) {
            printf("Error creating thread: %d\n", rc);
            exit(-1);
        }
    }
    
    for (long t=0; t<NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    printf("All threads completed.\n");
    pthread_exit(NULL);
}