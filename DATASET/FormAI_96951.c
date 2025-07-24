//FormAI DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE], front = -1, rear = -1;

sem_t mutex, full, empty;

void *producer(void *arg) {
    int element = 0;

    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);

        if ((front == 0 && rear == QUEUE_SIZE -1) || (front == rear + 1)) {
            printf("Queue is full, cannot insert element\n");
        } else if (rear == -1) {
            front = rear = 0;
            queue[rear] = element;
            printf("Producer produced element %d at index %d\n", element, rear);
        } else if (rear == QUEUE_SIZE -1 && front != 0) {
            rear = 0;
            queue[rear] = element;
            printf("Producer produced element %d at index %d\n", element, rear);
        } else {
            rear++;
            queue[rear] = element;
            printf("Producer produced element %d at index %d\n", element, rear);
        }

        element++;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void *consumer(void *arg) {
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        if (front == -1) {
            printf("Queue is empty, cannot consume element\n");
        } else {
            printf("Consumer consumed element %d from index %d\n", queue[front], front);

            if (front == rear) {
                front = rear = -1;
            } else if (front == QUEUE_SIZE -1) {
                front = 0;
            } else {
                front++;
            }
        }

        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, QUEUE_SIZE);

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}