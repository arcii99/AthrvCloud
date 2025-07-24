//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

void printMaze(char maze[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(char maze[][COLS], int row, int col, int rows, int cols) {
    if (row >= 0 && row < rows && col >= 0 && col < cols && maze[row][col] == '.') {
        return true;
    }
    return false;
}

bool solveMaze(char maze[][COLS], int row, int col, int rows, int cols) {
    if (row == rows - 1 && col == cols - 1) { // Reached destination
        maze[row][col] = 'X';
        return true;
    }

    if (isSafe(maze, row, col, rows, cols)) {
        maze[row][col] = 'X';

        if (solveMaze(maze, row + 1, col, rows, cols)) { // Move down
            return true;
        }

        if (solveMaze(maze, row, col + 1, rows, cols)) { // Move right
            return true;
        }

        if (solveMaze(maze, row - 1, col, rows, cols)) { // Move up
            return true;
        }

        if (solveMaze(maze, row, col - 1, rows, cols)) { // Move left
            return true;
        }

        maze[row][col] = '.'; // Backtrack
        return false;
    }
    return false;
}

int main() {
    char maze[ROWS][COLS] = {
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    if (solveMaze(maze, 0, 0, ROWS, COLS)) {
        printf("Maze solved!\n");
        printMaze(maze, ROWS, COLS);
    } else {
        printf("Maze solution not found!\n");
    }

    return 0;
}