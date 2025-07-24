//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_work(void *id) {
    printf("Thread #%d starting work...\n", *(int*)id);
    
    // Let's do some mind bending math
    int num = 1;
    for (int i = 2; i < 1000000; i++) {
        num *= i;
        num %= 2023;
    }
    printf("Thread #%d completed work: %d\n", *(int*)id, num);
    
    pthread_exit(NULL);
}

int main() {
    printf("Starting program...\n");
    
    // Create array of threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    // Create threads and assign IDs
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_work, &thread_ids[i]);
    }
    
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads completed work.\n");
    
    return 0;
}