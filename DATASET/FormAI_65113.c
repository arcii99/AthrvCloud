//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Structure to hold the cell info
typedef struct {
    int x;          // X coordinate
    int y;          // Y coordinate
    int visited;    // Whether cell is visited or not
} cell;

// Function to initialize the grid
void initGrid(cell grid[ROWS][COLS]) {
    for(int i=0; i<ROWS; ++i) {
        for(int j=0; j<COLS; ++j) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].visited = 0;
        }
    }
}

// Function to print the grid
void printGrid(cell grid[ROWS][COLS]) {
    for(int i=0; i<ROWS; ++i) {
        for(int j=0; j<COLS; ++j) {
            printf("(%d,%d) ", grid[i][j].x, grid[i][j].y);
        }
        printf("\n");
    }
}

// Function to perform DFS on the grid
void DFS(cell grid[ROWS][COLS], int x, int y) {
    grid[x][y].visited = 1;
    printf("(%d,%d) ", x, y);
    if(x > 0 && !grid[x-1][y].visited) DFS(grid, x-1, y);
    if(x < ROWS-1 && !grid[x+1][y].visited) DFS(grid, x+1, y);
    if(y > 0 && !grid[x][y-1].visited) DFS(grid, x, y-1);
    if(y < COLS-1 && !grid[x][y+1].visited) DFS(grid, x, y+1);
}

// Main function
int main() {
    // Initialize the grid
    cell grid[ROWS][COLS];
    initGrid(grid);

    // Print the grid
    printf("Initial Grid:\n");
    printGrid(grid);

    // Perform DFS starting from (0,0)
    printf("\nDFS Traversal:\n");
    DFS(grid,0,0);

    return 0;
}