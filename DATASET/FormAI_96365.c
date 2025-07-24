//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *print_hello(void *thread_id) {
    long id = (long) thread_id;
    printf("Hello from thread %ld!\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, print_hello, (void *) t);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    printf("Main thread exiting.\n");
    pthread_exit(NULL);
}