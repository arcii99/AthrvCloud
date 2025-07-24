//FormAI DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

/* Define the Queue structure */
#define MAX_QUEUE_SIZE 50
struct Queue {
    int arr[MAX_QUEUE_SIZE];
    int front, rear, size;
};

/* Initialize a new Queue */
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

/* Insert an element to the rear of the Queue */
void enqueue(struct Queue* queue, int num) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->arr[queue->rear] = num;
        queue->size++;
    }
}

/* Remove an element from the front of the Queue */
int dequeue(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int num = queue->arr[queue->front];
        queue->front++;
        queue->size--;
        return num;
    }
}

/* Get the element at the front of the Queue */
int front(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue->arr[queue->front];
    }
}

/* Get the element at the rear of the Queue */
int rear(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue->arr[queue->rear];
    }
}

/* Print all elements in the Queue */
void printQueue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    printf("Queue size: %d\n", queue.size);
    enqueue(&queue, 10);
    printf("Queue front: %d\n", front(&queue));
    printf("Queue rear: %d\n", rear(&queue));
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printf("Queue elements: ");
    printQueue(&queue);
    printf("Queue size: %d\n", queue.size);
    dequeue(&queue);
    printf("Queue front: %d\n", front(&queue));
    printf("Queue elements: ");
    printQueue(&queue);
    printf("Queue size: %d\n", queue.size);

    return 0;
}