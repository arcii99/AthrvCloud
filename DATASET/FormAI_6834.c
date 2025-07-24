//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int val) {
    if (q->rear == MAX_QUEUE_SIZE - 1)
        printf("Queue Overflow\n");
    else {
        if (q->front == -1) // if queue is initially empty
            q->front = 0;
        q->rear++;
        q->items[q->rear] = val;
        printf("%d inserted into queue\n", val);
    }
}

int dequeue(Queue *q) {
    int val;
    if (q->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        val = q->items[q->front];
        if (q->front >= q->rear) { // if last element is being removed
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        return val;
    }
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));
    
    return 0;
}