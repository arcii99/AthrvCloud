//FormAI DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>

#define MAX_SIZE 10 // maximum size of the queue

int queue[MAX_SIZE]; // declaration of the queue
int front = -1;
int rear = -1;
int num_elements = 0; // number of elements in the queue

void enqueue(int value) {
    if (num_elements == MAX_SIZE) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        rear %= MAX_SIZE;
        queue[rear] = value;
        num_elements++;
    }
}

int dequeue() {
    if (num_elements == 0) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int value = queue[front];
        front++;
        front %= MAX_SIZE;
        num_elements--;
        if (num_elements == 0) {
            front = -1;
            rear = -1;
        }
        return value;
    }
}

int main() {
    // example usage of the queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("%d ", dequeue()); // 1
    printf("%d ", dequeue()); // 2
    printf("%d ", dequeue()); // 3
    printf("%d ", dequeue()); // Queue is empty, -1
    return 0;
}