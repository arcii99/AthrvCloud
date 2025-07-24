//FormAI DATASET v1.0 Category: Queue ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define QUEUE_SIZE 10

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if ((front == 0 && rear == QUEUE_SIZE-1) || rear == front-1)
    {
        printf("\nQueue is full. Cannot add more elements.\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else if (rear == QUEUE_SIZE-1 && front != 0)
    {
        rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty. Cannot remove elements.\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == QUEUE_SIZE-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return data;
}

bool is_empty()
{
    return (front == -1 && rear == -1);
}

bool is_full()
{
    return ((front == 0 && rear == QUEUE_SIZE-1) || rear == front-1);
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* produce(void* arg)
{
    while (true) {
        int value = rand() % 10 + 1;
        pthread_mutex_lock(&mutex);
        while (is_full())
        {
            printf("Queue is full, producer is waiting...\n");
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Produced value: %d\n", value);
        enqueue(value);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3 + 1);
    }
    return NULL;
}

void* consume(void* arg)
{
    while (true) {
        pthread_mutex_lock(&mutex);
        while (is_empty())
        {
            printf("Queue is empty, consumer is waiting...\n");
            pthread_cond_wait(&cond, &mutex);
        }
        int value = dequeue();
        printf("Consumed value: %d\n", value);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3 + 1);
    }
    return NULL;
}

int main()
{
    pthread_t producer, consumer;
    srand(time(NULL));
    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    return 0;
}