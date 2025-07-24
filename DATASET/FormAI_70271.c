//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];
int bufferCount = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bufferNotEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotFull = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    int idx = *(int*)arg;
    while(1) {
        pthread_mutex_lock(&lock);
        while(bufferCount == BUFFER_SIZE) {
            pthread_cond_wait(&bufferNotFull, &lock);
        }
        int item = rand() % 100;
        buffer[bufferCount++] = item;
        printf("Producer %d produced %d\n", idx, item);
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&bufferNotEmpty);
        sleep(1);
    }
}

void* consumer(void* arg) {
    int idx = *(int*)arg;
    while(1) {
        pthread_mutex_lock(&lock);
        while(bufferCount == 0) {
            pthread_cond_wait(&bufferNotEmpty, &lock);
        }
        int item = buffer[--bufferCount];
        printf("Consumer %d consumed %d\n", idx, item);
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&bufferNotFull);
        sleep(1);
    }
}

int main() {
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    int producerIds[NUM_PRODUCERS], consumerIds[NUM_CONSUMERS];

    for(int i=0; i<NUM_PRODUCERS; i++) {
        producerIds[i] = i+1;
        pthread_create(&producers[i], NULL, producer, &producerIds[i]);
    }
    for(int i=0; i<NUM_CONSUMERS; i++) {
        consumerIds[i] = i+1;
        pthread_create(&consumers[i], NULL, consumer, &consumerIds[i]);
    }

    for(int i=0; i<NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }
    for(int i=0; i<NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }
    
    pthread_exit(NULL);
    return 0;
}