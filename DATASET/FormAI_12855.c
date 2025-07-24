//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 10

struct Queue {
    int queueArray[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

typedef struct Queue queue;

queue queueObj;

pthread_mutex_t queueMutex;

int isQueueFull() {
    if ((queueObj.front == queueObj.rear + 1) || (queueObj.front == 0 && queueObj.rear == MAX_QUEUE_SIZE - 1)) {
        return 1;
    } else {
        return 0;
    }
}

int isQueueEmpty() {
    if (queueObj.front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int value) {
    if (isQueueFull()) {
        printf("Queue is full!!\n");
    } else {
        if (queueObj.front == -1) {
            queueObj.front = 0;
        }
        queueObj.rear = (queueObj.rear + 1) % MAX_QUEUE_SIZE;
        queueObj.queueArray[queueObj.rear] = value;
        printf("Added element : %d\n", value);
    }
}

int dequeue() {
    int value;
    if (isQueueEmpty()) {
        printf("Queue is empty!!\n");
        return (-1);
    } else {
        value = queueObj.queueArray[queueObj.front];
        if (queueObj.front == queueObj.rear) {
            queueObj.front = -1;
            queueObj.rear = -1;
        } else {
            queueObj.front = (queueObj.front + 1) % MAX_QUEUE_SIZE;
        }
        return (value);
    }
}

void *producer(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&queueMutex);
        enqueue(i);
        pthread_mutex_unlock(&queueMutex);
    }
    printf("Producer Thread : Wait For Me!!\n");
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i, value;
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&queueMutex);
        value = dequeue();
        printf("Consumer Thread : Value : %d\n", value);
        pthread_mutex_unlock(&queueMutex);
    }
    printf("Consumer Thread : Wait For Me!!\n");
    pthread_exit(NULL);
}

int main() {

    pthread_t producerThread, consumerThread;

    pthread_mutex_init(&queueMutex, NULL);

    queueObj.front = -1;
    queueObj.rear = -1;

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    pthread_mutex_destroy(&queueMutex);

    return 0;
}