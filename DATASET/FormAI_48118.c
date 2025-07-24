//FormAI DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Element %d is inserted into the queue.\n", element);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot delete element.\n");
    } else {
        printf("Element %d is deleted from the queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements of the queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    delete();
    display();
    insert(40);
    insert(50);
    display();
    delete();
    delete();
    display();
    insert(60);
    insert(70);
    insert(80);
    display();
    insert(90);
    insert(100);
    insert(110);
    display();
    insert(120);
    insert(130);
    delete();
    delete();
    delete();
    display();
    delete();
    delete();
    delete();
    display();

    return 0;
}