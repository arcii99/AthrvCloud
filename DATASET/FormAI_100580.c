//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_SIZE 10

int data[MAX_SIZE];
int front = -1, rear = -1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void enqueue(int value) {
    pthread_mutex_lock(&mutex);

    while ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1)) {
        pthread_cond_wait(&cond, &mutex);
    }

    if (rear == MAX_SIZE - 1 && front != 0)
        rear = -1;

    data[++rear] = value;

    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
}

void dequeue() {
    pthread_mutex_lock(&mutex);

    while (front == -1) {
        pthread_cond_wait(&cond, &mutex);
    }

    int value = data[front++];
    if (front == MAX_SIZE)
        front = 0;

    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);

    printf("Removing %d from queue\n", value);
}

void display() {
    printf("Queue: ");
    
    if (front == -1)
        printf("Empty\n");
    else {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
            printf("%d ", data[i]);
        printf("%d ", data[i]);
        printf("\n");
    }
}

void *producer(void *args) {
    int i;

    for (i = 1; i <= 10; i++) {
        printf("Inserting %d into queue\n", i);
        enqueue(i);
        display();
    }

    pthread_exit(NULL);
}

void *consumer(void *args) {
    int i;

    for (i = 1; i <= 5; i++) {
        dequeue();
        display();
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}