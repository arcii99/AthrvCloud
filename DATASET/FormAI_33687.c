//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    printf("Thread %d is running...\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_args[THREAD_COUNT];
    int i, ret;
    
    /* Create threads */
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_args[i] = i;
        ret = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
        if (ret != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
    
    /* Wait for threads to finish */
    for (i = 0; i < THREAD_COUNT; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
    
    printf("All threads have finished executing.\n");
    
    return EXIT_SUCCESS;
}