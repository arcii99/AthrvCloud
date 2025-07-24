//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define p 0.4

void print_grid(int G[N][N])
{
    printf("Grid:\n");
    for(int i=0;i<N;i++)
    {
        printf("| ");
        for(int j=0;j<N;j++)
        {
            if(G[i][j]==1)
                printf("* ");
            else
                printf("  ");
        }
        printf("|\n");
    }
}

int is_valid(int a,int b)
{
    return (a>=0 && b>=0 && a<N && b<N);
}

int dfs(int x,int y,int G[N][N],int visited[N][N])
{
    visited[x][y]=1;

    if(x==N-1)
        return 1;

    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    int flag=0;

    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(is_valid(nx,ny) && !visited[nx][ny] && G[nx][ny]==1)
            flag = flag || dfs(nx,ny,G,visited);
    }

    return flag;
}

int percolation(int G[N][N])
{
    int visited[N][N]={0};

    for(int i=0;i<N;i++)
    {
        if(G[0][i]==1 && dfs(0,i,G,visited))
            return 1;
    }

    return 0;
}

int count_open_sites(int G[N][N])
{
    int cnt=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cnt+=G[i][j];
        }
    }

    return cnt;
}

void simulate_percolation()
{
    srand(time(0));

    int G[N][N]={0};

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if((double)rand()/RAND_MAX < p)
            {
                G[i][j]=1;
            }
        }
    }

    print_grid(G);

    if(percolation(G))
        printf("\nPercolates!");
    else
        printf("\nDoes not percolate.");

    printf("\n%d open sites created out of %d total sites.\n\n",count_open_sites(G),N*N);
}

void main()
{
    simulate_percolation();
}