//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int shared_data = 0;

void* thread_func(void* arg) {
    int thread_id = *(int*)arg;
    int local_data = 0;

    printf("Thread %d started.\n", thread_id);

    while (1) {
        pthread_mutex_lock(&mutex);
        if (shared_data >= 100) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        shared_data++;

        local_data++;
        printf("Thread %d increased shared data to %d (local data: %d)\n", thread_id, shared_data, local_data);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    printf("Thread %d done.\n", thread_id);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    printf("Starting %d threads...\n", MAX_THREADS);

    for (int i = 0; i < MAX_THREADS; i++) {
        ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &ids[i]) != 0) {
            printf("Thread creation failed.\n");
            return 1;
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Thread join failed.\n");
            return 1;
        }
    }

    printf("All threads done.\n");

    return 0;
}