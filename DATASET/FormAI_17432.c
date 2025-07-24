//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = 0, rear = -1;  // Pointer vars to keep track of the front and rear of the queue

void enqueue(int data) {
    // Check if queue is full
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    queue[++rear] = data;
    printf("%d enqueued to the queue!\n", data);
}

int dequeue() {
    // Check if queue is empty
    if (front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    // Check if queue is empty
    if (front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("Surprised to see a unique implementation of queue in C language? Let's try it out!\n\n");
    printf("Enqueuing elements...\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("\n");

    printf("Dequeueing elements...\n");
    printf("%d dequeued from the queue!\n", dequeue());
    printf("%d dequeued from the queue!\n", dequeue());
    printf("\n");

    printf("Enqueuing elements...\n");
    enqueue(40);
    enqueue(50);
    printf("\n");

    printf("Displaying elements...\n");
    display();
    printf("\n");

    printf("Enqueuing elements...\n");
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);

    printf("Trying to enqueue more elements...\n");
    enqueue(110);
    enqueue(120);
    printf("\n");

    printf("Displaying elements...\n");
    display();
    printf("\n");

    printf("Dequeueing elements again...\n");
    printf("%d dequeued from the queue!\n", dequeue());
    printf("%d dequeued from the queue!\n", dequeue());
    printf("%d dequeued from the queue!\n", dequeue());
    printf("\n");

    printf("Displaying elements again...\n");
    display();
    printf("\n");

    printf("Let's try to dequeue from an empty queue...\n");
    dequeue();
    printf("\n");

    printf("Thank you for trying out my unique implementation of queue!\n");
    return 0;
}