//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // The maximum size of the queue

typedef struct {
    int front;
    int rear;
    int items[MAX_SIZE];
} Queue;

void initQueue(Queue *q) {
    q->front = -1;  // Initially, the front is set to -1
    q->rear = -1;   // Initially, the rear is set to -1
}

int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);   // If the rear has reached the maximum size, the queue is full
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);   // If both front and rear are -1, the queue is empty
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {    // If the queue is full, print a message and exit the function
        printf("Sorry, the queue is full!\n");
        return;
    } else if (isEmpty(q)) {    // If the queue is empty, increment front and rear to 0 and add the item
        q->front = 0;
        q->rear = 0;
        q->items[q->rear] = value;
    } else {                    // Otherwise, increment rear and add the item
        q->rear++;
        q->items[q->rear] = value;
    }
    printf("Wow, the item %d has been added to the queue!\n", value);
}

int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {           // If the queue is empty, print a message and return -1
        printf("Sorry, the queue is empty!\n");
        return -1;
    } else if (q->front == q->rear) {    // If there is only one item in the queue, set front and rear to -1
        item = q->items[q->front];
        q->front = -1;
        q->rear = -1;
    } else {                    // Otherwise, get the item from the front and increment the front
        item = q->items[q->front];
        q->front++;
    }
    printf("Abracadabra! The item %d has been removed from the queue!\n", item);
    return item;
}

void display(Queue *q) {
    int i;
    if (isEmpty(q)) {           // If the queue is empty, print a message and exit the function
        printf("Sorry, the queue is empty!\n");
        return;
    }
    printf("The items in the queue are: ");
    for (i = q->front; i <= q->rear; i++) {    // Print all the items in the queue
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    display(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 20);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    return 0;
}