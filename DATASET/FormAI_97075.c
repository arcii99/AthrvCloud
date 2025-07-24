//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex;
pthread_cond_t cond_empty;
pthread_cond_t cond_full;

void *producer(void *ptr) {
    int item = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            printf("Buffer is full! Producer is waiting...\n");
            pthread_cond_wait(&cond_empty, &mutex);
        }
        item = rand() % 100;
        buffer[count++] = item;
        printf("Producer produced item: %d\n", item);
        pthread_cond_signal(&cond_full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *consumer(void *ptr) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            printf("Buffer is empty! Consumer is waiting...\n");
            pthread_cond_wait(&cond_full, &mutex);
        }
        int item = buffer[--count];
        printf("Consumer consumed item: %d\n", item);
        pthread_cond_signal(&cond_empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[2];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_empty, NULL);
    pthread_cond_init(&cond_full, NULL);
    pthread_create(&threads[0], NULL, producer, NULL);
    pthread_create(&threads[1], NULL, consumer, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;
}