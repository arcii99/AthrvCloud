//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Queue structure
typedef struct queue {
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, int element);
int dequeue(Queue *q);
void display(Queue q);

int main() {
    // Initialize queue
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
    
    // Enqueue some elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    
    // Display queue
    printf("Queue after enqueue:\n");
    display(queue);
    
    // Dequeue an element
    dequeue(&queue);
    
    // Display queue
    printf("Queue after dequeue:\n");
    display(queue);
    
    // Enqueue more elements
    enqueue(&queue, 60);
    enqueue(&queue, 70);
    enqueue(&queue, 80);
    
    // Display queue
    printf("Queue after more enqueues:\n");
    display(queue);
    
    return 0;
}

void enqueue(Queue *q, int element) {
    if(q->rear == MAX_QUEUE_SIZE-1) {
        printf("Queue is full!\n");
        return;
    }
    else if(q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
    }
    else {
        q->rear++;
    }
    q->arr[q->rear] = element;
}

int dequeue(Queue *q) {
    if(q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    else if(q->front == q->rear) {
        int element = q->arr[q->front];
        q->front = q->rear = -1;
        return element;
    }
    else {
        int element = q->arr[q->front];
        q->front++;
        return element;
    }
}

void display(Queue q) {
    if(q.front == -1) {
        printf("Queue is empty!\n");
    }
    else {
        for(int i=q.front;i<=q.rear;i++) {
            printf("%d ", q.arr[i]);
        }
        printf("\n");
    }
}