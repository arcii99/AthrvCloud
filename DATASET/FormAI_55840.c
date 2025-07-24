//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 6

// Function to check if a point (x, y) is a valid point
bool isValid(int x, int y, int maze[][COL], bool visited[][COL])
{
    if (x < 0 || x >= ROW || y < 0 || y >= COL)
        return false;

    if (maze[x][y] == 0 || visited[x][y])
        return false;

    return true;
}

// Function to print the solution matrix
void printSolution(int solution[][COL])
{
    printf("\nSolution:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf(" %2d ", solution[i][j]);
        }
        printf("\n");
    }
}

// Function to solve and print the maze
bool solveMazeUtil(int x, int y, int maze[][COL], int solution[][COL], bool visited[][COL])
{
    // If (x, y) is the destination, return true
    if (x == ROW - 1 && y == COL - 1 && maze[x][y] == 1) {
        solution[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isValid(x, y, maze, visited)) {
        // Mark (x, y) as visited
        visited[x][y] = true;

        // Add (x, y) to the solution path
        solution[x][y] = 1;

        // Check if there is a path from (x, y) to the right
        if (solveMazeUtil(x, y + 1, maze, solution, visited))
            return true;

        // Check if there is a path from (x, y) to the bottom
        if (solveMazeUtil(x + 1, y, maze, solution, visited))
            return true;

        // Check if there is a path from (x, y) to the left
        if (solveMazeUtil(x, y - 1, maze, solution, visited))
            return true;

        // Check if there is a path from (x, y) to the top
        if (solveMazeUtil(x - 1, y, maze, solution, visited))
            return true;

        // If there is no path from (x, y) in all 4 directions, backtrack
        solution[x][y] = 0;
        visited[x][y] = false;
        return false;
    }

    return false;
}

// Function to solve the maze
void solveMaze(int maze[][COL])
{
    int solution[ROW][COL] = { {0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0} };

    bool visited[ROW][COL];
    memset(visited, false, sizeof(visited));

    if (solveMazeUtil(0, 0, maze, solution, visited))
        printSolution(solution);
    else
        printf("Solution does not exist");
}

// Driver code
int main()
{
    int maze[ROW][COL] = { {1, 0, 0, 0, 0, 0},
                           {1, 1, 0, 1, 0, 1},
                           {0, 1, 0, 0, 0, 1},
                           {1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 1, 1} };

    solveMaze(maze);

    return 0;
}