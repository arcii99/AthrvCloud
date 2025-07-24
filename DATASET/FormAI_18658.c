//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_NUM 4

pthread_mutex_t lock;  // mutex to protect the global sum

struct thread_args {
    int* array;
    int start;
    int end;
    int sum;
};

void* thread_sum(void* arg) {
    struct thread_args* ta = (struct thread_args*)arg;

    for (int i = ta->start; i < ta->end; i++) {
        pthread_mutex_lock(&lock);
        ta->sum += ta->array[i];  // atomically add to the global sum
        pthread_mutex_unlock(&lock);
    }

    pthread_exit(NULL);
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    pthread_t threads[THREADS_NUM];
    struct thread_args args[THREADS_NUM];

    pthread_mutex_init(&lock, NULL);

    // divide the array into THREADS_NUM equal parts
    int part_size = 10 / THREADS_NUM;   
    for (int i = 0; i < THREADS_NUM; i++) {
        args[i].array = array;
        args[i].start = i * part_size;
        args[i].end = (i + 1) * part_size;
        args[i].sum = 0;
        pthread_create(&threads[i], NULL, thread_sum, (void*)&args[i]);
    }

    // wait for all threads to finish and collect their sums
    int sum = 0;
    for (int i = 0; i < THREADS_NUM; i++) {
        pthread_join(threads[i], NULL);
        sum += args[i].sum;
    }

    pthread_mutex_destroy(&lock);

    printf("The sum of the array is: %d\n", sum);
    return 0;
}