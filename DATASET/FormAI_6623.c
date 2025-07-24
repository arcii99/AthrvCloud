//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to print the maze
void printMaze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the given row and column are valid
int isValid(int row, int col, char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    return (row>=0 && row<rows && col>=0 && col<cols && maze[row][col]==' ');
}

// Recursive function to find the shortcut route
int findShortcutRoute(int start_row, int start_col, int end_row, int end_col, char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    // Mark the starting position as visited
    maze[start_row][start_col] = 'X';

    // Check if the current position is the ending position
    if(start_row == end_row && start_col == end_col) {
        return 1;
    }

    // Check in all four directions
    if(isValid(start_row-1, start_col, maze, rows, cols)) {  // Up
        if(findShortcutRoute(start_row-1, start_col, end_row, end_col, maze, rows, cols))
            return 1;
    }
    if(isValid(start_row, start_col+1, maze, rows, cols)) {  // Right
        if(findShortcutRoute(start_row, start_col+1, end_row, end_col, maze, rows, cols))
            return 1;
    }
    if(isValid(start_row+1, start_col, maze, rows, cols)) {  // Down
        if(findShortcutRoute(start_row+1, start_col, end_row, end_col, maze, rows, cols))
            return 1;
    }
    if(isValid(start_row, start_col-1, maze, rows, cols)) {  // Left
        if(findShortcutRoute(start_row, start_col-1, end_row, end_col, maze, rows, cols))
            return 1;
    }

    // If the current position doesn't lead to the ending position,
    // mark it as unvisited and backtrack
    maze[start_row][start_col] = ' ';
    return 0;
}

// Driver code
int main() {
    char maze[MAX_ROWS][MAX_COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };
    int start_row = 1, start_col = 1;
    int end_row = 7, end_col = 8;
    printf("\nMaze before finding the shortcut route:\n");
    printMaze(maze, MAX_ROWS, MAX_COLS);
    findShortcutRoute(start_row, start_col, end_row, end_col, maze, MAX_ROWS, MAX_COLS);
    printf("Shortcut route found!\n");
    printf("\nMaze after finding the shortcut route:\n");
    printMaze(maze, MAX_ROWS, MAX_COLS);
    return 0;
}