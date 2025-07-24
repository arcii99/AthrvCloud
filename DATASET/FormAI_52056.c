//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 3
#define ARRAY_SIZE 10

int array[ARRAY_SIZE];

void *thread_func(void *index_ptr) {
    int index = *((int *) index_ptr);
    int sum = 0;
    for (int i = index; i < ARRAY_SIZE; i += THREAD_COUNT) {
        sum += array[i];
    }
    printf("Thread %d: Sum = %d\n", index, sum);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_args[THREAD_COUNT];

    // Initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10;
    }

    // Create threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_args[i] = i;
        int ret = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
        if (ret != 0) {
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        int ret = pthread_join(threads[i], NULL);
        if (ret != 0) {
            printf("Error: pthread_join() failed\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}