//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3

void *thread_func(void *arg) {
    int thread_id = *((int *) arg);
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    printf("Thread %d: Sum is %d\n", thread_id, sum);
    pthread_exit(NULL);
}

int main() {
    int thread_ids[NUM_THREADS];
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, (void *) &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}