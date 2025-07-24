//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Declare the shared buffer and semaphores
char buffer[10];
sem_t filled, empty;

// Producer thread function
void *producer(void *arg) {
    int index = 0;
    char c;
    while (1) {
        c = 'A' + rand() % 26; // Generate a random capital letter
        sem_wait(&empty); // Wait for an empty space
        buffer[index++] = c; // Place the letter in the buffer and increment the index
        printf("Producer produced %c\n", c);
        if (index >= 10) {
            sem_post(&filled); // Signal that the buffer is full
            index = 0; // Reset the index
        }
    }
    return NULL;
}

// Consumer thread function
void *consumer(void *arg) {
    int index = 0;
    char c;
    while (1) {
        sem_wait(&filled); // Wait for a filled space
        c = buffer[index++]; // Get the letter from the buffer and increment the index
        printf("Consumer consumed %c\n", c);
        sem_post(&empty); // Signal that an empty space is available
        if (index >= 10) {
            index = 0; // Reset the index
        }
    }
    return NULL;
}

int main() {
    // Initialise the semaphores
    sem_init(&filled, 0, 0);
    sem_init(&empty, 0, 10);

    // Create the producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the semaphores
    sem_destroy(&filled);
    sem_destroy(&empty);

    return 0;
}