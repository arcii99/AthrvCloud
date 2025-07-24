//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 3

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    int id = (*(int *)arg);
    while (1) {
        // Produce item
        int item = rand() % 100;
        
        // Add item to buffer
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&full, &mutex);
        }
        printf("Producer #%d added item %d to buffer\n", id, item);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void *arg) {
    int id = (*(int *)arg);
    while (1) {
        // Remove item from buffer
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            pthread_cond_wait(&empty, &mutex);
        }
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumer #%d removed item %d from buffer\n", id, item);
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
        
        // Consume item
        printf("Consumer #%d consumed item %d\n", id, item);
    }
}

int main() {
    // Initialize producers
    pthread_t producer_threads[NUM_PRODUCERS];
    int producer_ids[NUM_PRODUCERS];
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i + 1;
        pthread_create(&producer_threads[i], NULL, producer, &producer_ids[i]);
    }
    
    // Initialize consumers
    pthread_t consumer_threads[NUM_CONSUMERS];
    int consumer_ids[NUM_CONSUMERS];
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_ids[i] = i + 1;
        pthread_create(&consumer_threads[i], NULL, consumer, &consumer_ids[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producer_threads[i], NULL);
    }
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumer_threads[i], NULL);
    }
    
    return 0;
}