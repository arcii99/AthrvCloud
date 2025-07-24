//FormAI DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int front = -1, rear = -1, queue[SIZE];

void enqueue(int value){
    if ((front == 0 && rear == SIZE-1) || front == rear+1){
        printf("\nQueue is full\n");
        return;
    }
    if (front == -1){
        front = 0;
        rear = 0;
    }
    else{
        if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;
    }
    queue[rear] = value;
}

int dequeue(){
    if (front == -1){
        printf("\nQueue is empty\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear){
        front = -1;
        rear = -1;
    }
    else{
        if (front == SIZE - 1)
            front = 0;
        else
            front++;
    }
    return value;
}


int main(){
    printf("Hello, I am a happy C Queue Implementation program! Let's get started!\n\n");

    // enqueuing values
    printf("Enqueuing values...\n");
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(30);
    enqueue(35);
    enqueue(40);
    enqueue(45);
    enqueue(50);

    // trying to enqueue again after queue is full, expecting error message
    printf("Trying to enqueue again after queue is full...\n");
    enqueue(55);

    // dequeuing values
    printf("Dequeuing values...\n");
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("\n");

    // trying to dequeue again after queue is empty, expecting error message
    printf("Trying to dequeue again after queue is empty...\n");
    dequeue();
    
    printf("\nYay! We made it to the end of the program without any errors! :D");
    return 0;
}