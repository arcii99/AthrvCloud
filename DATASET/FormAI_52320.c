//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// define the maximum number of threads that can be created
#define MAX_THREADS 10

// define the function that will be executed by each thread
void *thread_function(void *arg) {
    int thread_id = *((int *) arg);
    printf("Thread %d started\n", thread_id);
    for (int i = 0; i < 10; i++) {
        printf("Thread %d says hello %d times\n", thread_id, i+1);
    }
    printf("Thread %d ended\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    int thread_ids[MAX_THREADS];
    pthread_t threads[MAX_THREADS];
    int num_threads;

    printf("Enter the number of threads to create (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    // create the threads
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i+1;
        if (pthread_create(&threads[i], NULL, thread_function, (void *) &thread_ids[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    // join the threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads completed successfully.\n");
    exit(EXIT_SUCCESS);
}