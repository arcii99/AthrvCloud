//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Function to print the maze.
void printMaze(int maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid.
bool isSafe(int maze[][COL], int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1) {
        return true;
    }
    return false;
}

// Function to solve the maze.
bool solveMaze(int maze[][COL], int x, int y, int sol[][COL]) {
    if (x == ROW - 1 && y == COL - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y) == true) {
        sol[x][y] = 1;

        if (solveMaze(maze, x + 1, y, sol) == true) {
            return true;
        }

        if (solveMaze(maze, x, y + 1, sol) == true) {
            return true;
        }

        sol[x][y] = 0;
    }

    return false;
}

int main() {
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int sol[ROW][COL] = { 0 };

    if (solveMaze(maze, 0, 0, sol) == false) {
        printf("Solution does not exist.\n");
        return 0;
    }

    printf("Maze:\n");
    printMaze(maze);
    printf("\nSolution:\n");
    printMaze(sol);

    return 0;
}