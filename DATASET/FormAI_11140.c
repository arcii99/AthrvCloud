//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

pthread_mutex_t mutex;
pthread_cond_t cond;
int doneCount = 0;

void* thread_func(void* arg) {
    pthread_mutex_lock(&mutex);

    printf("[%lu] Thread started\n", pthread_self());

    // Wait on condition variable
    pthread_cond_wait(&cond, &mutex);

    printf("[%lu] Thread woken up\n", pthread_self());

    doneCount++;

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    printf("Starting %d threads\n", MAX_THREADS);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    // Sleep for 3 seconds
    sleep(3);

    printf("Sending signal to all threads\n");

    // Signal all threads
    pthread_cond_broadcast(&cond);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads done\n");

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}