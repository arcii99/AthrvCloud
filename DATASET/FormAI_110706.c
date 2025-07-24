//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: real-life
#include <stdio.h>
#define ROW 10
#define COL 10

// Function to check if possible to move to a cell
int isSafe(int maze[][COL], int x, int y)
{
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1)
        return 1;
    return 0;
}

// Function to print the solution matrix
void printSolution(int solution[][COL])
{
    printf("Maze Solution:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d ", solution[i][j]);
        printf("\n");
    }
}

// Function to solve the maze using backtracking
int solveMazeUtil(int maze[][COL], int x, int y, int solution[][COL])
{
    // Base case: if rat reaches the end
    if (x == ROW - 1 && y == COL - 1) {
        solution[x][y] = 1;
        return 1;
    }

    // Check if rat can move to (x,y) cell
    if (isSafe(maze, x, y) == 1) {
        // Mark the current cell as part of solution path
        solution[x][y] = 1;

        // Move forward in x direction
        if (solveMazeUtil(maze, x + 1, y, solution) == 1)
            return 1;

        // If moving in x direction didn't give solution
        // Then Move down in y direction
        if (solveMazeUtil(maze, x, y + 1, solution) == 1)
            return 1;

        // If moving in both directions doesn't give solution
        // Then backtrack
        solution[x][y] = 0;
        return 0;
    }

    return 0;
}

// Solve the maze using backtracking
void solveMaze(int maze[][COL])
{
    int solution[ROW][COL] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

    if (solveMazeUtil(maze, 0, 0, solution) == 0) {
        printf("Solution does not exist");
        return;
    }

    printSolution(solution);
}

// Main function
int main()
{
    int maze[ROW][COL] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 },
                           { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                           { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                           { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                           { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
                           { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                           { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
                           { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };

    solveMaze(maze);
    return 0;
}