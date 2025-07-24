//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int *arr;
    int size;
} thread_arg;

void *worker(void *arg) {
    thread_arg *targ = (thread_arg*)arg;
    int id = targ->id;
    int *arr = targ->arr;
    int size = targ->size;
    int sum = 0;
    for (int i = id; i < size; i += 2) {
        sum += arr[i];
    }
    printf("Thread %d sum = %d\n", id, sum);
    return NULL;
}

int main() {
    int size = 100;
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }

    pthread_t threads[2];
    thread_arg args[2];

    for (int i = 0; i < 2; ++i) {
        args[i].id = i;
        args[i].arr = arr;
        args[i].size = size;
        pthread_create(&threads[i], NULL, worker, &args[i]);
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }

    free(arr);
    return 0;
}