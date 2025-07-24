//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

void *print_message(void *thread_id) {
    int tid = (int) thread_id;
    printf("Thread %d is running...\n", tid);
    sleep(tid);
    printf("Thread %d is done!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    int rc;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d...\n", i);
        rc = pthread_create(&threads[i], NULL, print_message, (void *) i);
        if (rc) {
            printf("ERROR: return code from pthread_create is %d.\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}