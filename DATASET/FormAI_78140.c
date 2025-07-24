//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PROBABILITY 0.5

int grid[ROWS][COLS];
int visited[ROWS][COLS];

void initialize()
{
    int i,j;
    srand((unsigned) time(NULL));
    for (i=0; i<ROWS; i++)
    {
        for (j=0; j<COLS; j++)
        {
            if ((rand()/(double)RAND_MAX) < PROBABILITY)
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void print_grid()
{
    int i,j;
    for (i=0; i<ROWS; i++)
    {
        for (j=0; j<COLS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void dfs(int row, int col)
{    
    int i,j;
    if ((row < 0) || (col < 0) || (row >= ROWS) || (col >= COLS))
        return;
    if (visited[row][col])
        return;
    if (grid[row][col] == 0)
        return;
    visited[row][col] = 1;
    for (i=-1; i<=1; i++)
    {
        for (j=-1; j<=1; j++)
        {
            if ((i == 0) && (j == 0))
                continue;
            dfs(row+i, col+j);
        }
    }
}

int is_percolated()
{
    int i;
    for (i=0; i<COLS; i++)
    {
        if (grid[0][i] == 1)
        {
            dfs(0, i);
            break;
        }
    }
    for (i=0; i<COLS; i++)
    {
        if (visited[ROWS-1][i])
            return 1;
    }
    return 0;
}

int main()
{
    int i,j;
    int percolates;
    
    initialize();
    
    printf("Initial grid:\n");
    print_grid();
    
    percolates = is_percolated();
    if (percolates)
        printf("The system percolates!\n");
    else
        printf("The system does not percolate.\n");
        
    return 0;
}