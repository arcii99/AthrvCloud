//FormAI DATASET v1.0 Category: Queue ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

// Queue Data Structure
typedef struct Queue Queue;

struct Queue{
    int data[MAX_SIZE];
    int head;
    int tail;
};

// Function prototypes
void init(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
int enqueue(Queue* q, int x);
int dequeue(Queue* q);

void init(Queue* q){
    q->head = 0;
    q->tail = -1;
}

int isEmpty(Queue* q){
    return q->head > q->tail;
}

int isFull(Queue* q){
    return q->tail == MAX_SIZE-1;
}

int enqueue(Queue* q, int x){
    if(isFull(q)){
        printf("Error: Queue is full\n");
        return -1;
    }
    q->tail++;
    q->data[q->tail] = x;
    return 0;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Error: Queue is empty\n");
        return -1;
    }
    int x = q->data[q->head];
    q->head++;
    return x;
}

int main(){
    Queue q;
    init(&q);
    printf("Queue is empty: %d\n", isEmpty(&q));
    printf("Queue is full: %d\n", isFull(&q));
    printf("enqueue element 5: %d\n", enqueue(&q, 5));
    printf("enqueue element 10: %d\n", enqueue(&q, 10));
    printf("enqueue element 15: %d\n", enqueue(&q, 15));
    printf("dequeue element: %d\n", dequeue(&q));
    printf("dequeue element: %d\n", dequeue(&q));
    printf("Queue is empty: %d\n", isEmpty(&q));
    printf("enqueue element 20: %d\n", enqueue(&q, 20));
    printf("dequeue element: %d\n", dequeue(&q));
    printf("Queue is empty: %d\n", isEmpty(&q));

    return 0;
}