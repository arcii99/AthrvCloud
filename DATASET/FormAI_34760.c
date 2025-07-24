//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
/* Act I: Scene I */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define OPEN 1
#define BLOCKED 0

int grid[N][N],uf[N*N],sz[N*N];
int rows,cols;

void init_grid()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            grid[i][j]=BLOCKED;
}

/* Act I: Scene II */
void create_grid()
{
    srand(time(NULL));
    int random_row,random_col;
    int open_sites=0;

    while(1)
    {
        random_row = rand()%N;
        random_col = rand()%N;
        if(grid[random_row][random_col]==BLOCKED)
        {
            grid[random_row][random_col]=OPEN;
            if(is_full(random_row,random_col))
                printf("Alas, we have remained fated to be apart\n");
            open_sites++;
            if(open_sites>=N*N/2)
                break;
        }
    }
}

/* Act II: Scene I */
void init_uf()
{
    for(int i=0;i<N*N;i++)
    {
        uf[i]=i;
        sz[i]=1;
    }
}

int root(int p)
{
    while(uf[p]!=p)
    {
        uf[p]=uf[uf[p]];
        p=uf[p];
    }
    return p;
}

/* Act II: Scene II */
int is_connected(int p,int q)
{
    return root(p)==root(q);
}

/* Act II: Scene III */
void unite(int p,int q)
{
    int p_root = root(p);
    int q_root = root(q);
    if(p_root==q_root)
        return;

    if(sz[p_root] < sz[q_root])
    {
        uf[p_root] = q_root;
        sz[q_root] += sz[p_root];
    }
    else
    {
        uf[q_root] = p_root;
        sz[p_root] += sz[q_root];
    }
}

/* Act III: Scene I */
int is_full(int row,int col)
{
    for(int i=0;i<N;i++)
        if(grid[0][i]==OPEN && is_connected(i,N*row+col))
            return 1;
    return 0;
}

/* Act V */
void percolates()
{
    int flag=0;
    for(int i=0;i<N;i++)
    {
        if(grid[N-1][i]==OPEN)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[0][j]==OPEN && is_connected(N*i+j,N*(N-1)+i))
                {
                    printf("Hark, we are finally together my love!\n");
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==0)
        printf("Alas, we have remained fated to be apart\n");
}

int main()
{
    init_grid();
    create_grid();
    init_uf();

    percolates();

    return 0;
}