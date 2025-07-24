//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

pthread_mutex_t mutex;
pthread_cond_t cond_producer, cond_consumer;

void *producer(void *args) {
    for(int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while((front == 0 && rear == QUEUE_SIZE-1) || (rear == (front-1)%(QUEUE_SIZE-1))) {
            printf("Queue full! Producer waiting...\n");
            pthread_cond_wait(&cond_producer, &mutex);
        }

        if(front == -1) {
            front = rear = 0;
        } else if(rear == QUEUE_SIZE-1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        queue[rear] = rand() % 50 + 1;
        printf("Produced: %d\n", queue[rear]);
        if((front == 0 && rear == QUEUE_SIZE-1) || (rear == (front-1)%(QUEUE_SIZE-1))) {
            pthread_cond_signal(&cond_consumer);
        }
        pthread_mutex_unlock(&mutex);

        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

void *consumer(void *args) {
    for(int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while(front == -1) {
            printf("Queue empty! Consumer waiting...\n");
            pthread_cond_wait(&cond_consumer, &mutex);
        }

        printf("Consumed: %d\n", queue[front]);

        if(front == rear) {
            front = rear = -1;
        } else if(front == QUEUE_SIZE-1) {
            front = 0;
        } else {
            front++;
        }

        if(front != -1) {
            pthread_cond_signal(&cond_producer);
        }
        pthread_mutex_unlock(&mutex);

        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_producer, NULL);
    pthread_cond_init(&cond_consumer, NULL);

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