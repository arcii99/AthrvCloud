//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 50

typedef struct {
    int queue[QUEUE_SIZE];
    int front, rear;
} Queue;

int isFull(Queue *q){
    if(q->rear == QUEUE_SIZE - 1){
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int data){
    if(isFull(q)){
        printf("Overflow! Queue is full.\n");
        return;
    }
    q->rear++;
    q->queue[q->rear] = data;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Underflow! Queue is empty.\n");
        return -1;
    }
    q->front++;
    return q->queue[q->front];
}

int main(){
    Queue q;
    q.front = 0;
    q.rear = -1;

    printf("Queue Implementation in C\n");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue: ");
    while(!isEmpty(&q)){
        printf("%d ", dequeue(&q));
    }

    return 0;
}