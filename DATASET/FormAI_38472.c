//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 5

int isSafe(int row, int col, int visited[][COL], int maze[][COL])
{
    return (row >= 0 &&     // check if row number is valid
            row < ROW &&    // check if column number is valid
            col >= 0 &&     // check if row number is valid
            col < COL &&    // check if column number is valid
            maze[row][col] == 1 && // check if the cell is not blocked
            !visited[row][col]); // check if the cell is not already visited
}

void printSolution(int sol[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

int solveMazeUtil(int maze[][COL], int row, int col, int sol[][COL], int visited[][COL])
{
    // if destination is reached, maze is solved
    // destination is the last cell of the maze
    if (row == ROW - 1 && col == COL - 1) {
        sol[row][col] = 1;
        return 1;
    }
    // Check if maze[row][col] is valid
    if (isSafe(row, col, visited, maze)) {
        // mark visited cell
        visited[row][col] = 1;
        // Include this cell in solution path
        sol[row][col] = 1;
        // Move forward in row direction
        if (solveMazeUtil(maze, row + 1, col, sol, visited))
            return 1;
        // If moving in row direction doesn't give solution
        // then Move down in column direction
        if (solveMazeUtil(maze, row, col + 1, sol, visited))
            return 1;
        // If moving in column direction doesn't give solution
        // then Move back in row direction
        if (solveMazeUtil(maze, row - 1, col, sol, visited))
            return 1;
         // If moving backwards in row direction doesn't give solution
        // then Move upwards in column direction
        if (solveMazeUtil(maze, row, col - 1, sol, visited))
            return 1;
        // If no movement can be done in maze[row][col]
        // then backtrack: unmark visited cell and remove
        // it from solution path
        sol[row][col] = 0;
        return 0;
    }
    return 0;
}

int main()
{
    int maze[ROW][COL] = { { 1, 0, 0, 0, 0 },
                           { 1, 1, 0, 1, 1 },
                           { 0, 1, 1, 1, 0 },
                           { 0, 0, 1, 0, 0 },
                           { 0, 0, 1, 1, 1 } };
    int sol[ROW][COL];
    int visited[ROW][COL];
    int i, j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            sol[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    if (solveMazeUtil(maze, 0, 0, sol, visited) == 0) {
        printf("Solution doesn't exist");
        return 0;
    }

    printSolution(sol);
    return 0;
}