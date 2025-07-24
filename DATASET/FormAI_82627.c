//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 100

typedef struct {
    int front;
    int rear;
    int count;
    int data[MAX_QUEUE];
} CQueue;

void initCQueue(CQueue *cq) {
    cq->front = 0;
    cq->rear = -1;
    cq->count = 0;
}

int isEmpty(CQueue *cq) {
    return cq->count == 0;
}

int isFull(CQueue *cq) {
    return cq->count == MAX_QUEUE;
}

int size(CQueue *cq) {
    return cq->count;
}

void enqueue(CQueue *cq, int value) {
    if(isFull(cq)) {
        printf("The queue is full!\n");
        return;
    }
    cq->rear = (cq->rear + 1) % MAX_QUEUE;
    cq->data[cq->rear] = value;
    cq->count++;
}

int dequeue(CQueue *cq) {
    if(isEmpty(cq)) {
        printf("The queue is empty!\n");
        return -1;
    }
    int value = cq->data[cq->front];
    cq->front = (cq->front + 1) % MAX_QUEUE;
    cq->count--;
    return value;
}

void printCQueue(CQueue *cq) {
    if(isEmpty(cq)) {
        printf("The queue is empty!\n");
        return;
    }
    for(int i = cq->front; i != cq->rear; i = (i + 1) % MAX_QUEUE) {
        printf("%d ", cq->data[i]);
    }
    printf("%d\n", cq->data[cq->rear]);
}

int main() {
    CQueue cq;
    initCQueue(&cq);
    enqueue(&cq, 5);
    enqueue(&cq, 10);
    enqueue(&cq, 15);
    enqueue(&cq, 20);
    printf("The size of the queue is %d\n", size(&cq));
    printf("The queue is: ");
    printCQueue(&cq);
    dequeue(&cq);
    printf("The size of the queue is %d\n", size(&cq));
    printf("The queue is: ");
    printCQueue(&cq);
    return 0;
}