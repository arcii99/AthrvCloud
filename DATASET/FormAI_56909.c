//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

void initialize(int grid[N][N])
{
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int r = rand() % 101;
            if(r < 50)
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
        }
    }
}

void print_grid(int grid[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == 1)
                printf("X ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int is_percolating(int grid[N][N])
{
    int top[N], bottom[N];
    for(int i = 0; i < N; i++)
    {
        top[i] = 0;
        bottom[i] = 0;
    }
    for(int i = 0; i < N; i++)
    {
        if(grid[0][i] == 1)
            top[i] = 1;
        if(grid[N-1][i] == 1)
            bottom[i] = 1;
    }
    for(int i = 0; i < N; i++)
    {
        if(top[i] == 1 && bottom[i] == 1)
            return 1;
    }
    return 0;
}

void percolate(int grid[N][N])
{
    int percolates = 0;
    while(!percolates)
    {
        int i = rand() % N;
        int j = rand() % N;
        if(grid[i][j] == 0)
            grid[i][j] = 1;
        percolates = is_percolating(grid);
    }
}

int main()
{
    int grid[N][N];
    initialize(grid);
    printf("Initial grid:\n");
    print_grid(grid);
    percolate(grid);
    printf("Percolated grid:\n");
    print_grid(grid);
    return 0;
}