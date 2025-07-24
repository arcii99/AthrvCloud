//FormAI DATASET v1.0 Category: Queue ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

#define BUF_SIZE 10

typedef struct {
    int head;
    int tail;
    int size;
    int data[BUF_SIZE];
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} queue_t;

bool is_full(queue_t *queue) {
    return queue->size == BUF_SIZE;
}

bool is_empty(queue_t *queue) {
    return queue->size == 0;
}

void enqueue(queue_t *queue, const int data) {
    pthread_mutex_lock(&queue->lock);
    while (is_full(queue)) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }
    queue->data[queue->tail] = data;
    queue->size++;
    queue->tail = (queue->tail + 1) % BUF_SIZE;
    pthread_mutex_unlock(&queue->lock);
    pthread_cond_signal(&queue->not_empty);
}

void dequeue(queue_t *queue, int *data) {
    pthread_mutex_lock(&queue->lock);
    while (is_empty(queue)) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }
    *data = queue->data[queue->head];
    queue->size--;
    queue->head = (queue->head + 1) % BUF_SIZE;
    pthread_mutex_unlock(&queue->lock);
    pthread_cond_signal(&queue->not_full);
}

void *producer(void *arg) {
    queue_t *queue = (queue_t *) arg;
    int i;
    for (i = 0; i < 20; ++i) {
        enqueue(queue, i);
        printf("produced: %d\n", i);
    }
}

void *consumer(void *arg) {
    queue_t *queue = (queue_t *) arg;
    int i, data;
    for (i = 0; i < 20; ++i) {
        dequeue(queue, &data);
        printf("consumed: %d\n", data);
    }
}

int main() {
    pthread_t threads[2];
    queue_t queue = {.head = 0, .tail = 0, .size = 0};
    pthread_mutex_init(&queue.lock, NULL);
    pthread_cond_init(&queue.not_empty, NULL);
    pthread_cond_init(&queue.not_full, NULL);
    pthread_create(&threads[0], NULL, producer, &queue);
    pthread_create(&threads[1], NULL, consumer, &queue);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_mutex_destroy(&queue.lock);
    pthread_cond_destroy(&queue.not_empty);
    pthread_cond_destroy(&queue.not_full);
    return 0;
}