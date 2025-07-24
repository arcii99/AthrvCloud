//FormAI DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 //defining maximum size for queue

//Structure of the queue
typedef struct {
    int front; //Index for the front of the queue
    int rear; //Index for the rear of the queue
    int data[MAX_SIZE]; //Array used to store elements of the queue
} Queue;

//Function to check if the queue is empty
int isEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1) //Queue is empty
        return 1;
    else
        return 0;
}

//Function to add an element to the queue
void enqueue(Queue *q, int value) {
    if ((q->rear + 1) % MAX_SIZE == q->front) { //Queue is full
        printf("\nQueue is full!");
        return;
    } else if (isEmpty(q)) { //If queue is empty
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = value; //Add the element to the rear of the queue
}

//Function to remove an element from the queue
int dequeue(Queue *q) {
    int value;
    if (isEmpty(q)) { //If queue is empty
        printf("\nQueue is empty!");
        return -1;
    } else if (q->front == q->rear) { //Only one element in the queue
        value = q->data[q->front];
        q->front = q->rear = -1;
    } else {
        value = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

//Function to display the elements of the queue
void display(Queue *q) {
    int i;
    if (isEmpty(q)) { //If queue is empty
        printf("\nQueue is empty!");
        return;
    }
    printf("\nElements of queue are: ");
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("%d", q->data[i]);
}

//Main function
int main() {
    Queue q; //Create a queue
    q.front = q.rear = -1; //Initialize the queue to be empty

    //Enqueue some elements into the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q); //Display the elements of the queue

    //Dequeue some elements from the queue
    dequeue(&q);
    dequeue(&q);

    display(&q); //Display the elements of the queue after dequeue

    //Enqueue some more elements into the queue
    enqueue(&q, 60);
    enqueue(&q, 70);

    display(&q); //Display the elements of the queue

    return 0;
}