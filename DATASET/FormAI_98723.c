//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the size of the grid
#define GRID_SIZE 10

// Defining the threshold probability
#define THRESHOLD 0.6

// Defining the percolation flow directions
const int FLOWS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Defining the grid
int grid[GRID_SIZE][GRID_SIZE];

// Function to print the grid
void printGrid() {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the flow from start to end is possible
int isFlowPossible(int startX, int startY, int endX, int endY) {
    int visited[GRID_SIZE][GRID_SIZE] = {0}; // Marking all cells as unvisited
    visited[startX][startY] = 1; // Marking the start cell as visited

    // Implementing DFS
    int stackX[GRID_SIZE*GRID_SIZE], stackY[GRID_SIZE*GRID_SIZE];
    int top = -1;
    top++;
    stackX[top] = startX;
    stackY[top] = startY;

    while(top >= 0) {
        int curX = stackX[top], curY = stackY[top];
        top--;

        // Checking if the current cell is the end cell
        if(curX == endX && curY == endY) {
            return 1;
        }

        // Checking for possible flows
        for(int i = 0; i < 4; i++) {
            int nextX = curX + FLOWS[i][0], nextY = curY + FLOWS[i][1];

            if(nextX >= 0 && nextX < GRID_SIZE && nextY >= 0 && nextY < GRID_SIZE &&
               !visited[nextX][nextY] && grid[nextX][nextY]) {
                visited[nextX][nextY] = 1;
                top++;
                stackX[top] = nextX;
                stackY[top] = nextY;
            }
        }
    }

    return 0;
}

// Main Function
int main() {
    // Randomizing the grid with given probability
    srand(time(NULL));
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if((double)rand()/(double)RAND_MAX >= THRESHOLD) {
                grid[i][j] = 1;
            }
        }
    }

    // Printing the initial grid
    printf("Initial grid:\n");
    printGrid();

    // Checking for percolation
    int percolates = 0;
    for(int i = 0; i < GRID_SIZE; i++) {
        if(isFlowPossible(0, i, GRID_SIZE-1, i)) {
            percolates = 1;
            break;
        }
    }

    // Printing the final grid along with the percolation status
    printf("\nFinal grid:\n");
    printGrid();
    if(percolates) {
        printf("\nPercolation possible!\n");
    }
    else {
        printf("\nPercolation not possible!\n");
    }

    return 0;
}