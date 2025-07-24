//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_func(void *thread_id) {
    printf("Thread %ld is running\n", (long) thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, r;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        r = pthread_create(&threads[i], NULL, thread_func, (void *) i);
        if (r) {
            printf("Error creating thread %ld\n", (long) i);
            return 1;
        }
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        r = pthread_join(threads[i], NULL);
        if (r) {
            printf("Error joining thread %ld\n", (long) i);
            return 1;
        }
    }

    printf("All threads have completed\n");

    return 0;
}