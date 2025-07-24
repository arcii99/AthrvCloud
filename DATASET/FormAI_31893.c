//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include<stdio.h>

#define MAX_SIZE 5 //maximum size of the queue

int queue[MAX_SIZE]; //declaring queue array
int front = -1, rear = -1; //initially queue is empty

//function to check if queue is full
int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1) {
        return 1;
    }
    return 0;
}

//function to check if queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

//function to add element to the queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full! Cannot add more elements\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        printf("Element %d has been added to the queue\n", element);
    }   
}

//function to remove element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot remove any element\n");
    }
    else {
        int removed_element = queue[front];
        printf("Element %d has been removed from the queue\n", removed_element);
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

//function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    }
    else {
        int i;
        printf("The elements of the queue are: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, element;
    printf("C Queue Implementation using Array\n");
    do {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element you want to add to the queue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}