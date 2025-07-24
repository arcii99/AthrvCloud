//FormAI DATASET v1.0 Category: Queue ; Style: funny
#include <stdio.h>

#define QUEUE_SIZE 5

struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
};

struct Queue q;

void enqueue(int value) {
    if(q.rear == QUEUE_SIZE - 1){
        printf("Sorry, the Queue is already full\n");
    } else {
        printf("Adding %d to the Queue\n", value);
        q.items[++q.rear] = value;
    }
}

void dequeue() {
    if(q.front == q.rear){
        printf("Sorry, the Queue is already empty\n");
    } else {
        printf("Removing %d from the Queue\n", q.items[q.front]);
        q.front++;
    }
}

void display() {
    if(q.front == q.rear){
        printf("Sorry, the Queue is already empty\n");
    } else {
        printf("The current Queue is: ");
        for(int i = q.front; i <= q.rear; i++){
            printf("%d ", q.items[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hello! I am a Queue bot! Let's play with Queues\n");
    printf("I can handle only a Queue of size %d, let's see how you use me\n", QUEUE_SIZE);
    q.front = 0;
    q.rear = -1;

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    enqueue(6); // Ha! I am sorry, I am already full

    display();

    dequeue();
    dequeue();

    display();

    enqueue(6);
    enqueue(7);

    display();

    return 0;
}