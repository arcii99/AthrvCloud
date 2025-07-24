//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void *thread_func(void *arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d started\n", thread_id);
    for(int i=1; i<=5; i++) {
        printf("Thread %d executing iteration %d\n", thread_id, i);
    }
    printf("Thread %d completed\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++) {
        thread_ids[i] = i+1;
        int rc = pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
        if(rc) {
            fprintf(stderr, "Error creating thread %d\n", i+1);
            exit(1);
        }
    }

    for(int i=0; i<NUM_THREADS; i++) {
        int rc = pthread_join(threads[i], NULL);
        if(rc) {
            fprintf(stderr, "Error joining thread %d\n", i+1);
            exit(1);
        }
    }

    printf("All threads completed successfully\n");

    return 0;
}