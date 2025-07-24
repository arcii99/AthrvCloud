//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4
#define LOOP_COUNT 100000000

typedef struct {
    long id;
    long count;
    double sum;
} ThreadData;

void *work(void *arg) {
    ThreadData *data = (ThreadData *) arg;

    for (long i = 0; i < LOOP_COUNT; i++) {
        data->sum += ((i % 2 == 0) ? 1.0 : -1.0) / (2 * i + 1);
    }

    pthread_exit(NULL);
}

int main() {
    // Allocate thread data and create threads
    ThreadData *data[THREAD_COUNT];
    pthread_t threads[THREAD_COUNT];
    for (long i = 0; i < THREAD_COUNT; i++) {
        data[i] = (ThreadData *) malloc(sizeof(ThreadData));
        data[i]->id = i;
        data[i]->count = LOOP_COUNT;
        data[i]->sum = 0.0;
        pthread_create(&threads[i], NULL, work, (void *) data[i]);
    }

    // Join threads and accumulate results
    double pi = 0.0;
    for (long i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
        pi += 4.0 * data[i]->sum;
        free(data[i]);
    }

    printf("pi = %lf\n", pi);

    return 0;
}