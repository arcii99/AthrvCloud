//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int producer_index = 0, consumer_index = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    int val;
    while (1) {
        val = rand() % 100; // generate random number to add to buffer
        sem_wait(&empty); // decrement empty semaphore
        pthread_mutex_lock(&mutex); // acquire lock
        buffer[producer_index] = val; // add to buffer
        printf("Producer produced value %d at index %d\n", val, producer_index);
        producer_index = (producer_index + 1) % BUFFER_SIZE; // increment producer index
        pthread_mutex_unlock(&mutex); // release lock
        sem_post(&full); // increment full semaphore
        sleep(1); // wait before producing again
    }
    return NULL;
}

void *consumer(void *arg) {
    int val;
    while (1) {
        sem_wait(&full); // decrement full semaphore
        pthread_mutex_lock(&mutex); // acquire lock
        val = buffer[consumer_index]; // remove from buffer
        printf("Consumer consumed value %d at index %d\n", val, consumer_index);
        consumer_index = (consumer_index + 1) % BUFFER_SIZE; // increment consumer index
        pthread_mutex_unlock(&mutex); // release lock
        sem_post(&empty); // increment empty semaphore
        sleep(2); // wait before consuming again
    }
    return NULL;
}

int main(void) {
    // initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // create producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // cleanup
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}