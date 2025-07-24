//FormAI DATASET v1.0 Category: Random ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define THREAD_COUNT 5
#define ARRAY_SIZE 10

int rand_int() {
    return rand() % 100;
}

void *thread_func(void *arg) {
    int *array = (int *) arg;
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    printf("Thread %ld sum: %d\n", pthread_self(), sum);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand_int();
    }
    pthread_t threads[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, (void *) array)) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }
    return 0;
}