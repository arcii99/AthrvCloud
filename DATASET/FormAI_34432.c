//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#define MAX_ROWS 10
#define MAX_COLS 10

// Maze
char maze[MAX_ROWS][MAX_COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#','#','#','#','#','#',' ','#'},
    {'#',' ','#','#','#','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#',' ','#'},
    {'#','#','#','#',' ','#','#','#',' ','#'},
    {'#','#','#','#',' ',' ',' ','#',' ','#'},
    {'#','#','#','#',' ','#','#','#',' ','#'},
    {'#','#',' ',' ',' ','#','#','#',' ','#'},
    {'#','#',' ','#','#','#','#','#',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

// Function to print maze
void printMaze(char maze[][MAX_COLS]) {
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            printf("%c ", maze[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a cell is a valid cell in the maze
bool isValidCell(int row, int col) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS && maze[row][col] != '#') {
        return true;
    }
    return false;
}

// Recursive function to find route in the maze
bool findRoute(int row, int col) {
    // If current cell is the exit cell, return true
    if (maze[row][col] == 'E') { 
        return true;
    }
    // If current cell is not a valid cell in the maze, return false
    if (!isValidCell(row, col)) {
        return false;
    }
    // Mark current cell as visited
    maze[row][col] = '*';
    // Check if route is possible in all directions
    if (findRoute(row-1, col) || findRoute(row+1, col) || findRoute(row, col-1) || findRoute(row, col+1)) {
        return true;
    }
    // Mark current cell as unvisited
    maze[row][col] = ' ';
    // No route found
    return false;
}

int main() {
    printf("Maze before route is found:\n\n");
    printMaze(maze);
    
    // Starting point of the maze
    int startRow = 1;
    int startCol = 1;
    // Find route in maze
    if (findRoute(startRow, startCol)) {
        printf("\nRoute found!\n\n");
    } else {
        printf("\nNo route found.\n\n");
    }
    
    printf("Maze after route is found:\n\n");
    printMaze(maze);
    
    return 0;
}