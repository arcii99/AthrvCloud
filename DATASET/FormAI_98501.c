//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int counter = 0;

void *thread_func(void *arg) {
    int thread_id = *(int*)arg;
    while (counter < 5) {
        pthread_mutex_lock(&mutex);
        while (counter % NUM_THREADS != thread_id) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Thread %d is incrementing counter to %d\n", thread_id, ++counter);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int args[NUM_THREADS];
    int i;

    printf("Welcome to the mind-bending threading library implementation!\n");

    for (i = 0; i < NUM_THREADS; i++) {
        args[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void*)&args[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Counter has reached 5! Exiting...\n");

    return 0;
}