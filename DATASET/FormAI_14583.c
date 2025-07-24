//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define P_THRESHOLD 0.6

void initialize(int grid[][GRID_SIZE]);
void printGrid(int grid[][GRID_SIZE]);
void initializePercolation(int grid[][GRID_SIZE], int row);
int percolates(int grid[][GRID_SIZE]);

int main() 
{
    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n\n");

    time_t t;
    srand((unsigned) time(&t));
    int grid[GRID_SIZE][GRID_SIZE];

    initialize(grid);
    printf("Our star-crossed grid is initialized:\n");
    printGrid(grid);
    printf("\n");

    int percolates_ = 0;
    int row = 0;

    while (!percolates_) 
    {
        initializePercolation(grid, row);
        printf("Juliet: O Romeo, Romeo, wherefore art thou Romeo?\n");
        printf("Romeo: I am here, fair maiden. What doth thou desire?\n");
        printf("Juliet: Let us see if the significance of our love is met.\n");
        printf("Romeo: Indeed. Let us find if this grid percolates.\n\n");
        printGrid(grid);
        printf("\n");

        percolates_ = percolates(grid);
        row++;
    }

    printf("Our love has prevailed! The grid percolates!\n");
    printf("Two households, both alike in dignity,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean,\n");
    printf("Our love has triumphed, and the percolation threshold\n");
    printf("has been reached. Let us live happily ever after, my dear Romeo.\n");

    return 0;
}

void initialize(int grid[][GRID_SIZE]) 
{
    for (int i = 0; i < GRID_SIZE; i++) 
    {
        for (int j = 0; j < GRID_SIZE; j++) 
        {
            float p = (float)rand()/(float)RAND_MAX;
            if (p < P_THRESHOLD) 
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

void printGrid(int grid[][GRID_SIZE]) 
{
    for (int i = 0; i < GRID_SIZE; i++) 
    {
        for (int j = 0; j < GRID_SIZE; j++) 
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void initializePercolation(int grid[][GRID_SIZE], int row) 
{
    for (int i = 0; i < GRID_SIZE; i++) 
    {
        if (grid[row][i] == 1) 
        {
            grid[row][i] = 2;
        }
    }
}

int percolates(int grid[][GRID_SIZE]) 
{
    int top_row = 0;
    int bottom_row = GRID_SIZE - 1;

    for (int i = 0; i < GRID_SIZE; i++) 
    {
        if (grid[top_row][i] == 2) 
        {
            for (int j = 0; j < GRID_SIZE; j++) 
            {
                if (grid[bottom_row][j] == 2) 
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}