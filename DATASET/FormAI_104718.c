//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_MEMORY 1024

void *allocate_memory(void *thread_number)
{
    int n = *(int *)thread_number;
    char *memory = malloc(MAX_MEMORY);

    if (memory == NULL) {
        printf("Thread %d: Error allocating memory\n", n);
    } else {
        printf("Thread %d: Allocated %d bytes of memory at %p\n", n, MAX_MEMORY, memory);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_THREADS];
    int thread_nums[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_nums[i] = i;
        if (pthread_create(&threads[i], NULL, allocate_memory, &thread_nums[i])) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}