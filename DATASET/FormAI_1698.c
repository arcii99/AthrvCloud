//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define NUM_THREADS 2
#define MAX_COUNT 20

int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex;
pthread_cond_t buffer_full;
pthread_cond_t buffer_empty;

void *producer(void *arg) {
    int item, i;
    for (i = 0; i < MAX_COUNT; i++) {
        item = rand() % 100; // Generate a random item
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&buffer_full, &mutex);
        }
        buffer[count++] = item;
        printf("Producer produced item %d\n", item);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&buffer_empty);
        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item, i;
    for (i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            pthread_cond_wait(&buffer_empty, &mutex);
        }
        item = buffer[--count];
        printf("Consumer consumed item %d\n", item);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&buffer_full);
        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&buffer_full, NULL);
    pthread_cond_init(&buffer_empty, NULL);
    pthread_create(&threads[0], NULL, producer, NULL);
    pthread_create(&threads[1], NULL, consumer, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_cond_destroy(&buffer_full);
    pthread_cond_destroy(&buffer_empty);
    pthread_mutex_destroy(&mutex);
    return 0;
}