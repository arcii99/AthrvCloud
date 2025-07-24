//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: genious
#include <stdio.h>

#define ROW 7
#define COL 7

// Function to print the maze
void printMaze(int maze[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to solve the maze using backtracking
int solveMazeUtil(int maze[ROW][COL], int x, int y, int sol[ROW][COL]) {
    // If we have reached the goal, return true
    if (x == ROW - 1 && y == COL - 1) {
        sol[x][y] = 1;
        return 1;
    }

    // If the current cell is a valid one
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1) {
        // Mark the current cell as part of the solution path
        sol[x][y] = 1;

        // Move down
        if (solveMazeUtil(maze, x + 1, y, sol)) {
            return 1;
        }

        // Move right
        if (solveMazeUtil(maze, x, y + 1, sol)) {
            return 1;
        }

        // If we cannot move in either direction,
        // backtrack and mark the current cell as not
        // part of the solution path
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

// Function to solve the maze using backtracking
void solveMaze(int maze[ROW][COL]) {
    int sol[ROW][COL] = {0};

    if (solveMazeUtil(maze, 0, 0, sol) == 0) {
        printf("No solution exists.\n");
    } else {
        printf("Solution:\n");
        printMaze(sol);
    }
}

int main() {
    int maze[ROW][COL] = {
            {1, 0, 1, 1, 1, 0, 1},
            {1, 1, 1, 0, 1, 0, 1},
            {0, 0, 1, 0, 1, 0, 1},
            {0, 0, 1, 0, 1, 0, 1},
            {0, 0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 1, 0, 1},
            {1, 1, 1, 0, 1, 1, 1}
    };

    printf("Maze:\n");
    printMaze(maze);

    solveMaze(maze);

    return 0;
}