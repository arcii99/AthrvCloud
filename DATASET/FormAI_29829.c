//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define OPEN 1
#define BLOCKED 0

int grid[N][N];
int connected_tiles[N][N];

void percolation_simulation(int);
void init_grid();
int is_percolating();
int is_connected(int, int, int, int);
void print_grid();

int main()
{
    srand(time(NULL)); 
    
    percolation_simulation(50);
    
    return 0;
}

void percolation_simulation(int p)
{
    init_grid();
    int open_blocks = 0;
    int row, column;
    int perc_threshold = (N*N)*p/100;
    
    while (open_blocks < perc_threshold) 
    {
        row = rand() % N;
        column = rand() % N;

        if (grid[row][column] == BLOCKED) 
        {
            grid[row][column] = OPEN;
            open_blocks++;
            
            if (is_percolating()) 
            {
                printf("Percolated! %d%% of the blocks are open!\n", p);
                return;
            }
        }
    }
    
    printf("Did not percolate! %d%% of the blocks are open.\n", p);
    print_grid();
}

void init_grid()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = BLOCKED;
        }
    }
}

int is_percolating()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (grid[i][j] == OPEN) 
            {
                connected_tiles[i][j] = 1;
            } else 
            {
                connected_tiles[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        if (is_connected(0, i, N-1, i)) 
        {
            return 1;
        }
    }

    return 0;
}

int is_connected(int x1, int y1, int x2, int y2)
{
    if (x1<0 || x2<0 || y1<0 || y2 <0 || x1>=N || x2>=N || y1>=N || y2>=N) 
    {
        return 0;
    }
    if (connected_tiles[x1][y1] && connected_tiles[x2][y2])
    {
        return 1;
    }
    if (grid[x1][y1] == BLOCKED || grid[x2][y2] == BLOCKED)
    {
        return 0;
    }
    connected_tiles[x1][y1] = 1;

    if (is_connected(x1+1, y1, x2, y2) ||
        is_connected(x1, y1+1, x2, y2) ||
        is_connected(x1-1, y1, x2, y2) ||
        is_connected(x1, y1-1, x2, y2)) 
    {
        connected_tiles[x2][y2] = 1;
        return 1;
    }

    return 0;
}

void print_grid()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (grid[i][j] == BLOCKED) 
            {
                printf(". ");
            } else 
            {
                printf("# ");
            }
        }
        printf("\n");
    }
}