//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define BUFFER_SIZE 10
#define MAX_THREADS 5

int buffer[BUFFER_SIZE];
int front = -1, rear = -1, item_count = 0;

/* Initialize mutex locks and condition variables */
pthread_mutex_t lock;
pthread_cond_t not_full, not_empty;

void *producer(void *arg) {
    int data = 0;

    while(1) {
        pthread_mutex_lock(&lock);
        /* Check if buffer is full */
        if(item_count == BUFFER_SIZE) {
            printf("Buffer is full. Producer waiting...\n");
            pthread_cond_wait(&not_full, &lock); /* Wait till buffer is not full */
        }

        /* Add item to buffer */
        rear = (rear+1) % BUFFER_SIZE;
        buffer[rear] = data;
        printf("Producer produced item : %d\n", data);
        data++;
        item_count++;

        /* Signal consumer thread waiting to consume from buffer */
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&lock);

        /* Sleep for 1 second */
        sleep(1);
    }
}

void *consumer(void *arg) {
    int data;

    while(1) {
        pthread_mutex_lock(&lock);
        /* Check if buffer is empty */
        if(item_count == 0) {
            printf("Buffer is empty. Consumer waiting...\n");
            pthread_cond_wait(&not_empty, &lock); /* Wait till buffer is not empty */
        }

        /* Remove item from buffer */
        front = (front+1) % BUFFER_SIZE;
        data = buffer[front];
        printf("Consumer consumed item : %d\n", data);
        item_count--;

        /* Signal producer thread waiting to produce to buffer */
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&lock);

        /* Sleep for 2 seconds */
        sleep(2);
    }
}

int main() {
    pthread_t threads[MAX_THREADS];

    /* Initialize mutex and condition variables */
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    /* Create producer and consumer threads */
    pthread_create(&threads[0], NULL, producer, NULL);
    pthread_create(&threads[1], NULL, consumer, NULL);

    /* Wait for threads to finish */
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    /* Destroy mutex and condition variables */
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}