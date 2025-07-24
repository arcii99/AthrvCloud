//FormAI DATASET v1.0 Category: Queue ; Style: happy
#include <stdio.h>
#define SIZE 5 //Specify queue size

int queue[SIZE], front = -1, rear = -1; //Initialize queue variables

void enqueue(int value) { //Enqueue function
    if (rear == SIZE - 1) { //Check if queue is full
        printf("Sorry, queue is full!\n"); //Display error message
    } else {
        if (front == -1) { //If queue is empty
            front = 0; //Set front to 0
        }
        rear++; //Increment rear
        queue[rear] = value; //Assign value to rear position
        printf("%d has been added to the queue!\n", value); //Display success message
    }
}

void dequeue() { //Dequeue function
    if (front == -1) { //Check if queue is empty
        printf("Sorry, queue is empty!\n"); //Display error message
    } else {
        printf("%d has been dequeued from the queue!\n", queue[front]); //Display dequeued value
        front++; //Increment front
        if (front > rear) { //If queue is empty
            front = rear = -1; //Reset front and rear
        }
    }
}

void display() { //Display function
    if (front == -1) { //Check if queue is empty
        printf("Sorry, queue is empty!\n"); //Display error message
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) { //Loop through queue elements
            printf("%d ", queue[i]); //Display current element
        }
        printf("\n"); //Display newline character
    }
}

int main() { //Main function
    printf("Welcome to the happy queue program!\n"); //Display welcoming message
    printf("Here, we are going to make a queue that will make you all happy!\n");

    //Enqueue values
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display(); //Display queue elements

    //Dequeue values
    dequeue();
    dequeue();

    display(); //Display queue elements

    //Enqueue values
    enqueue(60);
    enqueue(70);

    display(); //Display queue elements

    return 0; //End program
}