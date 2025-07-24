//FormAI DATASET v1.0 Category: Queue ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int front = -1;
int rear = -1;

sem_t empty, full;
pthread_mutex_t mutex;

void enqueue(int value) {
    if ((front == 0 && rear == BUFFER_SIZE-1) || (rear == (front-1)%(BUFFER_SIZE-1))) {
        printf("Queue is full!\n");
        return;
    }
    else if (front == -1) {
        front = 0;
        rear = 0;
        buffer[rear] = value;
    }
    else if (rear == BUFFER_SIZE-1 && front != 0) {
        rear = 0;
        buffer[rear] = value;
    }
    else {
        rear++;
        buffer[rear] = value;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = buffer[front];
    buffer[front] = -1;
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == BUFFER_SIZE-1) {
        front = 0;
    }
    else {
        front++;
    }
    return value;
}

void *producer(void *arg) {
    int value = 1;
    while (1) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        printf("Producer produced %d\n", value);
        enqueue(value);
        value++;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void *consumer(void *arg) {
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int value = dequeue();
        printf("Consumer consumed %d\n", value);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(2);
    }
}

int main() {
    pthread_t tid_producer, tid_consumer;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid_producer, NULL, producer, NULL);
    pthread_create(&tid_consumer, NULL, consumer, NULL);
    pthread_join(tid_producer, NULL);
    pthread_join(tid_consumer, NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}