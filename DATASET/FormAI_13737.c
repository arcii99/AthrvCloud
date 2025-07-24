//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_QUEUE_SIZE 10

sem_t empty, full, mutex;
int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("%d enqueued to queue\n", item);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
    } else {
        int item = queue[front];
        front++;
        printf("%d dequeued from queue\n", item);
    }
}

void* produce(void* arg) {
    int item;
    for (int i = 0; i < 6; i++) {
        item = rand() % 100;
        sem_wait(&empty);
        sem_wait(&mutex);
        enqueue(item);
        sem_post(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL); 
}

void* consume(void* arg) {
    for (int i = 0; i < 6; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        dequeue();
        sem_post(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL); 
}

int main() {
    sem_init(&empty, 0, MAX_QUEUE_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_t producer, consumer;

    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}