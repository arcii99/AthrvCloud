//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, thread_func, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
        sleep(1);
    }

    pthread_exit(NULL);
}

void *thread_func(void *thread_id) {
    long tid = (long)thread_id;
    printf("Thread %ld is running\n", tid);
    sleep(2);
    printf("Thread %ld is done\n", tid);
    pthread_exit(NULL);
}