//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Function to print the maze
void printMaze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
bool isValidMove(char maze[][COLS], int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return false;
    }
    
    if (maze[x][y] == '#') {
        return false;
    }
    
    return true;
}

// Recursive function to find a path through the maze
bool findPath(char maze[][COLS], int x, int y) {
    // If we have reached the end, return true
    if (x == ROWS - 1 && y == COLS - 1) {
        return true;
    }
    
    // If the current cell is not valid, return false
    if (!isValidMove(maze, x, y)) {
        return false;
    }
    
    // Mark the current cell as visited
    maze[x][y] = '#';
    
    // Try to move down
    if (findPath(maze, x + 1, y)) {
        return true;
    }
    
    // Try to move right
    if (findPath(maze, x, y + 1)) {
        return true;
    }
    
    // Try to move up
    if (findPath(maze, x - 1, y)) {
        return true;
    }
    
    // Try to move left
    if (findPath(maze, x, y - 1)) {
        return true;
    }
    
    // If none of the moves from this cell lead to the end, mark it as unvisited and return false
    maze[x][y] = '.';
    return false;
}

int main() {
    // Define the maze
    char maze[ROWS][COLS] = {
        {'S', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '#', '.', '#', '#', '#', '.', '#', '#', '.'},
        {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'},
        {'.', '#', '#', '#', '.', '#', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
        {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
        {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
        {'.', '#', '#', '#', '#', '#', '#', '#', '.', 'E'}
    };
    
    // Print the maze
    printf("Maze:\n");
    printMaze(maze);
    printf("\n");
    
    // Find a path through the maze
    printf("Finding a path through the maze...\n");
    if (findPath(maze, 0, 0)) {
        printf("A path was found!\n");
    } else {
        printf("No path was found!\n");
    }
    
    // Print the maze with the path (if one was found)
    printf("\n");
    printMaze(maze);
    
    return 0;
}