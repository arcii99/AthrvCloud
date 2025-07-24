//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void* thread_function(void* thread_arg) {
    int* thread_num_ptr = (int*) thread_arg;

    printf("Thread number %d\n", *thread_num_ptr);
    (*thread_num_ptr)++;
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    // create the threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i])) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d\n", i);
            exit(-1);
        }
    }

    printf("All threads done executing.\n");

    return 0;
}