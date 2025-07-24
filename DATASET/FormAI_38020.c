//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

//structure for queue
struct queue { 
    int items[SIZE];
    int front;
    int rear;
};

//function to create a queue
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//function to check if queue is full
bool isFull(struct queue* q) {
    if (q->rear == SIZE - 1) {
        return true;
    }
    else {
        return false;
    }
}

//function to check if queue is empty
bool isEmpty(struct queue* q) {
    if (q->front == -1 && q->rear == -1) {
        return true;
    }
    else {
        return false;
    }
}

//function to add elements to queue
void enqueue(struct queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
        printf("Enqueued %d\n", val);
    }
}

//function to remove elements from queue
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

//function to print elements of queue
void printQueue(struct queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue contains: ");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

//main function
int main() {
    struct queue* myQueue = createQueue();
    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);
    printQueue(myQueue);
    dequeue(myQueue);
    printQueue(myQueue);
    enqueue(myQueue, 4);
    printQueue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    printQueue(myQueue);
    dequeue(myQueue);
    return 0;
}