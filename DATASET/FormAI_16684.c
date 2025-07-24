//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 9

// The maze, represented as a 2D array of characters
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Function to print out the maze
void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to find a route through the maze
int find_route(int row, int col) {
    // If this cell is the end of the maze, we've found a route
    if (row == ROWS - 1 && col == COLS - 1) {
        return 1;
    }
    
    // If this cell is a wall or we've already visited it, return 0
    if (maze[row][col] == '#' || maze[row][col] == '+') {
        return 0;
    }
    
    // Mark this cell as visited
    maze[row][col] = '+';
    
    // Try moving in each direction to find a route
    if (row > 0 && find_route(row - 1, col)) { // up
        return 1;
    }
    if (row < ROWS - 1 && find_route(row + 1, col)) { // down
        return 1;
    }
    if (col > 0 && find_route(row, col - 1)) { // left
        return 1;
    }
    if (col < COLS - 1 && find_route(row, col + 1)) { // right
        return 1;
    }
    
    // No route found, mark this cell as dead end
    maze[row][col] = 'x';
    return 0;
}

int main() {
    printf("Original maze:\n");
    print_maze();
    
    printf("\nFinding route...\n");
    if (find_route(0, 0)) {
        printf("Route found!\n");
    } else {
        printf("No route found.\n");
    }
    
    printf("\nFinal maze:\n");
    print_maze();
    
    return 0;
}