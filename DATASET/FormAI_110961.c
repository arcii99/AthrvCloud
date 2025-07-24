//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int start_row = 0;
int start_col = 0; 
int end_row = 9;
int end_col = 9;

// The maze solver function using recursive algorithm
void mazeSolver(int row, int col)
{
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
    {
        return;
    }
    if(maze[row][col] == 0 || maze[row][col] == 3)
    {
        return;
    }
    if(row == end_row && col == end_col)
    {
        maze[row][col] = 3;
        return;
    }
    maze[row][col] = 3; // marking the current position as visited
    mazeSolver(row-1, col); // North
    mazeSolver(row, col+1); // East
    mazeSolver(row+1, col); // South
    mazeSolver(row, col-1); // West
    maze[row][col] = 2; // marking the current position as part of the solution path
}

// The main function
int main()
{
    mazeSolver(start_row, start_col);
    printf("Solution Path:\n");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(maze[i][j] == 2)
            {
                printf("> ");
            }
            else if(maze[i][j] == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}