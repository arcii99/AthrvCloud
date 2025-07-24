//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define probability 0.6

int grid[N][N];
int visited[N][N];

void printGrid()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==1)
                printf("%c ",176);
            else
                printf("%c ",32);
        }
        printf("\n");
    }
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    if(x>0 && !visited[x-1][y] && grid[x-1][y]==1)
        dfs(x-1,y);
    if(x<N-1 && !visited[x+1][y] && grid[x+1][y]==1)
        dfs(x+1,y);
    if(y>0 && !visited[x][y-1] && grid[x][y-1]==1)
        dfs(x,y-1);
    if(y<N-1 && !visited[x][y+1] && grid[x][y+1]==1)
        dfs(x,y+1);
}

int percolates()
{
    for(int i=0;i<N;i++)
    {
        if(grid[0][i]==1 && visited[0][i]==0)
            dfs(0,i);
        if(grid[N-1][i]==1 && visited[N-1][i]==0)
            dfs(N-1,i);
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==1 && visited[i][j]==0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            float r = (float) rand() / (float) RAND_MAX;
            if(r<probability)
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    printGrid();
    printf("\n");

    if(percolates())
        printf("The system percolates!\n");
    else
        printf("The system does not percolate.\n");

    return 0;
}