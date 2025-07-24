//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// declare the function for pathfinding algorithm
void findPath(int grid[ROWS][COLS]);

// declare the function for printing the grid
void printGrid(int grid[ROWS][COLS]);

int main()
{
    // initialize the grid
    int grid[ROWS][COLS] = {{0,0,1,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0},
                            {0,0,1,0,0,0,0,0,0,0},
                            {0,0,0,0,0,1,1,1,1,1},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0,0}};

    // print the original grid
    printf("\nOriginal Grid: \n");
    printGrid(grid);

    // call the pathfinding function
    findPath(grid);

    // print the updated grid
    printf("\nUpdated Grid: \n");
    printGrid(grid);

    return 0;
}

void findPath(int grid[ROWS][COLS])
{
    int i, j, row, col, move = 1;
    int found = 0;

    // set starting point and ending point
    int startRow = 0;
    int startCol = 0;
    int endRow = ROWS-1;
    int endCol = COLS-1;

    while(!found)
    {
        found = 1;

        // move through the grid
        for(i=0; i<ROWS; i++)
        {
            for(j=0; j<COLS; j++)
            {
                if(grid[i][j] == move)
                {
                    // check neighbors for next move
                    if(i>0 && grid[i-1][j] == 0)
                    {
                        grid[i-1][j] = move + 1;
                        found = 0;
                    }
                    if(i<ROWS-1 && grid[i+1][j] == 0)
                    {
                        grid[i+1][j] = move + 1;
                        found = 0;
                    }
                    if(j>0 && grid[i][j-1] == 0)
                    {
                        grid[i][j-1] = move + 1;
                        found = 0;
                    }
                    if(j<COLS-1 && grid[i][j+1] == 0)
                    {
                        grid[i][j+1] = move + 1;
                        found = 0;
                    }
                }
            }
        }
        move++;
    }

    // trace the path
    row = endRow;
    col = endCol;
    move = grid[row][col];
    while(move > 1)
    {
        if(row>0 && grid[row-1][col] == move-1)
        {
            row--;
        }
        else if(row<ROWS-1 && grid[row+1][col] == move-1)
        {
            row++;
        }
        else if(col>0 && grid[row][col-1] == move-1)
        {
            col--;
        }
        else if(col<COLS-1 && grid[row][col+1] == move-1)
        {
            col++;
        }
        move--;
    }

    // mark the path on the grid
    startRow = row;
    startCol = col;
    grid[startRow][startCol] = -1;
    while(move < ROWS*COLS)
    {
        if(startRow>0 && grid[startRow-1][startCol] == move+1)
        {
            startRow--;
        }
        else if(startRow<ROWS-1 && grid[startRow+1][startCol] == move+1)
        {
            startRow++;
        }
        else if(startCol>0 && grid[startRow][startCol-1] == move+1)
        {
            startCol--;
        }
        else if(startCol<COLS-1 && grid[startRow][startCol+1] == move+1)
        {
            startCol++;
        }
        move++;
        grid[startRow][startCol] = -1;
    }
}

void printGrid(int grid[ROWS][COLS])
{
    int i,j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if(grid[i][j] == -1)
            {
                printf("* ");
            }
            else if(grid[i][j] == 1)
            {
                printf("S ");
            }
            else if(grid[i][j] == ROWS*COLS)
            {
                printf("E ");
            }
            else if(grid[i][j] == -2)
            {
                printf("X ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}