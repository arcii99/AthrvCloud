//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: realistic
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg);

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_args[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_function(void *arg) {
    int my_num = *(int *)arg;
    printf("Hello from thread %d\n", my_num);
    pthread_exit(NULL);
}