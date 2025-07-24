//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int arr[MAX_QUEUE_SIZE];
    int head;
    int tail;
    int size;
} Queue;

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t full_cond = PTHREAD_COND_INITIALIZER;

void enqueue(Queue* q, int data) {
    pthread_mutex_lock(&queue_mutex);
    while(q->size == MAX_QUEUE_SIZE) {
        pthread_cond_wait(&full_cond, &queue_mutex);
    }
    q->arr[q->tail] = data;
    q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
    q->size++;
    pthread_cond_signal(&empty_cond);
    pthread_mutex_unlock(&queue_mutex);
}

int dequeue(Queue* q) {
    pthread_mutex_lock(&queue_mutex);
    while(q->size == 0) {
        pthread_cond_wait(&empty_cond, &queue_mutex);
    }
    int data = q->arr[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_SIZE;
    q->size--;
    pthread_cond_signal(&full_cond);
    pthread_mutex_unlock(&queue_mutex);
    return data;
}

void* producer(void* arg) {
    Queue* q = (Queue*)arg;
    int data = 0;
    while(1) {
        enqueue(q, data);
        printf("Produced: %d\n", data);
        data++;
    }
}

void* consumer(void* arg) {
    Queue* q = (Queue*)arg;
    while(1) {
        int data = dequeue(q);
        printf("Consumed: %d\n", data);
    }
}

int main() {
    Queue q;
    q.head = q.tail = q.size = 0;

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, &q);
    pthread_create(&consumer_thread, NULL, consumer, &q);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}