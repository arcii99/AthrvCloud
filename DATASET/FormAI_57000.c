//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *printThread(void *thread_id) {
    long id = (long) thread_id;
    printf("Thread #%ld starting...\n", id);
    printf("Thread #%ld is executing.\n", id);
    printf("Thread #%ld finished.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread #%d.\n", i);
        rc = pthread_create(&threads[i], NULL, printThread, (void *) i);

        if (rc) {
            printf("ERROR: return code from pthread_create() is %d.\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}