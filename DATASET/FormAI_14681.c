//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 50

typedef struct{
    int front, rear, size;
    int elements[MAX_QUEUE_SIZE];
} Queue;

void initialize(Queue *q){
    q->front = q->rear = q->size = 0;
}

int isFull(Queue *q){
    return q->size == MAX_QUEUE_SIZE;
}

int isEmpty(Queue *q){
    return q->size == 0;
}

int enqueue(Queue *q, int data){
    if(isFull(q)){
        printf("Error: Queue is full\n");
        return 0;
    }
    q->elements[q->rear] = data;
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->size++;
    return 1;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Error: Queue is empty\n");
        return -1;
    }
    int data = q->elements[q->front];
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    q->size--;
    return data;
}

int main(){
    Queue q;
    initialize(&q);

    //Enqueue elements 1 - 10 into the queue
    for(int i = 1; i <= 10; i++){
        if(enqueue(&q, i)){
            printf("Enqueued %d\n", i);
        }
    }

    //Try to enqueue 11 into the queue but should fail
    if(!enqueue(&q, 11)){
        printf("Enqueue failed\n");
    }

    //Dequeue all elements and print them out
    while(!isEmpty(&q)){
        printf("Dequeued %d\n", dequeue(&q));
    }

    //Try to dequeue from an empty queue but should fail
    if(dequeue(&q) == -1){
        printf("Dequeue failed\n");
    }

    return 0;
}