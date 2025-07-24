//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

pthread_mutex_t mutex; // Mutex lock
pthread_cond_t buffer_not_empty; // Condition variable buffer not empty
pthread_cond_t buffer_not_full; // Condition variable buffer not full

int buffer[BUFFER_SIZE];
int buffer_count = 0;
int in = 0, out = 0;

void *producer(void *arg);
void *consumer(void *arg);

int main() {
    pthread_t producer_thread, consumer_thread; // Initialize thread variables
    
    // Initialize the mutex lock and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&buffer_not_empty, NULL);
    pthread_cond_init(&buffer_not_full, NULL);
    
    // Create the producer and consumer thread
    pthread_create(&producer_thread, NULL, &producer, NULL);
    pthread_create(&consumer_thread, NULL, &consumer, NULL);
    
    // Wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    // Destroy the mutex lock and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&buffer_not_empty);
    pthread_cond_destroy(&buffer_not_full);
    
    return 0;
}

void *producer(void *arg) {
    int item;
    for (int i=0; i<20; i++) { // Produce 20 items
        item = rand();
        pthread_mutex_lock(&mutex); // Lock the mutex
        
        // Wait if buffer is full
        while (buffer_count == BUFFER_SIZE) {
            printf("Buffer is full. Producer is waiting...\n");
            pthread_cond_wait(&buffer_not_full, &mutex);
        }
        
        // Produce item and add it to buffer
        buffer[in] = item;
        in++;
        in %= BUFFER_SIZE;
        buffer_count++;
        
        printf("Producer produced item %d. Buffer count is %d.\n", item, buffer_count);
        
        // Signal consumer that buffer is not empty
        pthread_cond_signal(&buffer_not_empty);
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    return NULL;
}

void *consumer(void *arg) {
    int item;
    for (int i=0; i<20; i++) { // Consume 20 items
        pthread_mutex_lock(&mutex); // Lock the mutex
        
        // Wait if buffer is empty
        while (buffer_count == 0) {
            printf("Buffer is empty. Consumer is waiting...\n");
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }
        
        // Consume item from buffer
        item = buffer[out];
        out++;
        out %= BUFFER_SIZE;
        buffer_count--;
        
        printf("Consumer consumed item %d. Buffer count is %d.\n", item, buffer_count);
        
        // Signal producer that buffer is not full
        pthread_cond_signal(&buffer_not_full);
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    return NULL;
}