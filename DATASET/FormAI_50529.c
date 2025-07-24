//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
// A Recursive Pathfinding Algorithm for a Grid Maze

#include <stdio.h>

#define ROWS 5
#define COLS 5

// Function to print the solution matrix
void printSolution(int solution[][COLS])
{
    printf("The solution matrix is:\n");
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
            printf(" %d ", solution[i][j]);
        printf("\n");
    }
}

// Function to check if a cell is safe to move
int isSafe(int maze[][COLS], int row, int col)
{
    // Returns 1 if the cell is safe to move to
    return (row >= 0 && row < ROWS && col >= 0 &&
            col < COLS && maze[row][col] == 1);
}

// A recursive function to solve the maze.
int solveMazeUtil(int maze[][COLS], int row, int col, int solution[][COLS])
{
    // If we have reached the goal, we return true
    if(row == ROWS-1 && col == COLS-1 && maze[row][col] == 1)
    {
        solution[row][col] = 1;
        return 1;
    }

    // Checking if the current cell is safe to move to
    if(isSafe(maze, row, col) == 1)
    {
        // Marking the cell as part of solution path
        solution[row][col] = 1;

        // Checking if we can move right
        if(solveMazeUtil(maze, row, col+1, solution) == 1)
            return 1;

        // Checking if we can move down
        if(solveMazeUtil(maze, row+1, col, solution) == 1)
            return 1;

        // Marking the cell as not part of solution path
        solution[row][col] = 0;
        return 0;
    }

    return 0;
}

// Function to solve the maze
void solveMaze(int maze[][COLS])
{
    int solution[ROWS][COLS] = { {0, 0, 0, 0, 0}, 
                                  {0, 0, 0, 0, 0}, 
                                  {0, 0, 0, 0, 0}, 
                                  {0, 0, 0, 0, 0}, 
                                  {0, 0, 0, 0, 0} };

    // If solveMazeUtil returns 0, we cannot reach the goal
    if(solveMazeUtil(maze, 0, 0, solution) == 0)
        printf("Solution does not exist.\n");
    else
        printSolution(solution);
}

// The main function
int main()
{
    // Input maze
    int maze[ROWS][COLS] = { {1, 0, 0, 0, 0}, 
                             {1, 1, 0, 1, 0}, 
                             {0, 1, 1, 1, 0}, 
                             {1, 0, 0, 1, 0}, 
                             {1, 1, 1, 1, 1} };

    // Solving the maze
    solveMaze(maze);

    return 0;
}