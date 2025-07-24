//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

struct Queue {
    int buffer[BUFFER_SIZE];
    int front, rear;
} queue;

pthread_mutex_t mutex;
pthread_cond_t cond_producer, cond_consumer;

void produce_item(int item) {
    pthread_mutex_lock(&mutex);
    while ((queue.rear + 1) % BUFFER_SIZE == queue.front) {
        printf("Queue full. Producer waiting...\n");
        pthread_cond_wait(&cond_producer, &mutex);
    }
    queue.buffer[queue.rear] = item;
    queue.rear = (queue.rear + 1) % BUFFER_SIZE;
    printf("Producer produced item %d\n", item);
    pthread_cond_signal(&cond_consumer);
    pthread_mutex_unlock(&mutex);
}

int consume_item() {
    pthread_mutex_lock(&mutex);
    while (queue.front == queue.rear) {
        printf("Queue empty. Consumer waiting...\n");
        pthread_cond_wait(&cond_consumer, &mutex);
    }
    int item = queue.buffer[queue.front];
    queue.front = (queue.front + 1) % BUFFER_SIZE;
    printf("Consumer consumed item %d\n", item);
    pthread_cond_signal(&cond_producer);
    pthread_mutex_unlock(&mutex);
    return item;
}

void* producer(void* args) {
    int item;
    while (1) {
        item = rand() % 100 + 1;
        produce_item(item);
        usleep(rand() % 1000);
    }
}

void* consumer(void* args) {
    while (1) {
        consume_item();
        usleep(rand() % 1000);
    }
}

void init() {
    queue.front = 0;
    queue.rear = 0;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_producer, NULL);
    pthread_cond_init(&cond_consumer, NULL);
}

int main() {
    init();

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_producer);
    pthread_cond_destroy(&cond_consumer);

    return 0;
}