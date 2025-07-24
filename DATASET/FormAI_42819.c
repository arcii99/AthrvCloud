//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond[NUM_THREADS];

int counter = 0;

void* thread_func(void* arg) {
    int tid = *(int*)arg;
    
    pthread_mutex_lock(&mutex);
    
    // Wait until all threads have started
    while (counter < NUM_THREADS) {
        pthread_cond_wait(&cond[tid], &mutex);
    }
    
    printf("Thread %d started\n", tid);
    
    pthread_mutex_unlock(&mutex);
    
    // Perform some work
    printf("Thread %d is doing some work...\n", tid);
    
    // Signal the next thread to start
    int next_tid = (tid + 1) % NUM_THREADS;
    pthread_cond_signal(&cond[next_tid]);
    
    pthread_exit(NULL);
}

int main() {
    int i, tids[NUM_THREADS];
    
    // Initialize conditional variables
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_cond_init(&cond[i], NULL);
    }
    
    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void*)&tids[i]);
    }
    
    // Wait for all threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Clean up
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_cond_destroy(&cond[i]);
    }
    pthread_mutex_destroy(&mutex);
    
    return 0;
}