//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// define the maximum size of the queue
#define MAX_QUEUE_SIZE 10

// define the Queue structure
typedef struct {
    int elements[MAX_QUEUE_SIZE];
    int rear, front;
    int size;
} Queue;

// function to initialize the Queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// function to check if the Queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// function to check if the Queue is full
int isFull(Queue* queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

// function to add an element to the Queue (enqueue)
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    }
    else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->elements[queue->rear] = element;
        if (queue->front == -1) {
            queue->front = queue->rear;
        }
        queue->size++;
    }
}

// function to remove an element from the Queue (dequeue)
int dequeue(Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        element = queue->elements[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        else {
            queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        }
        queue->size--;
        return element;
    }
}

// function to display the elements in the Queue
void display(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements : ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
            printf("%d ", queue->elements[i]);
        }
        printf("%d", queue->elements[i]);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);

    // basic enqueue and dequeue operations
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("Dequeued element : %d\n", dequeue(&queue));
    printf("Dequeued element : %d\n", dequeue(&queue));
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);

    return 0;
}