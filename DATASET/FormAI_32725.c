//FormAI DATASET v1.0 Category: Queue ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // maximum number of elements that can be stored in the queue

typedef struct {
    int front; // holds the index of the first element of the queue
    int rear; // holds the index of the last element of the queue
    int queue[MAX_QUEUE_SIZE]; // array to store the elements of the queue
} Queue;

// function to add an element to the queue
void enqueue(Queue *q, int element) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow! Cannot add element %d\n", element);
        return;
    }

    if (q->front == -1 && q->rear == -1) {
        // if the queue is empty, set both front and rear to 0
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }

    q->queue[q->rear] = element;
    printf("Element %d added to queue\n", element);
}

// function to remove an element from the queue
int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue underflow! Cannot remove element\n");
        return -1;
    }

    int element = q->queue[q->front];
    if (q->front == q->rear) {
        // if the queue has only one element, reset front and rear to -1
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return element;
}

// function to display the contents of the queue
void display(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Contents of queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = q.rear = -1; // set front and rear to -1 to indicate the queue is empty

    // enqueue some elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    // display the contents of the queue
    display(&q);

    // dequeue some elements
    int element = dequeue(&q);
    printf("Element %d removed from queue\n", element);

    element = dequeue(&q);
    printf("Element %d removed from queue\n", element);

    // display the contents of the queue again
    display(&q);

    // enqueue some more elements
    enqueue(&q, 5);
    enqueue(&q, 6);

    // display the contents of the queue again
    display(&q);

    return 0;
}