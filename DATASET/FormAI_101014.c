//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

// Circular buffer
int buffer[BUFFER_SIZE];

// Threading variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER;

int buffer_index = 0;

// Add to buffer
void add_item(int item) {
    pthread_mutex_lock(&mutex);
    
    // Wait until buffer is not full
    while(buffer_index == BUFFER_SIZE) {
        pthread_cond_wait(&buffer_not_full, &mutex);
    }
    
    buffer[buffer_index++] = item;
    
    // Notify consumer that buffer is not empty
    pthread_cond_signal(&buffer_not_empty);
    
    pthread_mutex_unlock(&mutex);
}

// Remove from buffer
int remove_item() {
    int item;
    
    pthread_mutex_lock(&mutex);
    
    // Wait until buffer is not empty
    while(buffer_index == 0) {
        pthread_cond_wait(&buffer_not_empty, &mutex);
    }
    
    item = buffer[--buffer_index];
    
    // Notify producer that buffer is not full
    pthread_cond_signal(&buffer_not_full);
    
    pthread_mutex_unlock(&mutex);
    
    return item;
}

// Producer thread
void *producer_thread(void *arg) {
    int item = 0;
    
    while(1) {
        sleep(1); // Sleep for 1 second
        
        item++;
        printf("Producer produced item %d\n", item);
        
        add_item(item);
    }
    
    pthread_exit(NULL);
}

// Consumer thread
void *consumer_thread(void *arg) {
    int item;
    
    while(1) {
        sleep(1); // Sleep for 1 second
        
        item = remove_item();
        printf("Consumer consumed item %d\n", item);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t producer, consumer;
    
    // Create producer and consumer threads
    pthread_create(&producer, NULL, producer_thread, NULL);
    pthread_create(&consumer, NULL, consumer_thread, NULL);
    
    // Wait for threads to finish
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    
    return 0;
}