//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t full;
    pthread_cond_t empty;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;

    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->full, NULL);
    pthread_cond_init(&q->empty, NULL);
}

int enqueue(Queue *q, int data) {
    pthread_mutex_lock(&q->mutex);

    if (q->count == MAX_QUEUE_SIZE) {
        pthread_cond_wait(&q->full, &q->mutex);
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
    q->count++;

    pthread_cond_signal(&q->empty);
    pthread_mutex_unlock(&q->mutex);

    return 1;
}

int dequeue(Queue *q) {
    int data = 0;

    pthread_mutex_lock(&q->mutex);

    if (q->count == 0) {
        pthread_cond_wait(&q->empty, &q->mutex);
    }

    data = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;

    pthread_cond_signal(&q->full);
    pthread_mutex_unlock(&q->mutex);

    return data;
}

Queue queue;
pthread_t threads[MAX_THREADS];

void *producer(void *arg) {
    int id = *(int *)arg;
    int i, data;

    for (i = 0; i < 10; i++) {
        data = random() % 100 + 1;
        printf("Producer %d produced %d\n", id, data);
        enqueue(&queue, data);
        usleep(random() % 100);
    }

    pthread_exit(0);
}

void *consumer(void *arg) {
    int id = *(int *)arg;
    int i, data;

    for (i = 0; i < 10; i++) {
        data = dequeue(&queue);
        printf("Consumer %d consumed %d\n", id, data);
        usleep(random() % 100);
    }

    pthread_exit(0);
}

int main() {
    int i, id[MAX_THREADS];

    initQueue(&queue);

    for (i = 0; i < MAX_THREADS; i++) {
        id[i] = i;
        if (i < MAX_THREADS / 2) {
            pthread_create(&threads[i], NULL, producer, (void *)&id[i]);
        } else {
            pthread_create(&threads[i], NULL, consumer, (void *)&id[i]);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}