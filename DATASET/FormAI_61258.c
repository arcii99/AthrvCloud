//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define THREAD_COUNT 4

int sum = 0;

void *compute_sum(void *arg) {
    int *numbers = (int*) arg;
    int local_sum = 0;
    for (int i = 0; i < 10; i++) {
        local_sum += *(numbers + i);
    }
    sum += local_sum;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int numbers[THREAD_COUNT][10];

    srand(time(NULL));
    for (int i = 0; i < THREAD_COUNT; i++) {
        for (int j = 0; j < 10; j++) {
            numbers[i][j] = rand() % 10;
        }
        pthread_create(&threads[i], NULL, compute_sum, (void*) numbers[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total: %d\n", sum);

    return 0;
}