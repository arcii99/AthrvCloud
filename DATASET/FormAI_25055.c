//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 10 // Maximum number of threads
#define MAX_QUEUE_SIZE 100 // Maximum queue size

int queue[MAX_QUEUE_SIZE]; // Shared resource
int queueSize = 0; // Current size of the queue
int nextIn = 0; // Index of next element to be inserted
int nextOut = 0; // Index of next element to be removed

pthread_mutex_t mutex; // Mutex to synchronize access to queue
pthread_cond_t condEmpty; // Condition variable to signal when queue is empty
pthread_cond_t condFull; // Condition variable to signal when queue is full

// Function to add element to queue
void enqueue(int val) {
    pthread_mutex_lock(&mutex);
    while (queueSize >= MAX_QUEUE_SIZE) {
        // Wait until queue is not full
        pthread_cond_wait(&condFull, &mutex);
    }
    queue[nextIn] = val;
    nextIn = (nextIn + 1) % MAX_QUEUE_SIZE;
    queueSize++;
    pthread_cond_signal(&condEmpty);
    pthread_mutex_unlock(&mutex);
}

// Function to remove element from queue
int dequeue() {
    int val;
    pthread_mutex_lock(&mutex);
    while (queueSize <= 0) {
        // Wait until queue is not empty
        pthread_cond_wait(&condEmpty, &mutex);
    }
    val = queue[nextOut];
    nextOut = (nextOut + 1) % MAX_QUEUE_SIZE;
    queueSize--;
    pthread_cond_signal(&condFull);
    pthread_mutex_unlock(&mutex);
    return val;
}

// Thread function to add elements to queue
void *producer(void *arg) {
    long id = (long) arg;
    int value = id * 1000;
    for (int i = 0; i < 10; i++) {
        printf("Producer %ld enqueuing %d\n", id, value);
        enqueue(value);
        value++;
    }
    pthread_exit(NULL);
}

// Thread function to remove elements from queue
void *consumer(void *arg) {
    long id = (long) arg;
    for (int i = 0; i < 5; i++) {
        int value = dequeue();
        printf("Consumer %ld dequeuing %d\n", id, value);
        sleep(1);
    }
    pthread_exit(NULL);
}

// Main function
int main() {
    pthread_t threads[MAX_THREADS];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condEmpty, NULL);
    pthread_cond_init(&condFull, NULL);
    for (long i = 0; i < MAX_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, producer, (void *) i);
        } else {
            pthread_create(&threads[i], NULL, consumer, (void *) i);
        }
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condEmpty);
    pthread_cond_destroy(&condFull);
    return 0;
}