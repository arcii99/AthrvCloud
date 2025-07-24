//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 500000

int global_array[ARRAY_SIZE];

struct thread_param {
    int from;
    int to;
    int sum;
};

void *sum_array(void *arg) {
    struct thread_param *param = (struct thread_param *)arg;
    int sum = 0;

    for (int i = param->from; i < param->to; i++) {
        sum += global_array[i];
    }

    param->sum = sum;
    pthread_exit(NULL);
}

void populate_array() {
    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        global_array[i] = rand() % 10;
    }
}

int main() {
    populate_array();

    pthread_t thread1, thread2;
    struct thread_param param1, param2;

    param1.from = 0;
    param1.to = ARRAY_SIZE / 2;
    param2.from = ARRAY_SIZE / 2;
    param2.to = ARRAY_SIZE;
    
    clock_t start = clock();

    pthread_create(&thread1, NULL, sum_array, (void *)&param1);
    pthread_create(&thread2, NULL, sum_array, (void *)&param2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    int sum = param1.sum + param2.sum;

    printf("The total sum of the array is: %d\n", sum);

    clock_t end = clock();

    printf("The program took %f seconds to run\n", (double)(end - start) / CLOCKS_PER_SEC);

    exit(EXIT_SUCCESS);
}