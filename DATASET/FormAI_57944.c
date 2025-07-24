//FormAI DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdio.h>

#define MAX_SIZE 100

// Structure for Queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct Queue queue;

// initialize the queue
void initialize(queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Checks if the queue is full
int isFull(queue *q) {
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Checks if the queue is empty
int isEmpty(queue *q) {
    if (q->rear == -1) {
        return 1;
    }
    return 0;
}

// Adding an element to the queue
void enqueue(queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
    }
}

// Removing an element from the queue
int dequeue(queue *q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        element = -1;
    } else {
        element = q->items[q->front];
        if (q->front >= q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }

    return element;
}

// Driver code
int main() {
    queue q;

    initialize(&q);

    // Adding elements to the queue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    // Removing elements from the queue
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));

    return 0;
}