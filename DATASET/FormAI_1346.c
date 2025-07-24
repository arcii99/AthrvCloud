//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS]; // 2D Array to store the maze

void generateMaze(int row, int col)
{
    int i, j;
    srand(time(NULL)); // Set the random seed
    
    // Initialize maze cells
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            maze[i][j] = 1; // 1 indicates the wall
        }
    }
    
    // Create paths using recursive backtracking algorithm
    int x, y;
    x = rand() % row;
    y = rand() % col;
    maze[x][y] = 0; // 0 indicates the path
    backtrack(x, y, row, col);
}

void backtrack(int x, int y, int row, int col)
{
    int dir[4][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}}; // Directions - West, North, East, South
    int i, j, k, d;
    
    // Shuffle directions
    for(k=0; k<4; k++)
    {
        i = rand() % 4;
        j = rand() % 4;
        int temp1 = dir[k][0];
        int temp2 = dir[k][1];
        dir[k][0] = dir[i][0];
        dir[k][1] = dir[i][1];
        dir[i][0] = temp1;
        dir[i][1] = temp2;
    }
    
    // Visit adjacent cell in each direction
    for(d=0; d<4; d++)
    {
        int dx = dir[d][0];
        int dy = dir[d][1];
        int newx = x + dx;
        int newy = y + dy;
        
        if(newx>=0 && newx<row && newy>=0 && newy<col && maze[newx][newy]==1)
        {
            // Carve the path
            maze[newx][newy] = 0;
            maze[x+dx/2][y+dy/2] = 0;
            
            // Continue creating paths
            backtrack(newx, newy, row, col);
        }
    }
}

void printMaze(int row, int col)
{
    int i, j;
    printf("+");
    for(j=0; j<col; j++)
    {
        printf("--+");
    }
    printf("\n");
    for(i=0; i<row; i++)
    {
        printf("|");
        for(j=0; j<col; j++)
        {
            if(maze[i][j]==1)
            {
                printf("##|");
            }
            else
            {   
                printf("  |");
            }
        }
        printf("\n");
        printf("+");
        for(j=0; j<col; j++)
        {
            printf("--+");
        }
        printf("\n");
    }
}

int main()
{
    generateMaze(ROWS, COLS);
    printMaze(ROWS, COLS);
    return 0;
}