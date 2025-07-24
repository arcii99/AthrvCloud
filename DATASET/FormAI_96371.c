//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int head = 0;
int tail = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

void enqueue(int item) {
    pthread_mutex_lock(&mutex);
    while ((tail + 1) % MAX_SIZE == head) {
        pthread_cond_wait(&full, &mutex);
    }
    queue[tail] = item;
    tail++;
    if (tail >= MAX_SIZE) {
        tail = 0;
    }
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    pthread_mutex_lock(&mutex);
    while (head == tail) {
        pthread_cond_wait(&empty, &mutex);
    }
    int item = queue[head];
    head++;
    if (head >= MAX_SIZE) {
        head = 0;
    }
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);
    return item;
}

void *producer(void *arg) {
    int i;
    for (i = 0; i < 100; i++) {
        printf("Producing item %d\n", i);
        enqueue(i);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i;
    int item;
    for (i = 0; i < 100; i++) {
        item = dequeue();
        printf("Consuming item %d\n", item);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}