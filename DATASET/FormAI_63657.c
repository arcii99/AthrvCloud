//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // size of grid

// function to print the grid
void print_grid(bool grid[][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j])
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if a cell is open or not
bool is_open(int row, int col, bool grid[][N])
{
    if(row<0 || row>=N || col<0 || col>=N)
        return false;
    else
        return grid[row][col];
}

// function to check if a cell is full or not
bool is_full(int row, int col, bool visited[][N], bool grid[][N])
{
    if(row<0 || row>=N || col<0 || col>=N)
        return false;
    else if(visited[row][col])
        return false;
    else if(!grid[row][col])
        return false;
    else if(row==0) // top row
        return true;
    else
    {
        visited[row][col] = true;

        bool full = is_full(row-1, col, visited, grid) 
                    || is_full(row, col-1, visited, grid)
                    || is_full(row, col+1, visited, grid)
                    || is_full(row+1, col, visited, grid);
        
        if(full)
            grid[row][col] = true;

        return full;
    }
}

// function to percolate the grid
bool percolate(bool grid[][N])
{
    bool visited[N][N]= {false};

    // check if each cell in the top row is full
    for(int i=0; i<N; i++)
    {
        if(is_full(0, i, visited, grid))
            grid[0][i] = true;
    }

    // check if the grid has percolated
    for(int i=0; i<N; i++)
    {
        if(grid[N-1][i] && is_full(N-1, i, visited, grid))
            return true;
    }

    return false;
}

int main()
{
    bool grid[N][N] = {false};
    
    // seed for random number generation
    srand(time(NULL));

    // randomly open cells in the grid
    for(int j=0; j<N; j++)
    {
        int random_num = rand() % N;
        grid[random_num][j] = true;
    }

    // print the initial grid
    printf("Initial grid:\n");
    print_grid(grid);

    // percolate the grid
    bool percolated = percolate(grid);
    
    // print the final grid
    printf("Final grid:\n");
    print_grid(grid);

    // check if grid has percolated or not
    if(percolated)
        printf("The grid has percolated!\n");
    else
        printf("The grid has not percolated!\n");

    return 0;
}