//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // the size of the matrix
#define p 0.6 // probability of a cell being open

// create the matrix of blocked cells that will be used in the simulation
int grid[N][N] = {0};

// function for printing the matrix
void print_grid()
{
    printf("\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j] == 0) {printf("⬛ ");}
            else {printf("⬜ ");}
        }
        printf("\n");
    }
}

// function for checking if a cell is open or blocked
int is_open(float prob)
{
    float random = (float)rand()/RAND_MAX;
    if (random < prob) {return 1;}
    else {return 0;}
}

// recursive function to check if the system percolates
int percolate(int row, int col)
{
    if(row < 0 || row >= N || col < 0 || col >= N) {return 0;}
    if(grid[row][col] == 0) {return 0;}
    if(row == N-1) {return 1;}
    grid[row][col] = 0;
    int up = percolate(row-1,col);
    int down = percolate(row+1,col);
    int left = percolate(row,col-1);
    int right = percolate(row,col+1);
    if(up || down || left || right) {return 1;}
    return 0;
}

int main()
{
    // initialize random seed
    srand(time(NULL));

    // create the randomly open cells in the matrix
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            grid[i][j] = is_open(p);
        }
    }

    print_grid();

    // check for system percolation
    int percolates = 0;
    for(int j=0;j<N;j++)
    {
        if(percolate(0,j) == 1) {percolates = 1; break;}
    }

    if(percolates == 1) {printf("\nSystem percolates!\n");}
    else {printf("\nSystem does not percolate.\n");}

    return 0;
}