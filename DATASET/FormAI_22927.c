//FormAI DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUEUE_SIZE 10

typedef struct {
    int items[QUEUE_SIZE];
    int front;
    int rear;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} Queue;

void queue_init(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    pthread_cond_init(&queue->not_full, NULL);
}

void queue_destroy(Queue *queue) {
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_empty);
    pthread_cond_destroy(&queue->not_full);
}

int queue_enqueue(Queue *queue, int item) {
    pthread_mutex_lock(&queue->lock);
    while((queue->rear + 1) % QUEUE_SIZE == queue->front) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }

    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->items[queue->rear] = item;

    if(queue->front == -1) {
        queue->front = 0;
    }

    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->lock);

    return 1;
}

int queue_dequeue(Queue *queue) {
    pthread_mutex_lock(&queue->lock);
    while(queue->front == -1) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }

    int item = queue->items[queue->front];
    if(queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % QUEUE_SIZE;
    }

    pthread_cond_signal(&queue->not_full);
    pthread_mutex_unlock(&queue->lock);

    return item;
}

void* producer(void *arg) {
    Queue *queue = (Queue*) arg;

    for(int i = 0; i < 20; i++) {
        printf("Enqueuing item %d\n", i);
        queue_enqueue(queue, i);
        sleep(1);
    }

    pthread_exit(NULL);
}

void* consumer(void *arg) {
    Queue *queue = (Queue*) arg;

    for(int i = 0; i < 20; i++) {
        int item = queue_dequeue(queue);
        printf("Dequeuing item %d\n", item);
        sleep(2);
    }

    pthread_exit(NULL);
}

int main() {
    Queue queue;
    queue_init(&queue);

    pthread_t prod_thread, cons_thread;
    pthread_create(&prod_thread, NULL, producer, &queue);
    pthread_create(&cons_thread, NULL, consumer, &queue);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    queue_destroy(&queue);

    return 0;
}