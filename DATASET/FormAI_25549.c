//FormAI DATASET v1.0 Category: Data structures visualization ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#define size 10 // macro for size of array 

struct stack{
    int arr[size];
    int top;
};

struct queue{
    int arr[size];
    int front, rear;
};

// Function to initialize the stack
void initializeStack(struct stack *s){
    s->top = -1;
}

// Function to check if the stack is empty
int isStackEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the stack is full
int isStackFull(struct stack *s){
    if(s->top == size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to push an element onto the stack
void push(struct stack *s, int value){
    if(isStackFull(s)){
        printf("Stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct stack *s){
    int value;
    if(isStackEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        value = s->arr[s->top];
        s->top--;
        return value;
    }
}

// Function to initialize the queue
void initializeQueue(struct queue *q){
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(struct queue *q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the queue is full
int isQueueFull(struct queue *q){
    if(q->rear == size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(struct queue *q, int value){
    if(isQueueFull(q)){
        printf("Queue overflow\n");
    }
    else{
        if(q->front == -1){
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue *q){
    int value;
    if(isQueueEmpty(q)){
        printf("Queue underflow\n");
        return -1;
    }
    else{
        value = q->arr[q->front];
        if(q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }
        else{
            q->front++;
        }
        return value;
    }
}

//Function to display the contents of Stack and Queue simultaneously
void displayBoth(struct stack s, struct queue q){
    printf("\n----STACK----\n");
    if(isStackEmpty(&s)){
        printf("EMPTY\n");
    }
    else{
        for(int i=s.top;i>=0;i--){
            printf("%d\n",s.arr[i]);
        }
    }

    printf("\n----QUEUE----\n");
    if(isQueueEmpty(&q)){
        printf("EMPTY\n");
    }
    else{
        for(int i=q.front;i<=q.rear;i++){
            printf("%d\n",q.arr[i]);
        }
    }

}

int main(){
    // Initialize Stack and Queue
    struct stack s;
    struct queue q;
    initializeStack(&s);
    initializeQueue(&q);

    // Populate Stack and Queue
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    enqueue(&q, 400);
    enqueue(&q, 500);

    // Print Stack and Queue
    displayBoth(s,q);

    // Pop from Stack and Dequeue from Queue
    printf("\nPopped value from stack: %d\n",pop(&s));
    printf("Dequeued value from queue: %d\n",dequeue(&q));

    // Print Stack and Queue
    displayBoth(s,q);

    return 0;
}