//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 10

void *thread_function(void *arg) {
    printf("Thread %d is starting...\n", *(int *)arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_args[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; ++i) {
        thread_args[i] = i;
        int status = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);

        if (status != 0) {
            printf("Error creating thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {
        int status = pthread_join(threads[i], NULL);

        if (status != 0) {
            printf("Error joining thread %d.\n", i);
            exit(EXIT_FAILURE);
        }

        printf("Thread %d has finished.\n", i);
    }

    printf("All threads have completed.\n");
    pthread_exit(NULL);
}