//FormAI DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
   int data[MAX_SIZE];
   int front;
   int rear;
} Queue;

// Function to initialize the queue
void init(Queue *q){
    q->front = -1;
    q->rear = -1;
}

// Function to check if queue is empty
int isEmpty(Queue *q){
    if(q->front == -1 && q->rear == -1)
        return 1;
    return 0;
}

// Function to check if queue is full
int isFull(Queue *q){
    if(q->rear == MAX_SIZE-1)
        return 1;
    return 0;
}


// Function to add an element to the end of the queue
void enqueue(Queue *q, int val){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }
    else if(isEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear++;

    q->data[q->rear] = val;
    printf("%d was enqueued.\n", val);
}

// Function to remove element from the front of the queue
void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    else if(q->front == q->rear){
        printf("%d was dequeued.\n", q->data[q->front]);
        init(q);
    }
    else{
        printf("%d was dequeued.\n", q->data[q->front]);
        q->front++;
    }
}

// Function to print the queue
void print(Queue *q){
    int i;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue is: ");
    for(i=q->front; i<=q->rear; i++)
        printf("%d ",q->data[i]);
    printf("\n");
}

int main(){
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    printf("Is queue empty? %d\n", isEmpty(&q));
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    print(&q);
    printf("Is queue full? %d\n", isFull(&q));
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    print(&q);
    return 0;
}