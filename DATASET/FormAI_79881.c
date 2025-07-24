//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ITEMS 5

int inventory[MAX_ITEMS];
int num_items = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv_produce = PTHREAD_COND_INITIALIZER;
pthread_cond_t cv_consume = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (num_items == MAX_ITEMS) {
            printf("Producer %d: inventory full, waiting to produce...\n", id);
            pthread_cond_wait(&cv_produce, &mutex);
        }
        inventory[num_items++] = id;
        printf("Producer %d produced item %d\n", id, num_items);
        pthread_cond_broadcast(&cv_consume);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (num_items == 0) {
            printf("Consumer %d: inventory empty, waiting to consume...\n", id);
            pthread_cond_wait(&cv_consume, &mutex);
        }
        int item = inventory[--num_items];
        printf("Consumer %d consumed item %d\n", id, item);
        pthread_cond_broadcast(&cv_produce);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_threads[3];
    pthread_t consumer_threads[2];
    int i, id;

    for (i = 0; i < 3; i++) {
        id = i + 1;
        pthread_create(&producer_threads[i], NULL, producer, &id);
    }
    for (i = 0; i < 2; i++) {
        id = i + 1;
        pthread_create(&consumer_threads[i], NULL, consumer, &id);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(producer_threads[i], NULL);
    }
    for (i = 0; i < 2; i++) {
        pthread_join(consumer_threads[i], NULL);
    }

    return 0;
}