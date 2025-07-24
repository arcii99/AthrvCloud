//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Function prototypes
void initializeMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);
bool findPath(char maze[ROWS][COLS], int row, int col);

int main() {
    char maze[ROWS][COLS];
    int startRow, startCol;

    // Initialize maze with starting point marked as S
    initializeMaze(maze);
    maze[0][0] = 'S';

    // Print initial maze
    printf("Original Maze:\n");
    printMaze(maze);

    // Find path through maze
    if (findPath(maze, 0, 0)) {
        printf("Path found!\n");

        // Print final maze with path marked as *
        printf("Final Maze:\n");
        printMaze(maze);
    } else {
        printf("No path found.\n");
    }

    return 0;
}

// Initializes maze with all spaces
void initializeMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = ' ';
        }
    }
}

// Prints the current state of the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursively finds path through maze
bool findPath(char maze[ROWS][COLS], int row, int col) {
    // If we have reached the end
    if (row == ROWS - 1 && col == COLS - 1) {
        maze[row][col] = '*';
        return true;
    }

    // Check right
    if (col < COLS - 1 && maze[row][col + 1] == ' ') {
        maze[row][col] = '*';
        if (findPath(maze, row, col + 1)) {
            return true;
        }
        maze[row][col] = ' ';
    }

    // Check down
    if (row < ROWS - 1 && maze[row + 1][col] == ' ') {
        maze[row][col] = '*';
        if (findPath(maze, row + 1, col)) {
            return true;
        }
        maze[row][col] = ' ';
    }

    // If neither right nor down is possible, return false
    return false;
}