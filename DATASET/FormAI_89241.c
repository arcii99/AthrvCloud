//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include <stdio.h>
#define MAX_QUEUE_SIZE 100

int front = 0;
int rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int value) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full! Cannot enqueue any more values.\n");
    }
    else {
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (front > rear) {
        printf("Queue is empty! Cannot dequeue any more values.\n");
        return -1; // sentinel value to indicate error
    }
    else {
        int value = queue[front];
        front++;
        return value;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Dequeued value: %d\n", dequeue()); // should print 10
    printf("Dequeued value: %d\n", dequeue()); // should print 20
    printf("Dequeued value: %d\n", dequeue()); // should print 30
    printf("Dequeued value: %d\n", dequeue()); // should print "Queue is empty!"
    return 0;
}