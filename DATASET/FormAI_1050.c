//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// function to be run as a thread
void* thread_function(void* arg) {
    int thread_arg = *(int*)arg;
    printf("Hello from thread %d!\n", thread_arg);
    pthread_exit(NULL);
}

int main() {
    int num_threads = 5;

    printf("Let's create %d happy threads!\n", num_threads);

    // allocate memory for thread IDs
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));

    // create threads
    for (int i = 0; i < num_threads; i++) {
        int* thread_arg = (int*)malloc(sizeof(int));
        *thread_arg = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)thread_arg);
    }

    // wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have happily exited. :)\n");

    // free memory
    free(threads);

    return 0;
}