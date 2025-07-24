//FormAI DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

int front = -1; // to keep track of the front of the queue
int rear = -1; // to keep track of the rear of the queue
int queue[QUEUE_SIZE];

// function to insert elements into the queue
void enqueue(int data) {
    if (rear == QUEUE_SIZE - 1) { // if the queue is full
        printf("The queue is full!\n");
        return;
    }
    if (front == -1) front = 0; // if it's the first element being inserted
    rear++;
    queue[rear] = data; // adding element to the rear
    printf("%d has been successfully added to the queue!\n", data);
}

// function to remove elements from the queue
void dequeue() {
    if (front == -1 || front > rear) { // if the queue is empty
        printf("The queue is empty!\n");
        return;
    }
    front++;
    printf("Element removed from queue!\n");
}

// function to display the queue
void display() {
    if (front == -1 || front > rear) { // if the queue is empty
        printf("The queue is empty!\n");
        return;
    }
    printf("\n*****Queue*****\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

// the main function
int main() {
    int option, data;
    printf("Welcome to our cheerful queue implementation program!\n");
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choose an option (1/2/3/4): ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\nEnter the data you want to add to the queue:\n");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for using our cheerful queue implementation program! Have a nice day!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 4);

    return 0;
}