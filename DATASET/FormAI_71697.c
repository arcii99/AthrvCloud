//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  // size of the grid
#define OPEN 1 // site is open
#define BLOCKED -1 // site is blocked
#define CONNECTED 2 // site is connected to the top

void print_grid(int grid[][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j] == OPEN)
                printf("O ");
            else if(grid[i][j] == BLOCKED)
                printf("X ");
            else
                printf("C ");
        }
        printf("\n");
    }
}

int is_valid(int i, int j)
{
    return (i >= 0 && i < N && j >= 0 && j < N);
}

int is_open(int grid[][N], int i, int j)
{
    return (grid[i][j] == OPEN);
}

int is_blocked(int grid[][N], int i, int j)
{
    return (grid[i][j] == BLOCKED);
}

int is_connected(int grid[][N], int i, int j)
{
    return (grid[i][j] == CONNECTED);
}

int top_row(int i)
{
    return (i < N); // checks whether the site is in the top row
}

int bottom_row(int i)
{
    return (i >= (N*N-N)); // checks whether the site is in the bottom row
}

void connect(int grid[][N], int i, int j)
{
    int dx[4] = {-1, 0, 0, 1}; // left, up, down and right
    int dy[4] = {0, 1, -1, 0};

    for(int k=0; k<4; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(is_valid(ni, nj) && is_open(grid, ni, nj))
        {
            // if the neighbouring site is open, it is connected to the top
            grid[ni][nj] = CONNECTED;
            connect(grid, ni, nj); // recursively check its neighbours
        }
    }
}

int percolates(int grid[][N])
{
    for(int j=0; j<N; j++)
    {
        if(is_connected(grid, N-1, j)) // checks whether there is a connected site in the bottom row
            return 1;
    }

    return 0;
}

void percolation(int grid[][N])
{
    for(int i=0; i<N*N; i++)
    {
        int row = rand() % N;
        int col = rand() % N;

        if(is_blocked(grid, row, col)) // if the site is blocked, open it
        {
            grid[row][col] = OPEN;

            if(top_row(row)) // if it is in the top row, it is connected to the top
                grid[row][col] = CONNECTED;

            connect(grid, row, col); // recursively check the neighbours

            if(percolates(grid)) // if the system percolates, stop
                break;
        }
    }

    print_grid(grid);
}

int main()
{
    srand(time(NULL));

    int grid[N][N];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            grid[i][j] = BLOCKED;
        }
    }

    percolation(grid);

    return 0;
}