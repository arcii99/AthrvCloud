//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // number of rows in the grid
#define COLS 10 // number of columns in the grid

int grid[ROWS][COLS]; // the grid matrix
int visited[ROWS][COLS]; // tracks visited elements in the matrix

// function prototypes
void createGrid();
void displayGrid();
int percolate();
void dfs(int row, int col);

int main() {
    clock_t start = clock(); // start the timer
    int count = 0; // number of percolations
    
    // create the grid
    createGrid();
    
    // display the grid
    printf("INITIAL GRID:\n");
    displayGrid();
    
    // percolate the grid
    count = percolate();
    
    // display the grid after percolation
    printf("GRID AFTER PERCOLATION:\n");
    displayGrid();
    
    // display the number of percolations
    printf("NUMBER OF PERCOLATIONS: %d\n", count);
    
    // calculate the running time
    printf("RUNNING TIME: %f seconds\n", ((double) clock() - start) / CLOCKS_PER_SEC);
    
    return 0;
}

// creates a grid with random values
void createGrid() {
    srand(time(NULL)); // seed the random number generator
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; // assign random value of 0 or 1
            visited[i][j] = 0; // mark as not visited
        }
    }
}

// displays the grid matrix
void displayGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// percolates the grid and returns the number of percolations
int percolate() {
    int count = 0; // number of percolations
    
    for(int i = 0; i < ROWS; i++) {
        if(grid[0][i] == 1 && visited[0][i] == 0) { // if starting element is 1 and has not been visited yet
            count++; // increment percolation count
            dfs(0, i); // perform DFS to mark all connected elements
        }
    }
    
    return count; // return the number of percolations
}

// performs depth first search on the grid to mark all connected elements
void dfs(int row, int col) {
    visited[row][col] = 1; // mark as visited
    
    if(row-1 >= 0 && grid[row-1][col] == 1 && visited[row-1][col] == 0) { // check north
        dfs(row-1, col);
    }
    
    if(row+1 < ROWS && grid[row+1][col] == 1 && visited[row+1][col] == 0) { // check south
        dfs(row+1, col);
    }
    
    if(col-1 >= 0 && grid[row][col-1] == 1 && visited[row][col-1] == 0) { // check west
        dfs(row, col-1);
    }
    
    if(col+1 < COLS && grid[row][col+1] == 1 && visited[row][col+1] == 0) { // check east
        dfs(row, col+1);
    }
}