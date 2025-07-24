//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

void printMaze(int maze[ROW_SIZE][COL_SIZE]) {
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValidMove(int maze[ROW_SIZE][COL_SIZE], int row, int col) {
    if (row >= 0 && row < ROW_SIZE && col >= 0 && col < COL_SIZE && maze[row][col] == 1) {
        return true;
    }
    return false;
}

bool solveMazeUtil(int maze[ROW_SIZE][COL_SIZE], int row, int col) {
    if (row == ROW_SIZE - 1 && col == COL_SIZE - 1) {  // Goal reached
        maze[row][col] = 2;
        return true;
    }

    if (isValidMove(maze, row, col)) {
        maze[row][col] = 2;  // Mark current cell as visited

        // Try down
        if (solveMazeUtil(maze, row + 1, col)) {
            return true;
        }

        // Try right
        if (solveMazeUtil(maze, row, col + 1)) {
            return true;
        }

        // Try up
        if (solveMazeUtil(maze, row - 1, col)) {
            return true;
        }

        // Try left
        if (solveMazeUtil(maze, row, col - 1)) {
            return true;
        }

        maze[row][col] = 1;  // If no path found, backtrack
        return false;
    }
    return false;
}

void solveMaze(int maze[ROW_SIZE][COL_SIZE]) {
    if (solveMazeUtil(maze, 0, 0)) {
        printf("Path found!\n\n");
        printMaze(maze);
    } else {
        printf("No path found!\n\n");
    }
}

int main() {
    int maze[ROW_SIZE][COL_SIZE] = { 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 1}
    };

    printf("Original Maze:\n\n");
    printMaze(maze);

    solveMaze(maze);

    return 0;
}