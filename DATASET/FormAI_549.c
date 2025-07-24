//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void* thread_func(void* arg) {
    int thread_num = *(int*) arg;

    printf("Thread number %d starting...\n", thread_num);

    // Do some work here

    printf("Thread number %d exiting...\n", thread_num);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    // Initialize thread numbers
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_nums[i] = i + 1;
    }

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished.\n");

    return 0;
}