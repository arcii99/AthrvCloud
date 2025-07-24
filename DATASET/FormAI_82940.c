//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20 // The size of the grid
#define PERCENTAGE 60 // The percentage of cells that will be filled initially

int grid[SIZE][SIZE]; // The grid

// Queue implementation
#define QUEUE_SIZE (SIZE * SIZE)
int queue[QUEUE_SIZE];
int front = -1, rear = -1;
void enqueue(int val){
    if(rear == QUEUE_SIZE - 1){
        printf("Queue Overflow\n");
        exit(1);
    }
    else{
        if(front == -1) front = 0;
        rear++;
        queue[rear] = val;
    }
}
int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        exit(1);
    }
    else{
        int val = queue[front];
        front++;
        return val;
    }
}

// Function to check if a cell is within the grid
bool isValid(int i, int j){
    return (i >= 0 && i < SIZE && j >= 0 && j < SIZE);
}

// Function to check if a cell is full
bool isFull(int i, int j){
    return (grid[i][j] == 1);
}

// Function to fill a cell
void fillCell(int i, int j){
    grid[i][j] = 1;
}

// Function to display the grid
void displayGrid(){
    printf("\n-------------------\n");
    for(int i = 0; i < SIZE; i++){
        printf("|");
        for(int j = 0; j < SIZE; j++){
            if(grid[i][j] == 1){
                printf("X");
            }
            else{
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("-------------------\n");
}

// Function to simulate percolation
void percolate(){
    // Fill a percentage of the cells randomly
    int cellsToFill = PERCENTAGE * SIZE * SIZE / 100;
    int cellsFilled = 0;
    srand(time(NULL)); // Seed the random number generator
    while(cellsFilled < cellsToFill){
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if(!isFull(i, j)){
            fillCell(i, j);
            cellsFilled++;
        }
    }

    // Add all cells in the top row to the queue
    for(int j = 0; j < SIZE; j++){
        if(isFull(0, j)){
            enqueue(j);
        }
    }

    // Loop until the queue is empty
    while(front != -1){
        int j = dequeue();
        // Check if any neighbors are full and add them to the queue
        if(isValid(0, j - 1) && isFull(0, j - 1)){
            enqueue(j - 1);
        }
        if(isValid(0, j + 1) && isFull(0, j + 1)){
            enqueue(j + 1);
        }
        if(isValid(1, j) && isFull(1, j)){
            enqueue(j);
        }
        // Fill the cell
        fillCell(0, j);
    }

    // Display the final grid
    displayGrid();
}

int main(){
    // Initialize the grid with empty cells
    for(int i = 0; i < SIZE; i++){
        for(int j = 0;j < SIZE; j++){
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    percolate();
    
    return 0;
}