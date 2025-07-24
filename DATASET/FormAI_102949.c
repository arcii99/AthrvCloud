//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 4

int shared_variable = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int *thread_num = (int *) arg;
    pthread_mutex_lock(&mutex);
    shared_variable++;
    printf("Thread %d incremented shared variable to %d\n", *thread_num, shared_variable);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NTHREADS];
    int thread_args[NTHREADS];
    int i, result;

    // create threads
    for(i=0; i<NTHREADS; i++) {
        thread_args[i] = i;
        result = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
        if(result != 0) {
            printf("Could not create thread %d\n", i);
            return -1;
        }
    }

    // join threads
    for(i=0; i<NTHREADS; i++) {
        result = pthread_join(threads[i], NULL);
        if(result != 0) {
            printf("Could not join thread %d\n", i);
            return -1;
        }
    }

    printf("Final value of shared variable is %d\n", shared_variable);

    return 0;
}