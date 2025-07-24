//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10

//Structure for Queue
typedef struct {
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue;

//Function prototypes
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void print(Queue *q);

int main(){
    Queue q;   //Creating a Queue
    q.front = -1;  //Initializing the front to -1
    q.rear = -1;   //Initializing the rear to -1

    enqueue(&q, 5);    //Enqueue data
    enqueue(&q, 10);   //Enqueue data
    enqueue(&q, 15);   //Enqueue data
    enqueue(&q, 20);   //Enqueue data
    printf("Elements in Queue: ");
    print(&q);         //Print queue elements

    dequeue(&q);        //Dequeue data
    dequeue(&q);        //Dequeue data
    printf("Elements in Queue: ");
    print(&q);          //Print queue elements
}

//Enqueue Function - adds data to the queue
void enqueue(Queue *q, int data){
    if(q->rear >= MAX_QUEUE_SIZE-1){      //Check if queue is full
        printf("Queue Overflow\n");
        return;
    }
    else{                           //If queue is not full
        if(q->front == -1){         //Check if queue is empty
            q->front++;
        }
        q->rear++;              //Move rear pointer
        q->arr[q->rear] = data;  
    }
}

//Dequeue Function - removes data from the queue
int dequeue(Queue *q){
    int temp;
    if(q->front == -1 && q->rear == -1){     //Check if queue is empty
        printf("Queue Underflow\n");
        return -1;
    }
    else{                             //If queue is not empty
        temp = q->arr[q->front];
        q->front++;                  //Move front pointer
        if(q->front > q->rear){      //If queue becomes empty
            q->front = q->rear = -1;
        }
    }
    return temp;
}

//Print Function - prints the elements in the queue
void print(Queue *q){
    if(q->front == -1 && q->rear == -1){    //Check if queue is empty
        printf("Empty Queue\n");
        return;
    }
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}