//FormAI DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_COUNT 10000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void *thread_func(void *thread_id) {
    int local_count = 0;
    int id = *(int *)thread_id;
    srand(time(NULL) + id);
    while (local_count < MAX_COUNT / NUM_THREADS) {
        pthread_mutex_lock(&mutex);
        if (count < MAX_COUNT) {
            printf("Thread %d: count is %d\n", id, ++count);
            local_count++;
        }
        pthread_mutex_unlock(&mutex);
        int sleep_time = rand() % 100;
        usleep(sleep_time);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Final count is %d\n", count);
    pthread_mutex_destroy(&mutex);
    return 0;
}