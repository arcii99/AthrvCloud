//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
    int tid = *(int*)thread_id;
    printf("Thread %d: Hello world!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i, rc;

    for(i=0; i<NUM_THREADS; i++) {
        printf("Main: creating thread %d\n", i);
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, print_hello, &thread_args[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    printf("Main: All threads have been created.\n");

    pthread_exit(NULL);
}