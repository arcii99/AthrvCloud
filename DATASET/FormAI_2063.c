//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define PERCOLATION_THRESHOLD 0.5

void initialize(int grid[SIZE][SIZE]);
void printGrid(int grid[SIZE][SIZE]);
int percolates(int grid[SIZE][SIZE]);

int main()
{
    int grid[SIZE][SIZE];
    srand(time(NULL));
    
    initialize(grid);
    printGrid(grid);
    
    int percolation = percolates(grid);
    
    if (percolation)
    {
        printf("Water percolates through the system!\n");
    }
    else
    {
        printf("Water does not percolate through the system.\n");
    }
    
    return 0;
}

void initialize(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            double random = (double)rand() / RAND_MAX;
            if (random > PERCOLATION_THRESHOLD)
            {
                grid[i][j] = 1;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
    }
}

void printGrid(int grid[SIZE][SIZE])
{
    printf("------------------------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------\n");
}

int percolates(int grid[SIZE][SIZE])
{
    int connections[SIZE][SIZE] = {0};
    int count = 0;
    int percolationFlag = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i == 0)
                {
                    connections[i][j] = 1;
                }
                else
                {
                    if ((j > 0 && connections[i-1][j-1] == 1) ||
                        (connections[i-1][j] == 1) ||
                        (j < SIZE-1 && connections[i-1][j+1] == 1))
                    {
                        connections[i][j] = 1;
                    }
                }
            }
        }
    }
    
    for (int j = 0; j < SIZE; j++)
    {
        if (connections[SIZE-1][j] == 1)
        {
            percolationFlag = 1;
            break;
        }
    }
    
    return percolationFlag;
}