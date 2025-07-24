//FormAI DATASET v1.0 Category: Queue ; Style: enthusiastic
#include <stdio.h>
#define MAX 5

// Declare a struct named Queue
struct Queue {

    int front;
    int rear;
    int items[MAX];
};

// Initialize the Queue
void initializeQueue(struct Queue *q) {

    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(struct Queue *q) {

    if (q->rear == MAX-1)
        return 1;
    else
        return 0;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {

    if (q->front == -1)
        return 1;
    else
        return 0;
}

// Enqueue item into the queue
void enqueue(struct Queue *q, int value) {

    if (isFull(q)) {
        printf("\nQueue is full! Cannot enqueue any more values!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("\nInserted %d into Queue", value);
}

// Dequeue item from the queue
int dequeue(struct Queue *q) {

    int item;
    if (isEmpty(q)) {
        printf("\nQueue is empty! Cannot dequeue any values!\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        printf("\nResetting queue!\n");
        q->front = q->rear = -1;
    }
    printf("\nRemoved %d from Queue", item);
    return item;
}

// Display the entire queue
void display(struct Queue *q) {

    int i;
    if (isEmpty(q)) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue content: ");
    for (i=q->front; i<=q->rear; i++) {
        printf("%d ", q->items[i]);
    }
}

// Main function that creates the queue and calls all functions
int main() {
    struct Queue q;
    initializeQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 23);
    enqueue(&q, 54);
    enqueue(&q, 6);
    enqueue(&q, 77);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 11);
    enqueue(&q, 89);
    display(&q);
    return 0;
}