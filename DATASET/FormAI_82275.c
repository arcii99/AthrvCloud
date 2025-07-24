//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_COUNT 5
#define WORK_PER_THREAD 500000

void *compute_pi(void * arg) {
    int id = *(int*)arg;
    double res = 0;

    for (int i = 0; i < WORK_PER_THREAD; i++) {
        int sign = i % 2 == 0 ? 1 : -1;
        double term = (double) sign / (2 * i + 1);
        res += term;
    }

    res = res * 4;
    printf("Thread %d computed pi = %f\n", id, res);
    pthread_exit((void*)id);
}

int main() {
    pthread_t threads[THREADS_COUNT];
    int thread_ids[THREADS_COUNT];

    for (int i = 0; i < THREADS_COUNT; i++) {
        thread_ids[i] = i;
        int ret = pthread_create(&threads[i], NULL, compute_pi, &thread_ids[i]);
        if (ret != 0) {
            printf("Error creating thread %d. Error code: %d\n", i, ret);
            exit(-1);
        }
    }

    int status[THREADS_COUNT];
    for (int i = 0; i < THREADS_COUNT; i++) {
        int ret = pthread_join(threads[i], (void**)&status[i]);
        if (ret != 0) {
            printf("Error joining thread %d. Error code: %d\n", i, ret);
            exit(-1);
        }
    }

    double total = 0;
    for (int i = 0; i < THREADS_COUNT; i++) {
        total += status[i] % 2 == 0 ? 1 : -1;
    }

    total = total * 4;
    printf("Computed pi = %f\n", total);
    return 0;
}