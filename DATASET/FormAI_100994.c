//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGS 100
#define MAX_LOOPS 10

// function to generate a random number between 0 and max
int getRandomNumber(int max) {
    return rand() % (max + 1);
}

int main() {
    // initialize queue
    int queue[MAX_BAGS];
    int front = -1;
    int rear = -1;
    
    // initialize random number generator
    srand(time(NULL));
    
    // loop through a number of iterations
    int i;
    for(i = 0; i < MAX_LOOPS; i++) {
        // generate random number of bags to add to queue
        int numBags = getRandomNumber(10);
        int j;
        for(j = 0; j < numBags; j++) {
            // check if queue is full
            if(rear == MAX_BAGS-1) {
                printf("Queue is full!\n");
                break;
            }
            else if(front == -1 && rear == -1) {
                front ++;
                rear ++;
                // add bag to queue
                queue[rear] = j+1;
            }
            else {
                rear ++;
                // add bag to queue
                queue[rear] = j+1;
            }
        }
        
        // remove bags from queue
        int k;
        for(k = 0; k < numBags; k++) {
            // check if queue is empty
            if(front == -1) {
                printf("Queue is empty!\n");
                break;
            }
            else {
                // remove bag from queue
                int bag = queue[front];
                front ++;
                printf("Bag %d has been removed from the queue.\n", bag);
            }
        }
    }
    
    return 0;
}