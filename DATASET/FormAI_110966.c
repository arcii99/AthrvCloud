//FormAI DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10         // Maximum size of the queue

int queue[MAX_SIZE];        // Queue array declaration
int front = -1, rear = -1;  // Initializing the front and rear pointers

// Function to check if the queue is empty
int is_empty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int is_full() {
    if (rear == MAX_SIZE-1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to insert an element into the queue
void enqueue(int data) {
    if (is_full()) {
        printf("Cannot insert element, queue is full.\n");
    } else {
        if (is_empty()) {
            front = rear = 0;   // Initializing front and rear pointers to 0
        } else {
            rear++;             // Incrementing rear pointer
        }
        queue[rear] = data;     // Inserting the element into the queue
        printf("Inserted element: %d\n", data);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (is_empty()) {
        printf("Cannot remove element, queue is empty.\n");
    } else if (front == rear) {
        front = rear = -1;      // Resetting front and rear pointers
    } else {
        front++;                // Incrementing front pointer
    }
}

// Function to display the contents of the queue
void display() {
    if (is_empty()) {
        printf("Cannot display elements, queue is empty.\n");
    } else {
        printf("Elements in the queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data you want to insert: ");
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
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}