//FormAI DATASET v1.0 Category: Computer Biology ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_SIZE 10
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];
int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_produce = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_consume = PTHREAD_COND_INITIALIZER;

void *producer(void *arg);
void *consumer(void *arg);
int produce_item();
void consume_item(int item);

int main() {
    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];

    srand(time(NULL));

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producers[i], NULL, producer, NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumers[i], NULL, consumer, NULL);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    return 0;
}

void *producer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&can_produce, &mutex);
        }

        int item = produce_item();
        buffer[count++] = item;
        printf("Produced item: %d\n", item);

        pthread_cond_signal(&can_consume);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            pthread_cond_wait(&can_consume, &mutex);
        }

        int item = buffer[--count];
        printf("Consumed item: %d\n", item);
        consume_item(item);

        pthread_cond_signal(&can_produce);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int produce_item() {
    return rand() % 100;
}

void consume_item(int item) {
    // do some processing on the item
}