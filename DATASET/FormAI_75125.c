//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *thread_id);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, print_message, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void *print_message(void *thread_id) {
    int tid;
    tid = (int)thread_id;
    printf("Thread %d: Hello, World!\n", tid);
    pthread_exit(NULL);
}