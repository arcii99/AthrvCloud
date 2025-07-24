//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 3

void* thread_func(void* id) {
    printf("Thread %ld starting\n", (long)id);
    printf("Thread %ld ending\n", (long)id);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int i, status;

    printf("Main thread starting\n");

    for (i = 0; i < THREAD_COUNT; i++) {
        status = pthread_create(&threads[i], NULL, thread_func, (void*)(long)i);
        if (status) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        status = pthread_join(threads[i], NULL);
        if (status) {
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }

    printf("Main thread ending\n");

    return 0;
}