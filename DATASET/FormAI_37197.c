//FormAI DATASET v1.0 Category: Data validation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

int data;
pthread_mutex_t mutex;
int threads_running = 0;

void* validate(void* arg) {
    int value = *((int*) arg);
    if (value >= 0 && value <= 100) {
        pthread_mutex_lock(&mutex);
        data = value;
        pthread_mutex_unlock(&mutex);
    }
    threads_running--;
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < MAX_THREADS; i++) {
        int* value = malloc(sizeof(int));
        *value = rand() % 200 - 50;
        pthread_create(&threads[i], NULL, validate, (void*) value);
        threads_running++;
    }

    while (threads_running > 0) {}

    pthread_mutex_destroy(&mutex);

    printf("Valid data: %d\n", data);

    return 0;
}