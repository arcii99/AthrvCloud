//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_THREADS 5
#define MAX_ITERATIONS 10

int shared_counter = 0;

pthread_mutex_t mutex;

void* thread_function(void* arg) {
    int local_counter = 0;
    int* thread_id = (int*) arg;

    while (local_counter < MAX_ITERATIONS) {
        pthread_mutex_lock(&mutex);
        shared_counter++;
        local_counter++;
        printf("Thread %d shared counter: %d\n", *thread_id, shared_counter);
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread %d completed %d iterations\n", *thread_id, MAX_ITERATIONS);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];

    pthread_mutex_init(&mutex, NULL);

    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_function, (void*) &thread_ids[i]);
        if (result != 0) {
            printf("Failed to create thread %d\n", i);
            exit(-1);
        }
        printf("Thread %d created\n", i);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        int result = pthread_join(threads[i], NULL);
        if (result != 0) {
            printf("Failed to join thread %d\n", i);
            exit(-1);
        }
        printf("Thread %d joined\n", i);
    }
    printf("Shared counter value: %d\n", shared_counter);

    pthread_mutex_destroy(&mutex);

    return 0;
}