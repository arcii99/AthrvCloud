//FormAI DATASET v1.0 Category: Queue ; Style: bold
// Welcome to this unique C Queue example program!
#include <stdio.h>

#define SIZE 5 // Define the maximum size of the Queue array

int queue_array[SIZE]; // Integer array to store the Queue elements
int rear = -1; // Initialize rear of the Queue to -1
int front = -1; // Initialize front of the Queue to -1

// Function to check if Queue is empty
int is_empty() {
    if (front == -1 || front == rear + 1) {
        return 1; // True, the Queue is empty
    } else {
        return 0; // False, the Queue is not empty
    }
}

// Function to check if Queue is full
int is_full() {
    if (rear == SIZE - 1) {
        return 1; // True, the Queue is full
    } else {
        return 0; // False, the Queue is not full
    }
}

// Function to add an element to the rear of the Queue
void enqueue(int value) {
    if (is_full()) {
        printf("The Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue_array[rear] = value;
        printf("Inserted %d into the Queue\n", value);
    }
}

// Function to remove an element from the front of the Queue
void dequeue() {
    if (is_empty()) {
        printf("The Queue is empty!\n");
    } else {
        printf("Removed %d from the Queue\n", queue_array[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Function to display the Queue elements
void display() {
    if (is_empty()) {
        printf("The Queue is empty!\n");
    } else {
        int i;
        printf("The Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}

int main() {
    // Welcome message
    printf("Welcome to the C Queue example program!\n");

    // Add elements to the Queue
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Display the Queue elements
    display();

    // Remove an element from the Queue
    dequeue();

    // Display the Queue elements
    display();

    // Add elements to the Queue
    enqueue(40);
    enqueue(50);
    enqueue(60);

    // Display the Queue elements
    display();

    // Remove elements from the Queue
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    // Display the Queue elements
    display();

    // Goodbye message
    printf("Thank you for using the C Queue example program!\n");

    return 0;
}