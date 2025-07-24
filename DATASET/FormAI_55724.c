//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void display_grid(char grid[][SIZE])
{
    int i, j;

    printf("\nCurrent Grid: \n");

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void percolate(char grid[][SIZE])
{
    int i, j;
    int is_percolating = 0;

    //check if last row is connected 
    for(j=0;j<SIZE;j++)
    {
        if(grid[SIZE-1][j] == 'O')
        {
            is_percolating = 1;
            break;
        }
    }

    //check for all other rows
    for(i=0;i<SIZE-1;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(grid[i][j] == 'O')
            {
                //check top cell
                if(i>0 && grid[i-1][j] == 'O')
                {
                    grid[i][j] = grid[i-1][j];
                }

                //check left cell
                if(j>0 && grid[i][j-1] == 'O')
                {
                    grid[i][j] = grid[i][j-1];
                }

                //check right cell
                if(j<SIZE-1 && grid[i][j+1] == 'O')
                {
                    grid[i][j] = grid[i][j+1];
                }

                //check bottom cell
                if(i<SIZE-1 && grid[i+1][j] == 'O')
                {
                    grid[i][j] = grid[i+1][j];
                }
            }
        }
    }

    //check if last row is connected 
    if(is_percolating != 1)
    {
        for(j=0;j<SIZE;j++)
        {
            if(grid[SIZE-1][j] == 'O')
            {
                is_percolating = 1;
                break;
            }
        }
    }

    if(is_percolating)
    {
        printf("\nGrid is percolating!\n");
    }
    else
    {
        printf("\nGrid is not percolating!\n");
    }
}

int main()
{
    char grid[SIZE][SIZE];
    int i, j;
    int p = 60; //probability of cell being open

    srand(time(NULL)); //initialize random seed

    //initialize grid
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if((rand() % 100) < p)
            {
                grid[i][j] = 'O';
            }
            else
            {
                grid[i][j] = 'X';
            }
        }
    }

    printf("Welcome to the Percolation Simulator!\n");

    display_grid(grid);

    percolate(grid);

    return 0;
}