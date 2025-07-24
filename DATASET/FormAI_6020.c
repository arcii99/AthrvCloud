//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Size of the grid
#define SIZE 10
//Probability that each cell becomes open initially
#define PROBABILITY 0.6

//Grid to keep track of open and blocked cells
int grid[SIZE][SIZE];
//Array to keep track of open cells in the top row
int topOpen[SIZE];
//Array to keep track of open cells in the bottom row
int bottomOpen[SIZE];

//Function to initialize the grid
void initializeGrid() {
    srand(time(NULL)); //Seed the random number generator
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if((double)rand() / (double)RAND_MAX <= PROBABILITY) {
                grid[i][j] = 1; //Open cell
            } else {
                grid[i][j] = 0; //Blocked cell
            }
        }
    }
}

//Function to print the grid
void printGrid() {
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Function to check if the percolation is successful
int isPercolating() {
    for(int i=0; i<SIZE; i++) {
        if(topOpen[i] == 1 && bottomOpen[i] == 1) {
            return 1; //Percolation successful
        }
    }
    return 0; //Percolation unsuccessful
}

//Function to check if a cell is open and valid
int isOpen(int row, int col) {
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0; //Invalid cell
    }
    if(grid[row][col] == 1) {
        return 1; //Open cell
    }
    return 0; //Blocked cell
}

//Function to check if a cell is connected to an open cell in the top row
void checkTop(int row, int col) {
    if(isOpen(row-1, col)) {
        topOpen[col] = 1;
    }
}

//Function to check if a cell is connected to an open cell in the bottom row
void checkBottom(int row, int col) {
    if(isOpen(row+1, col)) {
        bottomOpen[col] = 1;
    }
}

//Function to check if a cell is connected to an open cell in the left column
void checkLeft(int row, int col) {
    if(isOpen(row, col-1)) {
        if(col == 0) {
            topOpen[row] = 1;
        } else {
            checkTop(row, col-1);
            checkBottom(row, col-1);
        }
    }
}

//Function to check if a cell is connected to an open cell in the right column
void checkRight(int row, int col) {
    if(isOpen(row, col+1)) {
        if(col == SIZE-1) {
            bottomOpen[row] = 1;
        } else {
            checkTop(row, col+1);
            checkBottom(row, col+1);
        }
    }
}

//Function to check if a cell is connected to an open cell
void checkCell(int row, int col) {
    checkTop(row, col);
    checkBottom(row, col);
    checkLeft(row, col);
    checkRight(row, col);
}

//Function to update the open cells in the top row
void updateTop() {
    for(int i=0; i<SIZE; i++) {
        if(grid[0][i] == 1) {
            topOpen[i] = 1;
        }
    }
}

//Function to update the open cells in the bottom row
void updateBottom() {
    for(int i=0; i<SIZE; i++) {
        if(grid[SIZE-1][i] == 1) {
            bottomOpen[i] = 1;
        }
    }
}

//Function to simulate percolation
void simulatePercolation() {
    int percolating = 0;
    int iterations = 0;
    while(!percolating) {
        iterations++;
        for(int i=0; i<SIZE; i++) {
            topOpen[i] = 0;
            bottomOpen[i] = 0;
        }
        updateTop();
        updateBottom();
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                if(grid[i][j] == 1) {
                    checkCell(i, j);
                }
            }
        }
        percolating = isPercolating();
    }
    printf("Percolation succeeded after %d iterations.\n", iterations);
}

int main() {
    initializeGrid();
    printGrid();
    simulatePercolation();
    return 0;
}