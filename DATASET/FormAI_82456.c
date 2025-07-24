//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;

void insert() {
    int item;
    printf("\n\tEnter the element to insert: ");
    scanf("%d", &item);

    if (rear == MAX - 1) {
        printf("\n\tSorry, Queue is full!\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = item;
        printf("\n\tElement %d inserted to queue successfully.\n", item);
    }
    else {
        rear++;
        queue[rear] = item;
        printf("\n\tElement %d inserted to queue successfully.\n", item);
    }
}

void delete() {
    if (front == -1 && rear == -1) {
        printf("\n\tSorry, Queue is empty.\n");
    }
    else if (front == rear) {
        printf("\n\tElement %d deleted from queue successfully.\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("\n\tElement %d deleted from queue successfully.\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("\n\tSorry, Queue is empty.\n");
    }
    else {
        printf("\n\tQueue elements:\n");
        for (i = front; i <= rear; i++) {
            printf("\t\t%d\n", queue[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n\t-------- C Queue Implementation --------\n");
        printf("\t\t1. Insert\n");
        printf("\t\t2. Delete\n");
        printf("\t\t3. Display\n");
        printf("\t\t4. Exit\n");
        printf("\t-----------------------------------------\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tExiting the program... Goodbye!\n");
                exit(0);
                break;
            default:
                printf("\n\tInvalid input. Please input the correct option.\n");
        }
    }
    return 0;
}