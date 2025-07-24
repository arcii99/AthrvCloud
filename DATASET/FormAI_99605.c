//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg);

int main() {
    pthread_t threads[NUM_THREADS];
    int i, j, thread_args[NUM_THREADS];

    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    // join threads
    for (j = 0; j < NUM_THREADS; j++) {
        if (pthread_join(threads[j], NULL) != 0) {
            perror("pthread_join failed");
            exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    int thread_arg = *(int*)arg;
    printf("Thread %d is running.\n", thread_arg);
    pthread_exit(NULL);
}