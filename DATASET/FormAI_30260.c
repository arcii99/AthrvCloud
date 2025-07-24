//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Change this value to change the size of the grid
#define OPEN 1
#define BLOCKED 0

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

void printGrid() {
    printf(" ");
    for(int i=0; i<SIZE; i++) {
        printf(" %d", i);
    }
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        printf("%d", i);
        for(int j=0; j<SIZE; j++) {
            if(grid[i][j] == OPEN) {
                printf(" O");
            } else {
                printf(" X");
            }
        }
        printf("\n");
    }
}

int percolates() {
    // Check if the top of the grid is connected to the bottom
    for(int i=0; i<SIZE; i++) {
        if(visited[0][i] && visited[SIZE-1][i]) {
            return 1;
        }
    }
    return 0;
}

int dfs(int row, int col) {
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    }
    if(grid[row][col] == BLOCKED) {
        return 0; 
    }
    if(visited[row][col]) {
        return 0;
    }
    visited[row][col] = 1;
    dfs(row-1, col);
    dfs(row+1, col);
    dfs(row, col-1);
    dfs(row, col+1);
    return 1;
}

int main() {
    srand(time(NULL));
    // Initialize the grid with BLOCKED squares
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            grid[i][j] = BLOCKED;
            visited[i][j] = 0;
        }
    }
    // Open squares randomly until the grid percolates
    int count = 0;
    while(!percolates()) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if(grid[row][col] == BLOCKED) {
            grid[row][col] = OPEN;
            count++;
        }
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                visited[i][j] = 0;
            }
        }
        dfs(0, 0);
    }
    // Print out the final grid
    printGrid();
    printf("Percolates after %d open sites.\n", count);
    return 0;
}