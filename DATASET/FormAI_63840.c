//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 5 //maximum size of queue

int front = -1, rear = -1;
int queue[MAX_QUEUE_SIZE];

//function to check if the queue is empty
bool is_empty() {
    if (front == -1 && rear == -1) {
        return true;
    }
    else return false;
}

//function to check if the queue is full
bool is_full() {
    if ((rear+1)%MAX_QUEUE_SIZE == front) {
        return true;
    }
    else return false;
}

//function to insert an element into the queue
void enqueue(int val) {
    if (is_full()) {
        printf("Queue is full\n");
    }
    else if (is_empty()) {
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else {
        rear = (rear+1)%MAX_QUEUE_SIZE;
        queue[rear] = val;
    }
}

//function to remove an element from the queue
void dequeue() {
    if (is_empty()) {
        printf("Queue is empty\n");
    }
    else if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front+1)%MAX_QUEUE_SIZE;
    }
}

//function to display the elements of the queue
void display() {
    if (is_empty()) {
        printf("Queue is empty\n");
    }
    else {
        int i;
        for (i=front; i<=rear; i=(i+1)%MAX_QUEUE_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("Queue: ");
    display(); // 1 2 3 4 5
    enqueue(6); //Queue is full
    dequeue();
    dequeue();
    printf("Queue: ");
    display(); //3 4 5
    enqueue(6);
    printf("Queue: ");
    display(); //3 4 5 6
    return 0;
}