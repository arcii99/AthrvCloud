//FormAI DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t count_sem; // Semaphore to protect count variable
sem_t action_sem; // Semaphore to signal action is available
int count = 0; // Global variable to keep count

void *producer(void *arg) {
    int i;
    for(i=0; i<10; i++) {
        sem_wait(&count_sem); // Wait for count semaphore
        count++; // Increment the count variable
        printf("Producer produced item %d\n", count);
        sem_post(&action_sem); // Signal action semaphore
    }
    return NULL;
}

void *consumer(void *arg) {
    int i;
    for(i=0; i<10; i++) {
        sem_wait(&action_sem); // Wait for action semaphore
        printf("Consumer consumed item %d\n", count);
        sem_post(&count_sem); // Signal count semaphore
    }
    return NULL;
}

int main() {
    sem_init(&count_sem, 0, 1); // Initialize count semaphore to 1
    sem_init(&action_sem, 0, 0); // Initialize action semaphore to 0

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL); // Start producer thread
    pthread_create(&consumer_thread, NULL, consumer, NULL); // Start consumer thread

    pthread_join(producer_thread, NULL); // Wait for producer thread to complete
    pthread_join(consumer_thread, NULL); // Wait for consumer thread to complete

    sem_destroy(&count_sem); // Destroy count semaphore
    sem_destroy(&action_sem); // Destroy action semaphore
    return 0;
}