//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define N 10

int grid[N][N] = {0};

void printGrid()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}

int isPercolate()
{
    int visited[N] = {0};
    visited[0] = 1;
    int lastVisited = 0;
    
    for(int i=0;i<N;i++)
    {
        if(grid[0][i] == 1)
        {
            visited[i] = 1;
            lastVisited = i;
        }
    }
    
    while(visited[N-1] == 0)
    {
        for(int i=0;i<N;i++)
        {
            if(visited[i] == 1)
            {
                visited[i-1] = 1;
                lastVisited = i-1;
            }
            
            if(visited[i] == 1 && grid[lastVisited+1][i] == 1)
            {
                visited[i+1] = 1;
                lastVisited = i+1;
            }
        }
    }
    
    if(visited[N-1] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    srand((unsigned) time(NULL));
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(rand() % 2 == 0)
            {
                grid[i][j] = 1;
            }
        }
    }
    
    int percolate = isPercolate();
    
    printf("Initial Grid\n");
    printGrid();
    
    if(percolate == 1)
    {
        printf("\nThe grid percolates!\n");
    }
    else
    {
        printf("\nThe grid does not percolate.\n");
    }
    
    return 0;
}