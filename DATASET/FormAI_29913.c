//FormAI DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

bool isQueueFull(Queue* queue) {
    if ((queue->front == 0 && queue->rear == MAX_QUEUE_SIZE-1) || queue->rear == queue->front-1)
        return true;
    return false;
}

bool isQueueEmpty(Queue* queue) {
    if (queue->front == -1)
        return true;
    return false;
}

void enqueue(Queue* queue) {
    if (isQueueFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);
    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == MAX_QUEUE_SIZE-1 && queue->front != 0)
        queue->rear = 0;
    else
        queue->rear++;
    queue->arr[queue->rear] = data;
    printf("Enqueued successfully!\n");
}

void dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->front == MAX_QUEUE_SIZE-1)
        queue->front = 0;
    else
        queue->front++;
    printf("Dequeued data: %d\n", data);
}

void displayQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    if (queue->rear >= queue->front) {
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->arr[i]);
    } else {
        for (int i = queue->front; i < MAX_QUEUE_SIZE; i++)
            printf("%d ", queue->arr[i]);
        for (int i = 0; i <= queue->rear; i++)
            printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    int choice;
    bool flag = true;
    while (flag) {
        printf("\n-- Queue Operations --\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(queue);
                    break;
            case 2: dequeue(queue);
                    break;
            case 3: displayQueue(queue);
                    break;
            case 4: flag = false;
                    break;
            default: printf("Invalid choice!\n");
        }
    }
    printf("Program terminated successfully!\n");
    return 0;
}