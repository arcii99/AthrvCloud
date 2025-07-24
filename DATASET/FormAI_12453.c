//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of the grid
#define P 0.6 // probability of each site being open

int parent(int i, int j);
void union_sets(int i1, int j1, int i2, int j2);
int find_roots(int i1, int j1, int i2, int j2);
void print_grid();

int open[N][N];
int sz[N][N];
int parent_id[N][N];

int main()
{
    srand(time(NULL));
    
    // Initialise the grid and sets
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            open[i][j] = rand() < (RAND_MAX * P);
            sz[i][j] = 1;
            parent_id[i][j] = i*N + j;
        }
    }
    
    // Perform the percolation
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(open[i][j])
            {
                if(i > 0 && open[i-1][j])
                {
                    union_sets(i, j, i-1, j);
                }
                if(j > 0 && open[i][j-1])
                {
                    union_sets(i, j, i, j-1);
                }
            }
        }
    }
    
    print_grid();
        
    // Check if top and bottom are connected
    int top_root = find_roots(0, 0, 0, N-1);
    int bottom_root = find_roots(N-1, 0, N-1, N-1);
    
    if(top_root == bottom_root)
    {
        printf("Percolation successful!\n");
    }
    else
    {
        printf("Percolation failed :(\n");
    }
    
    return 0;
}

int parent(int i, int j)
{
    int id = i*N + j;
    while(id != parent_id[i][j])
    {
        id = parent_id[i][j];
        i = id / N;
        j = id % N;
    }
    return id;
}

void union_sets(int i1, int j1, int i2, int j2)
{
    int p1 = parent(i1, j1);
    int p2 = parent(i2, j2);
    
    if(p1 == p2)
    {
        return;
    }
    
    if(sz[i1][j1] < sz[i2][j2])
    {
        parent_id[p1/N][p1%N] = p2;
        sz[i2][j2] += sz[i1][j1];
    }
    else
    {
        parent_id[p2/N][p2%N] = p1;
        sz[i1][j1] += sz[i2][j2];
    }
}

int find_roots(int i1, int j1, int i2, int j2)
{
    int p1 = parent(i1, j1);
    int p2 = parent(i2, j2);
    
    return p1;
}

void print_grid()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(open[i][j])
            {
                if(parent_id[i][j] == i*N + j)
                {
                    printf("+");
                }
                else
                {
                    printf("-");
                }
            }
            else
            {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
}