//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grids[N][N];
int open[N][N];
int size[N][N];
int numOpen = 0;

/* Function to initialize the grid */
void initializeGrid()
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            grids[i][j] = 0;
            open[i][j] = 0;
            size[i][j] = 1;
        }
    }
}

/* Function to open a site on the grid */
void openSite(int row, int col)
{
    if(open[row][col])
        return;
    open[row][col] = 1;
    numOpen++;
    /* Setting the top row as full */
    if(row == 0)
        grids[row][col] = 1;
    int deltaRow[] = {-1, 0, 1, 0};
    int deltaCol[] = {0, 1, 0, -1};
    int adjRow, adjCol, i;
    /* Checking if adjacent sites are open and connected */
    for(i = 0; i < 4; i++)
    {
        adjRow = row + deltaRow[i], adjCol = col + deltaCol[i];
        if(adjRow >= 0 && adjRow < N && adjCol >= 0 && adjCol < N && open[adjRow][adjCol])
        {
            if(grids[adjRow][adjCol])
                grids[row][col] = 1;
            else
                size[adjRow][adjCol] += size[row][col], size[row][col] = size[adjRow][adjCol];
        }
    }
}

/* Function to check if the top and bottom of the grid are connected */
int percolates()
{
    int i, j;
    for(j = 0; j < N; j++)
    {
        if(grids[N-1][j])
        {
            for(i = 0; i < N; i++)
            {
                if(grids[0][i])
                    return 1;
            }
        }
    }
    return 0;
}

/* Function to simulate the percolation */
void simulatePercolation()
{
    srand(time(NULL));
    while(!percolates())
    {
        int row = rand() % N, col = rand() % N;
        openSite(row, col);
    }
}

/* Function to print out the grid */
void printGrid()
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(open[i][j])
                printf("%c ", grids[i][j] ? 'X' : 'O');
            else
                printf("# ");
        }
        putchar('\n');
    }
}

int main()
{
    initializeGrid();
    simulatePercolation();
    printGrid();
    return 0;
}