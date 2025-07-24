//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HEIGHT 15
#define WIDTH 30

bool grid[HEIGHT][WIDTH]; // our array representing the grid
bool visited[HEIGHT][WIDTH]; // array to keep track of visited cells
int flowCount; // variable to count the total number of cells that have flowed

// function to initialize the grid with random values
void initializeGrid() {
    srand(time(NULL));
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = (rand()%2 == 0);
        }
    }
}

// function to print the grid
void printGrid() {
    printf("\n   ");
    for(int i=0; i<WIDTH; i++) {
        printf("%d ", i%10);
    }
    printf("\n  ");
    for(int i=0; i<WIDTH; i++) {
        printf("--");
    }
    printf("\n");
    for(int i=0; i<HEIGHT; i++) {
        printf("%2d|", i);
        for(int j=0; j<WIDTH; j++) {
            if(grid[i][j]) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// function to check whether a cell is a valid one or not
bool isValid(int i, int j) {
    if(i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH) {
        return true;
    }
    return false;
}

// recursive function to flow through the grid
void flow(int i, int j) {
    visited[i][j] = true;
    flowCount++;
    if(isValid(i-1, j) && !visited[i-1][j] && !grid[i-1][j]) {
        flow(i-1, j);
    }
    if(isValid(i+1, j) && !visited[i+1][j] && !grid[i+1][j]) {
        flow(i+1, j);
    }
    if(isValid(i, j-1) && !visited[i][j-1] && !grid[i][j-1]) {
        flow(i, j-1);
    }
    if(isValid(i, j+1) && !visited[i][j+1] && !grid[i][j+1]) {
        flow(i, j+1);
    }
}

// function to calculate the percolation threshold
float calculateThreshold() {
    int totalCells = HEIGHT * WIDTH;
    float flowFraction = (float)flowCount / totalCells;
    return flowFraction;
}

int main() {
    initializeGrid();
    printGrid();
    int startRow, startCol;
    printf("\nEnter the starting cell (row col): ");
    scanf("%d %d", &startRow, &startCol);
    flow(startRow, startCol);
    float threshold = calculateThreshold();
    printf("\nPercolation threshold: %.2f", threshold);
    printGrid();
    return 0;
}