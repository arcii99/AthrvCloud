//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the dimensions of the grid
#define ROWS 10
#define COLS 10

// Define the start and end locations
#define START_ROW 0
#define START_COL 0
#define END_ROW ROWS-1
#define END_COL COLS-1

// Function to print the grid with obstacles and path
void printGrid(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col) {
    printf("\nGrid with obstacles:\n");
    for (int i=0; i < ROWS; i++) {
        for (int j=0; j < COLS; j++) {
            if (visited[i][j] == 1) {  // If the cell has been visited and is part of the path
                printf("P ");
            } else if (grid[i][j] == 0) {  // If the cell is empty
                printf(". ");
            } else {  // If the cell has an obstacle
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\nShortest path length: %d\n", grid[row][col]);
}

// Function to check if a given cell is valid and not an obstacle
bool isCellValid(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS)  // Check if the cell is within the grid boundaries
        return false;
    if (visited[row][col] == 1 || grid[row][col] == 1)  // Check if the cell has been visited or has an obstacle
        return false;
    return true;
}

// Function to find the shortest path using BFS
void shortestPath(int grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {{0}};  // Mark all cells as unvisited
    visited[START_ROW][START_COL] = 1;  // Set the start cell as visited
    int queue[ROWS*COLS][2] = {{START_ROW, START_COL}};  // Initialize the queue with the start cell
    int front = 0, rear = 0;  // Initialize the front and rear of the queue
    int row, col;
    
    while (front <= rear) {  // Keep iterating as long as the queue is not empty
        row = queue[front][0];
        col = queue[front][1];
        front++;
        
        if (row == END_ROW && col == END_COL) {  // If the destination is reached, break out of the loop
            printGrid(grid, visited, row, col);
            return;
        }
        
        // Check the neighbors of the cell in all four directions
        if (isCellValid(grid, visited, row-1, col)) {  // Up
            visited[row-1][col] = 1;
            queue[++rear][0] = row-1;
            queue[rear][1] = col;
            grid[row-1][col] = grid[row][col]+1;
        }
        if (isCellValid(grid, visited, row+1, col)) {  // Down
            visited[row+1][col] = 1;
            queue[++rear][0] = row+1;
            queue[rear][1] = col;
            grid[row+1][col] = grid[row][col]+1;
        }
        if (isCellValid(grid, visited, row, col-1)) {  // Left
            visited[row][col-1] = 1;
            queue[++rear][0] = row;
            queue[rear][1] = col-1;
            grid[row][col-1] = grid[row][col]+1;
        }
        if (isCellValid(grid, visited, row, col+1)) {  // Right
            visited[row][col+1] = 1;
            queue[++rear][0] = row;
            queue[rear][1] = col+1;
            grid[row][col+1] = grid[row][col]+1;
        }
    }
    printf("No path found.\n");  // If the destination is not reached, there is no path
}

int main() {
    int grid[ROWS][COLS] = {{0}};  // Initialize the grid with all empty cells
    srand(time(NULL));  // Seed the random number generator
    
    // Create random obstacles in the grid
    for (int i=0; i < ROWS; i++) {
        for (int j=0; j < COLS; j++) {
            if (rand() % 4 == 0) {
                grid[i][j] = 1;
            }
        }
    }
    
    printf("Grid size: %dx%d\n", ROWS, COLS);
    printf("Start location: (%d,%d)\n", START_ROW, START_COL);
    printf("End location: (%d,%d)\n", END_ROW, END_COL);
    shortestPath(grid);  // Find the shortest path using BFS
    
    return 0;
}