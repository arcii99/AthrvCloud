//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

int thread_count = MAX_THREADS;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *thread_function(void *arg) {
    int thread_id = *(int *) arg;
    printf("Thread %d: Started\n", thread_id);
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("Thread %d: Executed\n", thread_id);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[thread_count];
    int thread_ids[thread_count];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i=0; i<thread_count; i++) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, thread_function, (void *) &thread_ids[i]);
    }

    pthread_mutex_lock(&mutex);
    printf("Threads created. Press enter to execute all threads.\n");
    getchar();
    pthread_mutex_unlock(&mutex);

    pthread_cond_broadcast(&cond);

    for (int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}