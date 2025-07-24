//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_COUNT 100000

int global_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_increment(void *thread_id) {
    int i;
    int local_count = 0;

    for (i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        global_count++;
        local_count++;
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %d incremented the global count by %d\n", *(int *)thread_id, local_count);

    pthread_exit(NULL);
}

int main() {
    int i;
    int thread_ids[NUM_THREADS];

    pthread_t threads[NUM_THREADS];

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        
        int err = pthread_create(&threads[i], NULL, thread_increment, &thread_ids[i]);

        if (err) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Global count is %d\n", global_count);

    return 0;
}