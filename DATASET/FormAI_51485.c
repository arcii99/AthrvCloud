//FormAI DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include <stdio.h>
#define SIZE 10
 
int queue[SIZE], front = -1, rear = -1;
 
void enqueue(int data) {
    if (rear == SIZE - 1) {
        printf("The Queue is full!\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("Data added to the Queue: %d\n", data);
    }
}
 
void dequeue() {
    if (front == -1) {
        printf("The Queue is empty!\n");
    }
    else {
        printf("Data removed from the Queue: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}
 
void display() {
    if (front == -1) {
        printf("The Queue is empty!\n");
    }
    else {
        int i;
        printf("The Queue is:");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
 
int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    dequeue();
    display();
    enqueue(20);
    display();
    return 0;
}