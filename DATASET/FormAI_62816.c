//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_COUNT 5

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d started executing...\n", thread_id);
    for (int i = 0; i < 10; i++) {
        printf("Thread %d iteration %d\n", thread_id, i);
    }
    printf("Thread %d finished executing...\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_COUNT];
    int thread_ids[THREADS_COUNT];
    for (int i = 0; i < THREADS_COUNT; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i])) {
            printf("Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < THREADS_COUNT; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d\n", i);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}