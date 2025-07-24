//FormAI DATASET v1.0 Category: Queue ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

// struct definition for queue
struct Queue{
    int items[MAX_SIZE];
    int front;
    int rear;
};

// function to check if the queue is empty
int is_empty(struct Queue* q){
    if(q->rear == -1) return 1;
    return 0;
}

// function to check if the queue is full
int is_full(struct Queue* q){
    if(q->rear == MAX_SIZE-1) return 1;
    return 0;
}

// function to add an element to the queue
void enqueue(struct Queue* q, int value){
    if(is_full(q)){
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// function to remove an element from the queue
int dequeue(struct Queue* q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if(q->front > q->rear){
        q->front = q->rear = -1;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// function to display the elements of the queue
void display(struct Queue* q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// main function to test the queue data structure and functions
int main(){
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    // test enqueue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    // test dequeue
    dequeue(&q);

    // test display
    display(&q);

    return 0;
}