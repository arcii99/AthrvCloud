//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10 // Define the maximum number of rows
#define COL 10 // Define the maximum number of columns

// To check if a cell is valid or not for the maze
bool isValid(int row, int col, int maze[ROW][COL], int visited[ROW][COL])
{
    if (row >= 0 && col >=0 && row < ROW && col < COL && maze[row][col] == 1 && visited[row][col] == false)
        return true;
    return false;
}

// Function to print the solved maze
void printSolution(int solution[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf(" %d ", solution[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to solve the maze
bool mazeSolver(int row, int col, int maze[ROW][COL], int visited[ROW][COL], int solution[ROW][COL])
{
    if (row == ROW-1 && col == COL-1) // If we reach the end
    {
        solution[row][col] = 1;
        return true;
    }
    
    if (isValid(row, col, maze, visited))
    {
        visited[row][col] = true; // Mark as visited
        solution[row][col] = 1; // Mark as part of the solution
        
        // Check in all four directions
        if (mazeSolver(row+1, col, maze, visited, solution))
        {
            return true;
        }
        
        if (mazeSolver(row, col+1, maze, visited, solution))
        {
            return true;
        }
        
        if (mazeSolver(row-1, col, maze, visited, solution))
        {
            return true;
        }
        
        if (mazeSolver(row, col-1, maze, visited, solution))
        {
            return true;
        }
        
        // If no path found, backtrack
        solution[row][col] = 0;
        return false;
    }
    
    return false;
}

int main()
{
    // Example maze
    int maze[ROW][COL] = { {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                           {0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
    
    int visited[ROW][COL];
    int solution[ROW][COL];
    
    // Mark all cells as unvisited and not part of solution
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            visited[i][j] = false;
            solution[i][j] = 0;
        }
    }
    
    if (mazeSolver(0, 0, maze, visited, solution))
    {
        printf("Solution found!\n");
        printSolution(solution);
    }
    else
    {
        printf("Solution not found!\n");
    }
    
    return 0;
}