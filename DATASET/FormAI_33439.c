//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 100
#define MAX_ITEMS 50

pthread_mutex_t mutex;
int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand()%100; // Dummy item
        pthread_mutex_lock(&mutex);
        if (count >= MAX_ITEMS) {
            pthread_mutex_unlock(&mutex);
            continue;
        }
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Producer produced item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count <= 0) {
            pthread_mutex_unlock(&mutex);
            continue;
        }
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumer consumed item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}