//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 3
#define PASSES 1000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int shared_count = 0;

void *worker(void *arg) {
    int i;
    
    // Loop a number of times and increment the shared count
    for (i = 0; i < PASSES; i++) {
        pthread_mutex_lock(&mutex);
        shared_count++;
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int i;
    pthread_t threads[THREADS];
    
    // Create threads
    for (i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }
    
    // Wait for threads to finish
    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Result: %d\n", shared_count);
    
    return 0;
}