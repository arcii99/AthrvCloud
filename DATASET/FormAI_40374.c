//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUEUE_SIZE 10

// Structure for our queue
struct Queue {
    int arr[QUEUE_SIZE];
    int front, rear, size;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = q->rear = -1;
    q->size = 0;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isQueueFull(struct Queue* q) {
    return q->rear == QUEUE_SIZE - 1;
}

// Function to add an item to the queue
int enqueue(struct Queue* q, int item) {
    if (isQueueFull(q))
        return -1; // Queue is full
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = item;
    q->size++;
    return 0;
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    int item;
    if (isQueueEmpty(q))
        return -1; // Queue is empty
    item = q->arr[q->front];
    q->front++;
    q->size--;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Function to print the contents of the queue
void printQueue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

struct Queue q;
pthread_mutex_t mutex;

// The producer thread function
void* producer(void* arg) {
    int item;
    while (1) {
        item = rand() % 10; // Random integer between 0 and 9
        pthread_mutex_lock(&mutex); // Lock the mutex
        if (enqueue(&q, item) == -1) {
            printf("Queue is full. Producer waiting...\n");
            pthread_mutex_unlock(&mutex); // Unlock the mutex
            sleep(1); // Sleep for 1 second
        }
        else {
            printf("Produced item: %d\n", item);
            printQueue(&q);
            pthread_mutex_unlock(&mutex); // Unlock the mutex
            sleep(1); // Sleep for 1 second
        }
    }
    return NULL;
}

// The consumer thread function
void* consumer(void* arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex); // Lock the mutex
        if (isQueueEmpty(&q)) {
            printf("Queue is empty. Consumer waiting...\n");
            pthread_mutex_unlock(&mutex); // Unlock the mutex
            sleep(1); // Sleep for 1 second
        }
        else {
            item = dequeue(&q);
            printf("Consumed item: %d\n", item);
            printQueue(&q);
            pthread_mutex_unlock(&mutex); // Unlock the mutex
            sleep(1); // Sleep for 1 second
        }
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    initializeQueue(&q); // Initialize the queue
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex

    // Create the producer thread
    if (pthread_create(&prod_thread, NULL, producer, NULL)) {
        printf("Error creating producer thread.\n");
        return -1;
    }

    // Create the consumer thread
    if (pthread_create(&cons_thread, NULL, consumer, NULL)) {
        printf("Error creating consumer thread.\n");
        return -1;
    }

    // Wait for the threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    pthread_mutex_destroy(&mutex); // Destroy the mutex

    return 0;
}