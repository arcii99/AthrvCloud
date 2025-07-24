//FormAI DATASET v1.0 Category: Queue ; Style: happy
// Yay! Let's create a happy C Queue program example!
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int q_array[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Let's create a happy function to create the queue
void createQueue(Queue *q) {
    q -> front = q -> rear = -1;
    printf("Queue successfully created! Yay!\n");
}

// Let's create a happy function to check if the queue is empty
int isQueueEmpty(Queue q) {
    if (q.front == -1 && q.rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Let's create a happy function to check if the queue is full
int isQueueFull(Queue q) {
    if ((q.rear+1)%MAX_QUEUE_SIZE == q.front) {
        return 1;
    } else {
        return 0;
    }
}

// Let's create a happy function to add an element to the queue
void enqueue(Queue *q, int element) {
    if (isQueueFull(*q)) {
        printf("Queue is full. Oh no! :(\n");
        return;
    } else if (isQueueEmpty(*q)) {
        q -> front = q -> rear = 0;
    } else {
        q -> rear = (q -> rear + 1)%MAX_QUEUE_SIZE;
    }

    q -> q_array[q -> rear] = element;
    printf("Yay! Element %d successfully added to the queue!\n", element);
}

// Let's create a happy function to remove an element from the queue
void dequeue(Queue *q) {
    if (isQueueEmpty(*q)) {
        printf("Queue is empty. Oh no! :(\n");
        return;
    } else if (q -> front == q -> rear) {
        q -> front = q -> rear = -1;
    } else {
        q -> front = (q -> front + 1)%MAX_QUEUE_SIZE;
    }

    printf("Yay! Element successfully removed from the queue! :D\n");
}

// Let's create a happy function to display the elements of the queue
void displayQueue(Queue q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Oh no! :(\n");
        return;
    }

    printf("Here are the current elements of the queue: \n");
    int i, j;
    for (i = q.front, j = q.rear; i <= j; i = (i+1)%MAX_QUEUE_SIZE) {
        printf("%d ", q.q_array[i]);
    }
    printf("\nHappy queue displaying complete! :D\n");
}

// Yay! Let's test our happy C Queue program example!
int main() {
    Queue q;

    createQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    enqueue(&q, 25);
    enqueue(&q, 30);
    enqueue(&q, 35);
    enqueue(&q, 40);
    enqueue(&q, 45);
    enqueue(&q, 50);
    enqueue(&q, 55);
    
    displayQueue(q);

    dequeue(&q);

    displayQueue(q);

    enqueue(&q, 60);

    displayQueue(q);

    return 0;
}

// Happy C Queue program example complete! Yay! :)