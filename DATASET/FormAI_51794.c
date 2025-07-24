//FormAI DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

// Defining a structure for the queue
struct queue{
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to check if the queue is full
int isFull(struct queue *q){
    if(q->rear == MAX_SIZE-1){
        printf("The queue is full!\n");
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty(struct queue *q){
    if(q->front == -1){
        printf("The queue is empty!\n");
        return 1;
    }
    else{
        return 0;
    }
}

// Function to insert an element into the queue
void enqueue(struct queue *q, int data){
    if(isFull(q)){
        printf("Cannot insert element into the queue!\n");
    }
    else{
        if(q->front == -1){
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
        printf("%d has been inserted into the queue.\n", data);
    }
}

// Function to remove an element from the queue
void dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Cannot remove element from the queue!\n");
    }
    else{
        printf("%d has been removed from the queue.\n", q->arr[q->front]);
        if(q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }
        else{
            q->front++;
        }
    }
}

// Function to view the first element of the queue
void peek(struct queue *q){
    if(isEmpty(q)){
        printf("Cannot view the first element of the queue!\n");
    }
    else{
        printf("The first element of the queue is %d.\n", q->arr[q->front]);
    }
}

// The main function
int main(){
    struct queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    peek(&q);
    dequeue(&q);
    peek(&q);
    enqueue(&q, 20);
    dequeue(&q);
    dequeue(&q);
    peek(&q);
    dequeue(&q);
    isEmpty(&q);
    return 0;
}