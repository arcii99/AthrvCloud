//FormAI DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = q->size = 0;
}

int isFull(Queue *q) {
    return q->size == MAX_SIZE;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full. Cannot Enqueue.\n");
        return;
    }

    q->arr[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty. Cannot Dequeue.\n");
        return -1;
    }

    int value = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;

    return value;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty. Cannot Display.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    do {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != q->rear);
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    //enqueue some elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5); //queue is now full, cannot enqueue

    display(&q); //display the queue: 1 2 3 4 5

    //dequeue some elements
    dequeue(&q);
    dequeue(&q);
    display(&q); //display the remaining elements: 3 4 5

    //enqueue some more elements
    enqueue(&q, 6);
    enqueue(&q, 7);
    display(&q); //display the updated queue: 3 4 5 6 7

    return 0;
}