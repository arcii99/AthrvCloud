//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

void *producer(void *arg){
    int i;
    for(i = 0; i < BUFFER_SIZE; i++){
        // Lock the mutex before modifying shared buffer
        pthread_mutex_lock(&mutex);
        
        // If the buffer is full, wait for the consumer to consume some data
        while(counter == BUFFER_SIZE){
            pthread_cond_wait(&cond_var, &mutex);
        }
        
        // Insert item into buffer
        buffer[counter++] = i;
        printf("Producer produced item %d\n", i);
        
        // Signal consumer that an item is available
        pthread_cond_signal(&cond_var);
        
        // Unlock the mutex 
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg){
    int i, item;
    while(1){
        // Lock the mutex before modifying shared buffer
        pthread_mutex_lock(&mutex);
        
        // If the buffer is empty, wait for the producer to produce some data
        while(counter == 0){
            pthread_cond_wait(&cond_var, &mutex);
        }
        
        // Remove item from buffer
        item = buffer[--counter];
        printf("Consumer consumed item %d\n", item);
        
        // Signal producer that buffer has space
        pthread_cond_signal(&cond_var);
        
        // Unlock the mutex 
        pthread_mutex_unlock(&mutex);
        
        // Do some processing on the consumed item 
        // ...
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}