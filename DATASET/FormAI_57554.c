//FormAI DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

// defining the maximum size of the queue
#define MAX_SIZE 10

// defining the queue data structure
struct Queue {
    int array[MAX_SIZE];
    int front, rear;
};

// initializing the queue as an empty queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// function to check if the queue is empty
int isEmpty(struct Queue *q) {
    if(q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

// function to check if the queue is full
int isFull(struct Queue *q) {
    if(q->rear == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

// function to add an element to the queue
void enqueue(struct Queue *q, int data) {
    if(isFull(q)) {
        printf("Queue is full!");
        return;
    }
    else if(isEmpty(q)) {
        q->front = q->rear = 0;
        q->array[q->rear] = data;
    }
    else {
        q->rear++;
        q->array[q->rear] = data;
    }
}

// function to remove an element from the queue
int dequeue(struct Queue *q) {
    int temp;
    if(isEmpty(q)) {
        printf("Queue is empty!");
        return -1;
    }
    else if(q->front == q->rear) {
        temp = q->array[q->front];
        q->front = q->rear = -1;
    }
    else {
        temp = q->array[q->front];
        q->front++;
    }
    return temp;
}

// function to display the elements in the queue
void display(struct Queue *q) {
    if(isEmpty(q))
        printf("Queue is empty!");
    else {
        printf("Queue elements are: ");
        for(int i=q->front; i<=q->rear; i++)
            printf("%d ", q->array[i]);
    }
}

// main function to test the queue implementation
int main() {
    struct Queue q;
    initializeQueue(&q);
    
    // testing enqueue operation
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    
    // testing dequeue operation
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    
    // testing display operation
    display(&q);
    
    return 0;
}