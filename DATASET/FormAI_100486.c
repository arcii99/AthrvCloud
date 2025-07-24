//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// defining the size of the grid and the probability of the cells being open
#define N 10
#define P 0.5

// declaring the global variables
bool grid[N][N];
bool visited[N][N];
int size[N * N];
int id[N * N];

// utility function to find the parent of the current cell
int find(int i)
{
    while(i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

// function to union the two cells by updating their parent index
void union_cells(int p, int q)
{
    int root_p = find(p);
    int root_q = find(q);

    if(root_p == root_q)
        return;

    if(size[root_p] < size[root_q])
    {
        id[root_p] = root_q;
        size[root_q] += size[root_p];
    }
    else
    {
        id[root_q] = root_p;
        size[root_p] += size[root_q];
    }
}

// function to check if the current cell is a valid cell
bool is_valid(int i, int j)
{
    return (i >= 0 && i < N && j >= 0 && j < N);
}

// recursive function to check the percolation of the grid
void check_percolation(int i, int j)
{
    visited[i][j] = true;
    
    if(is_valid(i - 1, j) && grid[i - 1][j] && !visited[i - 1][j])
        union_cells(i * N + j, (i - 1) * N + j);

    if(is_valid(i + 1, j) && grid[i + 1][j] && !visited[i + 1][j])
        union_cells(i * N + j, (i + 1) * N + j);

    if(is_valid(i, j - 1) && grid[i][j - 1] && !visited[i][j - 1])
        union_cells(i * N + j, i * N + (j - 1));

    if(is_valid(i, j + 1) && grid[i][j + 1] && !visited[i][j + 1])
        union_cells(i * N + j, i * N + (j + 1));

    for(int x = 0; x < N; x++)
    {
        if(is_valid(0, x) && grid[0][x] && find(x) == find(i * N + j))
        {
            printf("The grid percolates!\n");
            exit(0);
        }
    }

    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            if(grid[x][y] && !visited[x][y])
                check_percolation(x, y);
}

int main()
{
    // initializing the grid and the global arrays
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = (rand() < P * RAND_MAX);
            visited[i][j] = false;
            id[i * N + j] = i * N + j;
            size[i * N + j] = 1;
        }
    }

    // printing the initial state of the grid
    printf("Initial state of the grid:\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j])
                printf("O ");
            else
                printf("X ");
        }
        printf("\n");
    }

    // checking the percolation of the grid
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(grid[i][j] && !visited[i][j])
                check_percolation(i, j);

    // printing the final state of the grid
    printf("Final state of the grid:\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j])
                printf("O ");
            else
                printf("X ");
        }
        printf("\n");
    }

    return 0;
}