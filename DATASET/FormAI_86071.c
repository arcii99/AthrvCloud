//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int thread_counter = 0;

void *thread_function(void *arg) {
    int thread_id = *(int *) arg;

    pthread_mutex_lock(&lock);
    thread_counter++;
    printf("Thread %d has started\n", thread_id);
    printf("Thread Counter: %d\n", thread_counter);
    pthread_mutex_unlock(&lock);

    if (thread_counter == MAX_THREADS) {
        pthread_cond_broadcast(&cond);
    } else {
        pthread_cond_wait(&cond, &lock);
    }

    printf("Thread %d has finished\n", thread_id);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (result != 0) {
            printf("Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed\n");

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}