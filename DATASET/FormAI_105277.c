//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUEUE_SIZE 5

typedef struct {
    int data[QUEUE_SIZE];
    int head;
    int tail;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} Queue;

void queue_init(Queue *queue) {
    queue->head = 0;
    queue->tail = -1;
    queue->count = 0;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_full, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
}

void queue_destroy(Queue *queue) {
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_full);
    pthread_cond_destroy(&queue->not_empty);
}

void queue_enqueue(Queue *queue, int value) {
    pthread_mutex_lock(&queue->lock);
    while (queue->count == QUEUE_SIZE) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }
    queue->tail = (queue->tail + 1) % QUEUE_SIZE;
    queue->data[queue->tail] = value;
    queue->count++;
    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->lock);
}

int queue_dequeue(Queue *queue) {
    pthread_mutex_lock(&queue->lock);
    while (queue->count == 0) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }
    int value = queue->data[queue->head];
    queue->head = (queue->head + 1) % QUEUE_SIZE;
    queue->count--;
    pthread_cond_signal(&queue->not_full);
    pthread_mutex_unlock(&queue->lock);
    return value;
}

void *producer(void *arg) {
    Queue *queue = (Queue *) arg;
    for (int i = 0; i < 10; i++) {
        queue_enqueue(queue, i);
        printf("Enqueued %d\n", i);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    Queue *queue = (Queue *) arg;
    for (int i = 0; i < 10; i++) {
        int value = queue_dequeue(queue);
        printf("Dequeued %d\n", value);
    }
    pthread_exit(NULL);
}

int main() {
    Queue queue;
    queue_init(&queue);
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, &queue);
    pthread_create(&consumer_thread, NULL, consumer, &queue);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    queue_destroy(&queue);
    return 0;
}