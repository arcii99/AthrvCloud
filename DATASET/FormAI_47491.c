//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS];
pthread_mutex_t lock;

int shared_variable = 0;

void *thread_function(void *args) {
    int thread_id = (int) args;
    printf("Thread %d started.\n", thread_id);
    
    pthread_mutex_lock(&lock);
    for (int i = 0; i < 5; i++) {
        shared_variable++;
        printf("Thread %d: shared_variable = %d\n", thread_id, shared_variable);
    }
    pthread_mutex_unlock(&lock);
    
    printf("Thread %d finished.\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    int rc;
    long t;
    pthread_mutex_init(&lock, NULL);
    
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, thread_function, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d.\n", rc);
            exit(-1);
        }
    }
    
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    pthread_mutex_destroy(&lock);

    printf("Final value of shared_variable: %d\n", shared_variable);
    pthread_exit(NULL);
}