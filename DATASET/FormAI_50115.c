//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10
typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int value){
    if(q->rear < MAX_QUEUE_SIZE - 1) {
        q->rear++;
        q->items[q->rear] = value;
    } else {
        printf("Queue overflow!\n");
    }
}

int dequeue(Queue *q) {
    int item;
    if(q->front > q->rear) {
        printf("Queue underflow!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
    }
    return item;
}

void display(Queue *q) {
    int i;
    if(q->front > q->rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for(i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 6);
    enqueue(&q, 8);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    display(&q);

    enqueue(&q, 10);
    enqueue(&q, 12);
    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}