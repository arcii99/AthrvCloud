//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // grid size
#define THRESHOLD 0.6 // probability threshold for site to be open

void initialize(int grid[][SIZE]) // function to initialize the grid with closed sites
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void open_sites(int grid[][SIZE]) // function to randomly open a site in the grid
{
    srand(time(NULL));
    int i = rand()%SIZE; // generate a random row index
    int j = rand()%SIZE; // generate a random column index
    if(grid[i][j] == 0)
    {
        grid[i][j] = 1; // open the site if it is not already open
    }
    else
    {
        open_sites(grid); // recursively call the function again if the site is already open
    }
}

int is_percolation_possible(int grid[][SIZE]) // function to check if percolation is possible
{
    int top_row[SIZE], bottom_row[SIZE]; // arrays to identify open sites in top and bottom rows
    for(int i=0; i<SIZE; i++)
    {
        top_row[i] = 0;
        bottom_row[i] = 0;
    }
    for(int i=0; i<SIZE; i++) // identify open sites in top and bottom rows
    {
        if(grid[0][i] == 1)
        {
            top_row[i] = 1;
        }
        if(grid[SIZE-1][i] == 1)
        {
            bottom_row[i] = 1;
        }
    }
    for(int i=0; i<SIZE; i++) // check for a path from top row to bottom row
    {
        if(top_row[i] == 1)
        {
            for(int j=0; j<SIZE; j++)
            {
                if(bottom_row[j] == 1 && grid[0][i] == grid[SIZE-1][j])
                {
                    return 1; // return 1 if a path exists
                }
            }
        }
    }
    return 0; // return 0 if no path exists
}

int main()
{
    int grid[SIZE][SIZE];
    initialize(grid);
    while(!is_percolation_possible(grid)) // simulate percolation until percolation is possible
    {
        open_sites(grid);
        for(int i=0; i<SIZE; i++) // print the grid after opening a site
        {
            for(int j=0; j<SIZE; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("Percolation is possible!\n");
    return 0;
}