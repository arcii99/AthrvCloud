//FormAI DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

pthread_mutex_t lock;
pthread_cond_t cv_producer, cv_consumer;

void *producer(void *arg) {
    int item = 0;

    while(1) {
        item++;

        pthread_mutex_lock(&lock);
        while ((in + 1) % BUFFER_SIZE == out) { // check if buffer is full
            printf("Buffer is full. Producer waiting...\n");
            pthread_cond_wait(&cv_producer, &lock);
        }
        
        buffer[in] = item; // place item in buffer
        in = (in + 1) % BUFFER_SIZE;

        printf("Produced item: %d\n", item);

        pthread_cond_signal(&cv_consumer); // notify consumer
        pthread_mutex_unlock(&lock);
    }
}

void *consumer(void *arg) {
    int item;

    while(1) {
        pthread_mutex_lock(&lock);
        while (in == out) { // check if buffer is empty
            printf("Buffer is empty. Consumer waiting...\n");
            pthread_cond_wait(&cv_consumer, &lock);
        }

        item = buffer[out]; // remove item from buffer
        out = (out + 1) % BUFFER_SIZE;

        printf("Consumed item: %d\n", item);

        pthread_cond_signal(&cv_producer); // notify producer
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;
    int rc;

    // initialize mutex and condition variables
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cv_producer, NULL);
    pthread_cond_init(&cv_consumer, NULL);

    // create threads
    rc = pthread_create(&producer_thread, NULL, producer, NULL);
    if (rc != 0) {
        fprintf(stderr, "Error: Unable to create producer thread.\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&consumer_thread, NULL, consumer, NULL);
    if (rc != 0) {
        fprintf(stderr, "Error: Unable to create consumer thread.\n");
        exit(EXIT_FAILURE);
    }

    // wait for threads to finish
    rc = pthread_join(producer_thread, NULL);
    if (rc != 0) {
        fprintf(stderr, "Error: Unable to join producer thread.\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_join(consumer_thread, NULL);
    if (rc != 0) {
        fprintf(stderr, "Error: Unable to join consumer thread.\n");
        exit(EXIT_FAILURE);
    }

    // cleanup
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cv_producer);
    pthread_cond_destroy(&cv_consumer);

    return 0;
}