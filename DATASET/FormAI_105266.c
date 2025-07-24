//FormAI DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// define the maximum size of the queue
#define MAX_SIZE 10

typedef struct Queue {
    int front;
    int rear;
    int size;
    int arr[MAX_SIZE];
} Queue;

// function to initialize the queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        q->arr[i] = 0;
    }
}

// function to check if the queue is empty
int is_empty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if the queue is full
int is_full(Queue *q) {
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// function to add an element to the queue
void enqueue(Queue *q, int val) {
    if (is_full(q)) {
        printf("Queue is full.\n");
    } else if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = val;
        q->size++;
        printf("Value added to the queue.\n");
    } else {
        q->rear++;
        q->arr[q->rear] = val;
        q->size++;
        printf("Value added to the queue.\n");
    }
}

// function to remove an element from the queue
int dequeue(Queue *q) {
    int val;
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else if (q->front == q->rear) {
        val = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        q->size--;
        return val;
    } else {
        val = q->arr[q->front];
        q->front++;
        q->size--;
        return val;
    }
}

// function to display the queue
void display(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    init(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    
    enqueue(&q, 40);
    enqueue(&q, 50);
    
    display(&q);
    
    return 0;
}