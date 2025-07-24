//FormAI DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
// Unique C Queue Implementation Example Program in Asynchronous Style
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define QUEUE_SIZE 10

int queue[QUEUE_SIZE], front = -1, rear = -1; // Global variables for queue

sem_t empty, full; // Semaphores for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for locking and unlocking

void* producer(void* arg); // Producer function
void* consumer(void* arg); // Consumer function

int main() {
    pthread_t tid1, tid2; // Thread identifiers
    int rc1, rc2; // Return codes

    // Initializing semaphores
    sem_init(&empty, 0, QUEUE_SIZE);
    sem_init(&full, 0, 0);

    // Creating producer and consumer threads
    if((rc1 = pthread_create(&tid1, NULL, producer, NULL))) {
        printf("Producer thread creation failed with error code %d", rc1);
        exit(1);
    }
    if((rc2 = pthread_create(&tid2, NULL, consumer, NULL))) {
        printf("Consumer thread creation failed with error code %d", rc2);
        exit(1);
    }

    // Joining threads
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Destroying semaphores
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

void* producer(void* arg) {
    int item;

    while(1) {
        item = rand() % 100 + 1; // Generating random number from 1 to 100

        sem_wait(&empty); // Waiting on empty semaphore
        pthread_mutex_lock(&mutex); // Locking mutex

        if (rear == QUEUE_SIZE - 1) {
            printf("\nQueue Overflow");
            exit(1);
        }
        else if (front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = item;
            printf("\nProducer inserted item %d into queue", item);
        }
        else {
            rear++;
            queue[rear] = item;
            printf("\nProducer inserted item %d into queue", item);
        }

        pthread_mutex_unlock(&mutex); // Unlocking mutex
        sem_post(&full); // Signaling full semaphore
    }
}

void* consumer(void* arg) {
    int item;

    while(1) {
        sem_wait(&full); // Waiting on full semaphore
        pthread_mutex_lock(&mutex); // Locking mutex

        if (front == -1 && rear == -1) {
            printf("\nQueue Underflow");
            exit(1);
        }
        else if (front == rear) {
            item = queue[front];
            front = rear = -1;
            printf("\nConsumer removed item %d from queue", item);
        }
        else {
            item = queue[front];
            front++;
            printf("\nConsumer removed item %d from queue", item);
        }

        pthread_mutex_unlock(&mutex); // Unlocking mutex
        sem_post(&empty); // Signaling empty semaphore
    }
}