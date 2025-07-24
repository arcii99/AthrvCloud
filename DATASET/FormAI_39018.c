//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t queue_full_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t queue_empty_cond = PTHREAD_COND_INITIALIZER;

void* producer(void* arg)
{
    int num;
    for(int i=0;i<5;i++)
    {
        num = rand() % 100;
        pthread_mutex_lock(&queue_mutex);
        while((rear+1)%MAX_SIZE == front)
        {
            printf("Producer is about to wait\n");
            pthread_cond_wait(&queue_full_cond, &queue_mutex);
        }
        if(front == -1) front = 0;
        rear = (rear+1) % MAX_SIZE;
        queue[rear] = num;
        printf("Producer produced %d\n", num);
        pthread_cond_signal(&queue_empty_cond);
        pthread_mutex_unlock(&queue_mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg)
{
    int num;
    for(int i=0;i<5;i++)
    {
        pthread_mutex_lock(&queue_mutex);
        while(front == -1)
        {
            printf("Consumer is about to wait\n");
            pthread_cond_wait(&queue_empty_cond, &queue_mutex);
        }
        num = queue[front];
        if(front == rear) front = rear = -1;
        else front = (front + 1) % MAX_SIZE;
        printf("Consumer consumed %d\n", num);
        pthread_cond_signal(&queue_full_cond);
        pthread_mutex_unlock(&queue_mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t producer_thread, consumer_thread;

    srand(time(NULL));

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}