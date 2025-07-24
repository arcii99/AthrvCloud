//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_func(void *arg) {
    int thread_num = *(int*) arg;
    printf("Thread %d starting...\n", thread_num);
    for (int i = 0; i < 10; i++) {
        printf("Thread %d: %d\n", thread_num, i);
        sleep(1);
    }
    printf("Thread %d exiting...\n", thread_num);
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        thread_nums[i] = i+1;
        if (pthread_create(&threads[i], NULL, thread_func, &thread_nums[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}