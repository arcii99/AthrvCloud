//FormAI DATASET v1.0 Category: Queue ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of customers allowed in the queue
#define MAX_CUSTOMERS 10

// Define the customer struct
typedef struct {
    int id;
    char name[20];
    char ticket_type[20];
} Customer;

// Define the queue struct
typedef struct {
    Customer customers[MAX_CUSTOMERS];
    int front;
    int rear;
    int size;
} Queue;

// Function to check if the queue is empty
bool is_empty(Queue* q) {
    return (q->size == 0);
}

// Function to check if the queue is full
bool is_full(Queue* q) {
    return (q->size == MAX_CUSTOMERS);
}

// Function to add a customer to the queue
void enqueue(Queue* q, Customer customer) {
    if (!is_full(q)) {
        q->rear = (q->rear + 1) % MAX_CUSTOMERS;
        q->customers[q->rear] = customer;
        q->size++;
        printf("%s has joined the queue!\n", customer.name);
    } else {
        printf("Error: Queue is full. Please try again later.\n");
    }
}

// Function to remove a customer from the queue
void dequeue(Queue* q) {
    if (!is_empty(q)) {
        q->front = (q->front + 1) % MAX_CUSTOMERS;
        q->size--;
        printf("%s has received their ticket and left the queue!\n", q->customers[q->front].name);
    } else {
        printf("Error: Queue is empty. No customers to dequeue.\n");
    }
}

// Function to display all customers in the queue
void display_queue(Queue* q) {
    if (!is_empty(q)) {
        printf("Customers in the queue:\n");
        int i;
        for (i = 0; i < q->size; i++) {
            printf("%d. %s (%s)\n", i+1, q->customers[(q->front+i)%MAX_CUSTOMERS].name, q->customers[(q->front+i)%MAX_CUSTOMERS].ticket_type);
        }
    } else {
        printf("Queue is empty. No customers to display.\n");
    }
}

int main() {
    // Initialize the queue
    Queue q = { {}, 0, -1, 0 };
    
    // Add customers to the queue
    Customer c1 = { 1, "Alice", "VIP" };
    Customer c2 = { 2, "Bob", "General" };
    Customer c3 = { 3, "Charlie", "Child" };
    Customer c4 = { 4, "David", "General" };
    Customer c5 = { 5, "Eve", "Child" };
    enqueue(&q, c1);
    enqueue(&q, c2);
    enqueue(&q, c3);
    enqueue(&q, c4);
    enqueue(&q, c5);
    
    // Display the queue
    display_queue(&q);
    
    // Remove customers from the queue
    dequeue(&q);
    dequeue(&q);
    
    // Display the queue again
    display_queue(&q);
    
    return 0;
}