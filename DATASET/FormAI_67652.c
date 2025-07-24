//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <pthread.h>

#define THREADS 5
#define ITERATIONS 1000000

pthread_mutex_t lock;
int counter;

void* thread_function(void* arg) {
    int thread_id = *((int*) arg);

    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }

    printf("Thread %d finished executing.\n", thread_id);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int thread_ids[THREADS];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void*) &thread_ids[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Counter value: %d\n", counter);

    pthread_mutex_destroy(&lock);

    return 0;
}