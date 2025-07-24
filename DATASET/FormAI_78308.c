//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Buffer size of 5
#define BUFFER_SIZE 5

// Message queue - buffer
int msg_queue[BUFFER_SIZE];

// Count of messages in queue
int count = 0;

// Initialize mutex lock and condition variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

// Producer function
void *producer(void *param)
{
    int value;
    srand(time(NULL));
    while (1) {
        value = rand() % 50;
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            // When buffer is full, wait for consumer
            pthread_cond_wait(&empty, &mutex);
        }
        msg_queue[count++] = value;
        printf("Produced value: %d\n", value);
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
}

// Consumer function
void *consumer(void *param)
{
    int value;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            // When no message in queue, wait for producer
            pthread_cond_wait(&full, &mutex);
        }
        value = msg_queue[--count];
        printf("Consumed value: %d\n", value);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
}

// Main function
int main(int argc, char *argv[])
{
    // Thread variables
    pthread_t producer_thread, consumer_thread;
    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}