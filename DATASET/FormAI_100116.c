//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_CNT 5

int shared_var = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* thread_func(void* arg) {
    int i;
    for (i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);
        shared_var++;
        printf("Thread %d incrementing shared variable to %d.\n",
            *(int*)arg, shared_var);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_cond_signal(&cond);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_CNT];
    int thread_ids[THREAD_CNT];
    int i;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (i = 0; i < THREAD_CNT; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    pthread_mutex_lock(&mutex);
    while (shared_var < THREAD_CNT*5) {
        pthread_cond_wait(&cond, &mutex);
    }
    printf("All threads finished. Shared variable value is %d.\n", shared_var);
    pthread_mutex_unlock(&mutex);

    for (i = 0; i < THREAD_CNT; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}