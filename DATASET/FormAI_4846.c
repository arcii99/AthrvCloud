//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int count;
} Data;

Data buffer = {{0}, 0};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;

void enqueue(int item) {
    pthread_mutex_lock(&mutex);

    while (buffer.count == MAX_SIZE) {
        pthread_cond_wait(&cond_empty, &mutex);
    }

    buffer.arr[buffer.count] = item;
    buffer.count++;

    printf("Enqueued item: %d\n", item);

    pthread_cond_signal(&cond_full);
    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    int ret_val = -1;

    pthread_mutex_lock(&mutex);

    while (buffer.count == 0) {
        pthread_cond_wait(&cond_full, &mutex);
    }

    ret_val = buffer.arr[0];
    int i;
    for (i = 0; i < buffer.count-1; i++) {
        buffer.arr[i] = buffer.arr[i+1];
    }
    buffer.count--;

    printf("Dequeued item: %d\n", ret_val);

    pthread_cond_signal(&cond_empty);
    pthread_mutex_unlock(&mutex);

    return ret_val;
}

void *producer(void *args) {
    int i;
    for (i = 0; i < 20; i++) {
        enqueue(i);
    }
    pthread_exit(NULL);
}

void *consumer(void *args) {
    int total = 0;
    while (total < 20) {
        int val = dequeue();
        total += val;
    }
    printf("Consumer total: %d\n", total);
    pthread_exit(NULL);
}

int main() {
    pthread_t prod_tid, cons_tid;

    pthread_create(&prod_tid, NULL, &producer, NULL);
    pthread_create(&cons_tid, NULL, &consumer, NULL);

    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    return 0;
}