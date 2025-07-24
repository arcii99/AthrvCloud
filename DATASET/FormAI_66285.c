//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_NUM 10

pthread_mutex_t mutex;
pthread_cond_t condition;
int shared_count = 0;

void* increment_count(void* arg) {
    int threadID = *(int *)arg;
    int count = 0;
    while (count < 5) {
        pthread_mutex_lock(&mutex);
        shared_count++;
        printf("Thread %d incremented count to %d\n", threadID, shared_count);
        if (shared_count % THREADS_NUM == 0) {
            printf("Thread %d signaling conditon variable\n", threadID);
            pthread_cond_signal(&condition);
        }
        pthread_mutex_unlock(&mutex);
        count++;
    }
    pthread_exit(NULL);
}

void* wait_for_all_threads(void* arg) {
    int threadID = *(int *)arg;
    pthread_mutex_lock(&mutex);
    while (shared_count % THREADS_NUM != 0) {
        printf("Thread %d waiting for condition variable\n", threadID);
        pthread_cond_wait(&condition, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    printf("Thread %d finished waiting for all threads\n", threadID);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_NUM];
    pthread_attr_t attr;
    void* status;
    int threadID[THREADS_NUM];
    int i;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < THREADS_NUM; i++) {
        threadID[i] = i;
        pthread_create(&threads[i], &attr, increment_count, (void *)&threadID[i]);
    }

    pthread_create(&threads[THREADS_NUM-1], &attr, wait_for_all_threads, (void *)&threadID[THREADS_NUM-1]);

    for (i = 0; i < THREADS_NUM; i++) {
        pthread_join(threads[i], &status);
    }

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);
    pthread_exit(NULL);
}