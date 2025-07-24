//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Declare variables */
int queue[10], front, rear, size;

/* Function to check if the queue is full */
int isFull(){
    return rear == 9;
}

/* Function to check if the queue is empty */
int isEmpty(){
    return front == -1;
}

/* Function to add an element to the queue */
void enqueue(int element){
    if(isFull()){
        printf("Queue is full.\n\n");
    }else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("%d added to the queue.\n\n", element);
        size++;
    }
}

/* Function to remove an element from the queue */
void dequeue(){
    if(isEmpty()){
        printf("Queue is empty.\n\n");
    }else{
        int element = queue[front];
        if(front >= rear){
            front = -1;
            rear = -1;
        }else{
            front++;
        }
        printf("%d removed from the queue.\n\n", element);
        size--;
    }
}

/* Function to display the elements in the queue */
void display(){
    if(isEmpty()){
        printf("Queue is empty.\n\n");
    }else{
        printf("Elements in the queue: ");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n\n");
    }
}

int main(){

    /* Initialize variables */
    front = -1;
    rear = -1;
    size = 0;

    printf("=============================\n");
    printf("Welcome to the Surreal Queue\n");
    printf("=============================\n\n");

    printf("Let's add some random elements to the queue...\n");
    srand(time(NULL));
    for(int i=0; i<5; i++){
        int random = rand() % 100;
        printf("Adding %d to the queue...\n", random);
        enqueue(random);
    }

    printf("The queue so far is:\n");
    display();

    printf("Now let's remove the first %d elements from the queue...\n", size/2);
    for(int i=0; i<size/2; i++){
        dequeue();
    }

    printf("The queue now is:\n");
    display();

    printf("Let's add some more random elements to the queue...\n");
    srand(time(NULL));
    for(int i=0; i<5; i++){
        int random = rand() % 100;
        printf("Adding %d to the queue...\n", random);
        enqueue(random);
    }

    printf("The final queue is:\n");
    display();

    printf("Thank you for experiencing the Surreal Queue!\n");

    return 0;
}