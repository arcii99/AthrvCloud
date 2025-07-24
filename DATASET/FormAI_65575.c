//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int value) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front){
        printf("WOW! The queue is already full. You can't enqueue anymore.\n");
        // Initializing the queue once again for the next run.
        q->front = 0;
        q->rear = -1;
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = value;
        printf("AMAZING! %d has been enqueued successfully.\n", value);
    }
}

int dequeue(Queue* q) {
    int value;
    if (q->front > q->rear) {
        printf("INCONCEIVABLE! The queue is empty. There is nothing to dequeue.\n");
        // Initializing the queue once again for the next run.
        q->front = 0;
        q->rear = -1;
        return -1;
    }
    else {
        value = q->data[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        printf("ASTONISHING! %d has been dequeued successfully.\n", value);
        return value;
    }
}

int main() {
    Queue q;

    q.front = 0;
    q.rear = -1;

    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55);

    // Dequeueing all elements from the queue
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;
}