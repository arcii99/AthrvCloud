//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100 // maximum size of the queue
#define MAX_BAGGAGE_SIZE 30 // maximum size of the luggage
#define MAX_PROCESSING_TIME 10 // maximum time it takes to process a luggage

typedef int QueueElement; // data type of the queue elements

typedef struct {
    int front; // front index of the queue
    int rear; // rear index of the queue
    int count; // number of elements in the queue
    QueueElement elements[MAX_QUEUE_SIZE]; // elements in the queue
} Queue;

void initialize(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isFull(Queue *q) {
    return q->count == MAX_QUEUE_SIZE;
}

bool isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, QueueElement x) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->elements[q->rear] = x;
    ++q->count;
}

QueueElement dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        exit(1);
    }
    QueueElement x = q->elements[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    --q->count;
    return x;
}

int main() {
    Queue q;
    initialize(&q);

    int num_luggage = rand() % MAX_QUEUE_SIZE; // generate random number of luggages
    printf("Number of luggage = %d\n", num_luggage);

    int total_processing_time = 0; // total time to process the luggage

    for (int i = 0; i < num_luggage; ++i) {
        int luggage_size = rand() % MAX_BAGGAGE_SIZE + 1; // generate random luggage size
        printf("Luggage %d size = %d\n", i + 1, luggage_size);

        enqueue(&q, luggage_size);

        int processing_time = rand() % MAX_PROCESSING_TIME + 1; // generate random processing time
        printf("Luggage %d processing time = %d\n", i + 1, processing_time);

        total_processing_time += processing_time;
    }

    printf("Total processing time = %d\n", total_processing_time);

    while (!isEmpty(&q)) {
        int luggage_size = dequeue(&q);
        printf("Processing luggage size = %d\n", luggage_size);

        int processing_time = rand() % MAX_PROCESSING_TIME + 1; // generate random processing time
        printf("Processing time = %d\n", processing_time);

        total_processing_time -= processing_time;
    }

    printf("Total processing time remaining = %d\n", total_processing_time);

    return 0;
}