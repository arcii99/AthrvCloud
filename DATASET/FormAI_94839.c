//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10 // The maximum size of our queue
#define ERR_VAL -999 // An error value to return when there is no element in the queue

// A struct representing our queue
typedef struct {
    int arr[MAX_SIZE]; // An array to store the elements of our queue
    int head; // The index pointing to the head of our queue
    int tail; // The index pointing to the tail of our queue
} queue;

// A function to initialize our queue
void init_queue(queue *q) {
    q->head = -1;
    q->tail = -1;
}

// A function to check if our queue is empty
int is_empty(queue *q) {
    if(q->head == -1 && q->tail == -1)
        return 1;
    else
        return 0;
}

// A function to check if our queue is full
int is_full(queue *q) {
    if((q->tail+1)%MAX_SIZE == q->head)
        return 1;
    else
        return 0;
}

// A function to enqueue an element into our queue
void enqueue(queue *q, int ele) {
    if(is_full(q)) {
        printf("Our wagon is full! We cannot add any more goods!\n");
        return;
    }
    else if(is_empty(q)) {
        q->head = q->tail = 0;
    }
    else {
        q->tail = (q->tail+1)%MAX_SIZE;
    }
    q->arr[q->tail] = ele;
    printf("Added %d to the wagon! Our goods have increased!\n", ele);
}

// A function to dequeue an element from our queue
int dequeue(queue *q) {
    int ele;
    if(is_empty(q)) {
        printf("Our wagon is empty! We have no goods to sell!\n");
        return ERR_VAL;
    }
    else if(q->head == q->tail) {
        ele = q->arr[q->head];
        q->head = q->tail = -1;
    }
    else {
        ele = q->arr[q->head];
        q->head = (q->head+1)%MAX_SIZE;
    }
    printf("Sold %d from the wagon! Our goods have decreased!\n", ele);
    return ele;
}

int main() {
    queue q;
    init_queue(&q);
    
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    dequeue(&q);
    
    return 0;
}