//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg);

int main() {
    pthread_t thread_id[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        if (pthread_create(&thread_id[i], NULL, thread_function, (void *) i) != 0) {
            fprintf(stderr, "error: Cannot create thread\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(thread_id[i], NULL) != 0) {
            fprintf(stderr, "error: Cannot join thread %d\n", i);
            exit(EXIT_FAILURE);
        }
        printf("Thread %d has finished\n", i);
    }

    return 0;
}

void *thread_function(void *arg) {
    int thread_num = (int) arg;
    printf("Running thread %d\n", thread_num);
    pthread_exit(NULL);
}