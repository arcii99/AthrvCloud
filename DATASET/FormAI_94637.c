//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10 // Number of rows in the maze
#define COLS 10 // Number of columns in the maze

char maze[ROWS][COLS] = { // Define the maze as a character array
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'}
};

int startRow = 1, startCol = 1; // Starting position in the maze
int endRow = ROWS - 2, endCol = COLS - 2; // Ending position in the maze

// Function to print the maze
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to recursively find the route through the maze
int findRoute(int r, int c) {
    if (r == endRow && c == endCol) { // If we reach the end, we're done
        maze[r][c] = '*'; // Mark the end with an asterisk
        return 1;
    }
    if (maze[r][c] == '#' || maze[r][c] == '*') { // If we hit a wall or a previously-visited cell, we can't go further
        return 0;
    }
    maze[r][c] = '*'; // Mark the current location with an asterisk
    if (findRoute(r + 1, c) || findRoute(r, c + 1) || findRoute(r - 1, c) || findRoute(r, c - 1)) { // Recurse in all four directions
        return 1;
    }
    maze[r][c] = '.'; // If we couldn't find a path, unmark the current location with a dot
    return 0;
}

int main() {
    printf("Original maze:\n");
    printMaze();
    if (findRoute(startRow, startCol)) { // Try to find a route through the maze
        printf("\nRoute found!\n");
        printMaze();
    }
    else {
        printf("\nNo route found.\n");
    }
    return 0;
}