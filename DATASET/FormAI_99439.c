//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

//define variable for mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg){
    pthread_mutex_lock(&mutex);
    printf("Thread %d is running\n", *(int*)arg);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
       thread_args[i] = i;
       pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }

    // wait for all threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
       pthread_join(threads[i], NULL);
    }

    //destroy mutex
    pthread_mutex_destroy(&mutex);
    return 0;
}