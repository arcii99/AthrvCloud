//FormAI DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include<stdlib.h>
#include<stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE], front=-1, rear=-1;

void enqueue(int item){
    if ((front == 0 && rear == MAX_SIZE-1) || (front == rear+1)){
        printf("Queue is full\n");
        return;
    }
    else if (front == -1 && rear == -1){
        front = rear = 0;
    }
    else if (rear == MAX_SIZE-1 && front != 0){
        rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = item;
}

void dequeue(){
    if (front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if (front == rear){
        front = rear = -1;
    }
    else if (front == MAX_SIZE-1){
        front = 0;
    }
    else{
        front++;
    }
}

void display(){
    int i;
    if (front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }
    if (rear >= front){
        for (i=front; i<=rear; i++)
            printf("%d ",queue[i]);
    }
    else{
        for (i=front; i<MAX_SIZE; i++)
            printf("%d ", queue[i]);
        for (i=0; i<=rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int choice, item;
    printf("\nWelcome to the post-apocalyptic C Queue Program!\n");
    while (1){
        printf("\nSelect an operation:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}