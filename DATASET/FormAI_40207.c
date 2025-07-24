//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A Maze is represented by a 2D array of integers
#define ROW 6
#define COL 6

int maze[ROW][COL] = {
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 1}
};

int solution[ROW][COL];

// Recursive function to solve the Maze using Backtracking
int solveMazeUtil(int x, int y) {
    if (x == ROW - 1 && y == COL - 1) {
        solution[x][y] = 1;
        return 1;
    }
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1) {
        solution[x][y] = 1;
        if (solveMazeUtil(x + 1, y))
            return 1;
        if (solveMazeUtil(x, y + 1))
            return 1;
        solution[x][y] = 0;
        return 0;
    }
    return 0;
}

// Function to solve the Maze
void solveMaze() {
    if (solveMazeUtil(0, 0) == 0)
        printf("No Solution Exist!\n");
    else {
        printf("Solution:\n");
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++)
                printf("%d ", solution[i][j]);
            printf("\n");
        }
    }
}

// Main Function
int main() {
    solveMaze();
    return 0;
}