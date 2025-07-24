//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// Create a struct to represent a cell in the grid
typedef struct Cell {
    int row;
    int col;
    bool visited;
} Cell;

// Create a function to check if a cell is valid (i.e. within the bounds of the grid and unvisited)
bool is_valid_cell(int row, int col, bool visited[ROWS][COLS]) {
    return (row >= 0 && row < ROWS) && (col >= 0 && col < COLS) && !visited[row][col];
}

// Create a recursive function to find the path through the grid using depth-first search
bool depth_first_search(int grid[ROWS][COLS], int row, int col, bool visited[ROWS][COLS]) {
    // Mark the current cell as visited
    visited[row][col] = true;
  
    // Check if the current cell is the end of the path
    if (grid[row][col] == 2) {
        return true;
    }
  
    // Check all the neighboring cells to see if they can be visited
    if (is_valid_cell(row - 1, col, visited) && grid[row - 1][col] != 0) { // Check north
        if (depth_first_search(grid, row - 1, col, visited)) {
            return true;
        }
    }
    
    if (is_valid_cell(row, col + 1, visited) && grid[row][col + 1] != 0) { // Check east
        if (depth_first_search(grid, row, col + 1, visited)) {
            return true;
        }
    }
    
    if (is_valid_cell(row + 1, col, visited) && grid[row + 1][col] != 0) { // Check south
        if (depth_first_search(grid, row + 1, col, visited)) {
            return true;
        }
    }
    
    if (is_valid_cell(row, col - 1, visited) && grid[row][col - 1] != 0) { // Check west
        if (depth_first_search(grid, row, col - 1, visited)) {
            return true;
        }
    }
    
    // If we've checked all the neighboring cells and none of them lead to the end of the path, backtrack
    return false;
}

int main() {
    // Define the grid
    int grid[ROWS][COLS] = {
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 2}
    };
    
    // Define the starting cell
    Cell start_cell = {0, 0, false};
    
    // Define a boolean array to keep track of which cells have been visited
    bool visited[ROWS][COLS] = {false};
  
    // Start the depth-first search from the starting cell
    if (depth_first_search(grid, start_cell.row, start_cell.col, visited)) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }
  
    return 0;
}