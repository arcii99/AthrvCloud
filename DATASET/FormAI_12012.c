//FormAI DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h> 

#define MAX_SIZE 10 

int front = -1, rear = -1;
int queue[MAX_SIZE];

// This function checks if the queue is full or not
int isFull() {  
    if(front == 0 && rear == MAX_SIZE - 1) return 1;
    if(front == rear + 1) return 1;
    return 0;
}

// This function checks if the queue is empty or not
int isEmpty() {
    if(front == -1) return 1;
    return 0;
}

// This function adds an element to the queue
void enqueue(int element) {
    if(isFull()) {
        printf("\nQueue is full!\n");
    } else {
        if(front == -1) front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        printf("\nEnqueued element: %d\n", element);
    }
}

// This function removes an element from the queue
void dequeue() {
    if(isEmpty()) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nDequeued element: %d\n", queue[front]);
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

// This function prints the elements in the queue
void printQueue() {
    if(isEmpty()) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nElements in the queue are:\n");
        int i;
        for(i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
    }
}

int main() {

    // Add some elements to the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    // Print the elements in the queue
    printQueue();
    
    // Remove an element from the queue
    dequeue();
    
    // Print the elements in the queue again
    printQueue();
    
    // Add one more element to the queue
    enqueue(40);

    // Print the elements in the queue again
    printQueue();

    return 0;
}