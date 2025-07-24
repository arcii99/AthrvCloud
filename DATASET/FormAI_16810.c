//FormAI DATASET v1.0 Category: Queue ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}

int dequeue()
{
    if (front == -1 || front > rear) {
        return -1;
    }

    int data = queue[front];
    front++;

    if (front > rear) {
        front = rear = -1;
    }

    return data;
}

void* producer(void* arg)
{
    int item = 1;
    while (1) {
        enqueue(item);
        printf("Producer produced item %d\n", item);
        item++;
        sleep(1);
    }
}

void* consumer(void* arg)
{
    int item;
    while (1) {
        item = dequeue();
        if (item == -1) {
            printf("Consumer waiting for items in queue\n");
        } else {
            printf("Consumer consumed item %d\n", item);
        }
        sleep(2);
    }
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}