//FormAI DATASET v1.0 Category: Queue ; Style: active
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

/* defining the structure of the queue */
struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

/* initialize the queue */
void init_queue(struct queue * q){
    q -> front = -1;
    q -> rear = -1;
}

/* check if the queue is full */
int check_full(struct queue * q){
    if(q -> rear == MAX_SIZE - 1)
        return 1;
    return 0;
}

/* check if the queue is empty */
int check_empty(struct queue * q){
    if(q -> front == -1 && q -> rear == -1)
        return 1;
    return 0;
}

/* insert an item into the queue */
void enqueue(struct queue * q, int item){
    if(check_full(q)){
        printf("Queue overflow!\n");
        return;
    }
    if(check_empty(q)){
        q -> front = q -> rear = 0;
        q -> items[0] = item;
    } else {
        q -> rear++;
        q -> items[q -> rear] = item;
    }
    printf("Enqueued item: %d\n", item);
}

/* remove an item from the queue */
void dequeue(struct queue * q){
    if(check_empty(q)){
        printf("Queue underflow!\n");
        return;
    }
    int item = q -> items[q -> front];
    if(q -> front == q -> rear){
        q -> front = q -> rear = -1;
    } else {
        q -> front++;
    }
    printf("Dequeued item: %d\n", item);
}

int main(){
    struct queue q;
    init_queue(&q);
    
    enqueue(&q, 10);    // adding items to the queue
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q);        // removing an item from the queue
    enqueue(&q, 40);
    dequeue(&q);
    enqueue(&q, 50);
    
    return 0;
}