//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 5

pthread_t threads[THREAD_COUNT];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_task(void* arg) {
    int id = *(int*)arg;
    printf("Thread #%d has started\n", id);

    while (1) {
        pthread_mutex_lock(&mutex);
        printf("Thread #%d has acquired the mutex\n", id);
        sleep(1);
        printf("Thread #%d has released the mutex\n", id);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    return NULL;
}

int main() {
    printf("Starting the program\n");

    int thread_ids[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i + 1;
        int result = pthread_create(&threads[i], NULL, thread_task, &thread_ids[i]);
        if (result != 0) {
            printf("Error: Failed to create thread #%d\n", i+1);
        }
    }

    while (1);

    return 0;
}