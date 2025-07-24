//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_print(void *thread_id) {
    long tid = (long)thread_id;
    printf("Thread ID %ld is printing\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int return_code;
    long t;

    printf("Main thread is creating %d child threads\n", NUM_THREADS);
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        return_code = pthread_create(&threads[t], NULL, thread_print, (void *)t);
        if (return_code) {
            printf("Error: pthread_create() returned error code %d\n", return_code);
            exit(-1);
        }
    }
    
    printf("Main thread has finished creating threads and is now waiting for them to finish\n");
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads have finished executing, exiting main thread\n");
    pthread_exit(NULL);
}