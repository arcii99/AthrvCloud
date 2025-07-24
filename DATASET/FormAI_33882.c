//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', ' ', '#', '#', 'X', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Function to find the path through the maze
void mazeRouteFinder(int r, int c) {
    // Base case: if we reach the end of the maze, print the solution
    if (maze[r][c] == 'X') {
        printf("Path found!\n");
        return;
    }
    
    // Mark the current cell as part of the path
    maze[r][c] = '+';
    
    // Try moving up
    if (maze[r-1][c] == ' ' || maze[r-1][c] == 'X') {
        mazeRouteFinder(r-1, c);
    }
    
    // Try moving down
    if (maze[r+1][c] == ' ' || maze[r+1][c] == 'X') {
        mazeRouteFinder(r+1, c);
    }
    
    // Try moving left
    if (maze[r][c-1] == ' ' || maze[r][c-1] == 'X') {
        mazeRouteFinder(r, c-1);
    }
    
    // Try moving right
    if (maze[r][c+1] == ' ' || maze[r][c+1] == 'X') {
        mazeRouteFinder(r, c+1);
    }
    
    // If we've reached this point, it means we can't find a path from this cell
    // so mark it as unexplored
    maze[r][c] = ' ';
}

int main(void) {
    int start_row = 1;
    int start_col = 1;
    
    printf("Original maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    mazeRouteFinder(start_row, start_col);
    
    printf("Solution maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}