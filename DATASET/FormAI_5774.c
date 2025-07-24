//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CAPACITY 100 // maximum capacity of the queue

// Declare global variables
int front = -1, rear = -1;
char queue[MAX_CAPACITY][50]; // queue to hold the baggage
int runway[MAX_CAPACITY]; // array to hold runway numbers of the baggage

// Function to check if the queue is full
int isFull() {
    if(rear == MAX_CAPACITY-1) {
        return 1; // full
    } else {
        return 0; // not full
    }
}

// Function to check if the queue is empty
int isEmpty() {
    if(front == -1 || front > rear) {
        return 1; // empty
    } else {
        return 0; // not empty
    }
}

// Function to add a baggage to the queue
void enqueue(char baggage[], int runway_number) {
    if(isFull()) {
        printf("The queue is full. Cannot add any more baggage.\n");
    } else {
        if(front == -1) {
            front = 0;
        }
        rear++;
        strcpy(queue[rear], baggage);
        runway[rear] = runway_number;
        printf("Baggage with tag number %s is added to the queue for runway %d.\n", baggage, runway_number);
    }
}

// Function to remove a baggage from the queue
void dequeue() {
    if(isEmpty()) {
        printf("The queue is empty. No baggage to remove.\n");
    } else {
        printf("Baggage with tag number %s and runway number %d is removed from the queue.\n", queue[front], runway[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    if(isEmpty()) {
        printf("The queue is empty.\n");
    } else {
        printf("The baggage in the queue are:\n");
        for(int i = front; i <= rear; i++) {
            printf("Tag number: %s, Runway: %d.\n", queue[i], runway[i]);
        }
    }
}

// Function to simulate the baggage handling process
void simulate() {
    int runway1_count = 0, runway2_count = 0, runway3_count = 0;
    int flag_runway1 = 0, flag_runway2 = 0, flag_runway3 = 0;
    
    while(!isEmpty()) {
        if(runway[front] == 1) {
            if(!flag_runway1) {
                printf("======= Begin Baggage Handling for Runway 1 =======\n");
                flag_runway1 = 1;
            }
            printf("Handling baggage with tag number %s on Runway 1.\n", queue[front]);
            runway1_count++;
        } else if(runway[front] == 2) {
            if(!flag_runway2) {
                printf("======= Begin Baggage Handling for Runway 2 =======\n");
                flag_runway2 = 1;
            }
            printf("Handling baggage with tag number %s on Runway 2.\n", queue[front]);
            runway2_count++;
        } else if(runway[front] == 3) {
            if(!flag_runway3) {
                printf("======= Begin Baggage Handling for Runway 3 =======\n");
                flag_runway3 = 1;
            }
            printf("Handling baggage with tag number %s on Runway 3.\n", queue[front]);
            runway3_count++;
        } else {
            printf("Invalid runway number %d.\n", runway[front]);
        }
        dequeue();
    }
    
    printf("======= End Baggage Handling =======\n");
    printf("Total Baggage handled on Runway 1: %d\n", runway1_count);
    printf("Total Baggage handled on Runway 2: %d\n", runway2_count);
    printf("Total Baggage handled on Runway 3: %d\n", runway3_count);
}

int main() {
    // Add some test data
    enqueue("1234", 1);
    enqueue("2345", 2);
    enqueue("3456", 3);
    enqueue("4567", 2);
    enqueue("5678", 1);
    display();
    
    // Simulate the baggage handling
    simulate();
    
    return 0;
}