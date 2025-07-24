//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: inquisitive
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3

void *thread_func(void *thread_id) {
    int tid = *((int*) thread_id);
    printf("Thread %d starting...\n", tid);
    for (int i = 0; i < 5; i++) {
        printf("Thread %d: %d\n", tid, i);
    }
    printf("Thread %d ending...\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
        if (result != 0) {
            printf("Error creating thread %d!\n", i);
            return -1;
        }
    }

    printf("Main thread waiting for all threads to finish...\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        int result = pthread_join(threads[i], NULL);
        if (result != 0) {
            printf("Error joining thread %d!\n", i);
            return -1;
        }
    }

    printf("All threads finished! Exiting...\n");
    return 0;
}