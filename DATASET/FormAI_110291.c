//FormAI DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#define MAX_LENGTH 10

int front = -1, rear = -1;
int queue[MAX_LENGTH];

// function to check if the queue is empty
int is_empty(){
    if (front == -1 && rear == -1){
        return 1;
    }
    else {
        return 0;
    }
}

// function to check if the queue is full
int is_full(){
    if (rear == MAX_LENGTH - 1){
        return 1;
    }
    else {
        return 0;
    }
}

// function to add an element to the queue
void enqueue(int x){
    if (is_full()){
        printf("The queue is full!\n");
    }
    else if (is_empty()){
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear++;
        queue[rear] = x;
    }
}

// function to remove an element from the queue
void dequeue(){
    if (is_empty()){
        printf("The queue is empty!\n");
    }
    else if (front == rear){
        front = rear = -1;
    }
    else {
        front++;
    }
}

// function to print the queue
void print_queue(){
    if (is_empty()){
        printf("The queue is empty!\n");
    }
    else {
        printf("The queue is: ");
        for (int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    print_queue();
    dequeue();
    print_queue();
    enqueue(40);
    print_queue();
    return 0;
}