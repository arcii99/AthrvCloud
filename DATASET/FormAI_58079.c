//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10

struct Queue{
    int data[MAX_QUEUE_SIZE];
    int front, rear;
};

void initQueue(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue *q){
    if(q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int isQueueFull(struct Queue *q){
    if(q->rear == MAX_QUEUE_SIZE-1)
        return 1;
    else
        return 0;
}

void enQueue(struct Queue *q, int num){
    if(isQueueFull(q)){
        printf("Oh no! The queue is already full. En-queuing failed.\n");
        return;
    }
    else if(isQueueEmpty(q)){
        q->front = q->rear = 0;
        q->data[q->rear] = num;
    }
    else{
        q->rear++;
        q->data[q->rear] = num;
    }
}

int deQueue(struct Queue *q){
    int i;
    int num;
    if(isQueueEmpty(q)){
        printf("Oh no! There's nothing to dequeue. De-queuing failed.\n");
        exit(EXIT_FAILURE);
    }
    else if(q->front == q->rear){
        num = q->data[q->front];
        q->front = q->rear = -1;
        return num;
    }
    else{
        num = q->data[q->front];
        for(i=q->front; i<q->rear; i++){
            q->data[i] = q->data[i+1];
        }
        q->rear--;
        return num;
    }
}

int main(){
    struct Queue q;
    initQueue(&q);
    enQueue(&q, 5);
    enQueue(&q, 8);
    enQueue(&q, 19);
    enQueue(&q, 16);
    printf("Elements of queue: %d %d %d %d\n", q.data[0], q.data[1], q.data[2], q.data[3]);
    printf("Front of queue: %d\n", q.data[q.front]);
    printf("Rear of queue: %d\n", q.data[q.rear]);
    deQueue(&q);
    deQueue(&q);
    printf("Elements of queue after dequeing: %d %d\n", q.data[0], q.data[1]);
    printf("Front of queue: %d\n", q.data[q.front]);
    printf("Rear of queue: %d\n", q.data[q.rear]);
    enQueue(&q, 27);
    enQueue(&q, 49);
    printf("Elements of queue after en-queuing again: %d %d %d\n", q.data[0], q.data[1], q.data[2]);
    printf("Front of queue: %d\n", q.data[q.front]);
    printf("Rear of queue: %d\n", q.data[q.rear]);
    return 0;
}