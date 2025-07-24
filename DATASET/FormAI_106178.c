//FormAI DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include<stdio.h>
#define MAX 5 //maximum size of queue

int queue[MAX]; //array for queue
int front = -1, rear = -1; //variable to keep track of front and rear of queue

//function to add an element to queue
void enqueue(int num) {
    if(rear == MAX-1){ //if Queue is full
        printf("\nQueue is full!\n");
    }
    else {
        if(front == -1){ //if first element being added
            front = 0;
        }
        rear++;
        queue[rear] = num;
    }
}

//function to remove an element from queue
void dequeue() {
    if(front == -1 || front > rear){ //if Queue is empty
        printf("\nQueue is empty!\n");
    }
    else{
        printf("\nElement %d dequeued from Queue\n", queue[front]);
        front++;
    }
}

//function to display the elements in queue
void display() {
    if(front == -1){ //if Queue is empty
        printf("\nQueue is empty!\n");
    }
    else{
        printf("\nQueue elements are:\n");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    //displaying the current status of Queue
    display();
    
    //adding elements to Queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); //Queue is full now
    
    //displaying the queue
    display();
    
    //removing element from Queue
    dequeue();
    dequeue();
    
    //displaying the queue
    display();
    
    //removing all elements from Queue
    dequeue();
    dequeue();
    dequeue();
    dequeue(); //Queue is empty now
    
    //displaying the queue
    display();
    
    return 0;
}