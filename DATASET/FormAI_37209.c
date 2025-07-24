//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5

pthread_t thread[THREAD_COUNT];
pthread_mutex_t mutex;

void* print_hello(void* args) {
    int* thread_id = (int*) args;
    pthread_mutex_lock(&mutex);
    printf("Hello from thread %d\n", *thread_id);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    int thread_args[THREAD_COUNT];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_args[i] = i;
        int error = pthread_create(&thread[i], NULL, &print_hello, &thread_args[i]);
        if (error != 0) {
            printf("Error creating thread %d: %s\n", i, strerror(error));
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        int error = pthread_join(thread[i], NULL);
        if (error != 0) {
            printf("Error joining thread %d: %s\n", i, strerror(error));
            exit(EXIT_FAILURE);
        }
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}