//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define max size of the queue
#define MAX_SIZE 10

// Define queue data structure
typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = -1; // set front and rear to -1, indicating empty queue
}

// Check if the queue is empty
int isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

// Check if the queue is full
int isFull(Queue q) {
    return (q.rear == MAX_SIZE - 1);
}

// Add an element to the rear end of the queue
void enqueue(Queue* q, int val) {
    if (isFull(*q)) {
        printf("Queue is full.\n");
        return;
    }
    // If queue is empty, set front to 0
    if (isEmpty(*q)) {
        q->front = 0;
    }
    q->arr[++q->rear] = val;
    printf("%d enqueued.\n", val);
}

// Remove an element from the front end of the queue
int dequeue(Queue* q) {
    if (isEmpty(*q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int val = q->arr[q->front];
    // If front and rear are equal, set them back to -1, indicating empty queue
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front++;
    }
    printf("%d dequeued.\n", val);
    return val;
}

// Display the elements in the queue
void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    dequeue(&q);
    enqueue(&q, 4);
    display(q);
    return 0;
}