//FormAI DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

//initialize the grid with random values
void initialize_grid(int grid[ROWS][COLS])
{
    srand(time(NULL));
    int i,j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            grid[i][j] = rand()%2;
        }
    }
}

//print the grid
void print_grid(int grid[ROWS][COLS])
{
    int i,j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            if(grid[i][j])
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

//get the number of live neighbours for a given cell
int get_live_neighbours(int grid[ROWS][COLS], int i, int j)
{
    int count = 0;
    if(i>0 && j>0 && grid[i-1][j-1])
        count++;
    if(i>0 && grid[i-1][j])
        count++;
    if(i>0 && j<COLS-1 && grid[i-1][j+1])
        count++;
    if(j>0 && grid[i][j-1])
        count++;
    if(j<COLS-1 && grid[i][j+1])
        count++;
    if(i<ROWS-1 && j>0 && grid[i+1][j-1])
        count++;
    if(i<ROWS-1 && grid[i+1][j])
        count++;
    if(i<ROWS-1 && j<COLS-1 && grid[i+1][j+1])
        count++;
    return count;
}

//update the grid for the next generation
void update_grid(int grid[ROWS][COLS])
{
    int new_grid[ROWS][COLS];
    int i,j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            int live_neighbours = get_live_neighbours(grid, i, j);
            if(grid[i][j])
            {
                if(live_neighbours<2 || live_neighbours>3)
                {
                    new_grid[i][j] = 0;
                }
                else
                {
                    new_grid[i][j] = 1;
                }
            }
            else
            {
                if(live_neighbours==3)
                {
                    new_grid[i][j] = 1;
                }
                else
                {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    //copy the new grid to the original grid
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main()
{
    int grid[ROWS][COLS];
    initialize_grid(grid);
    int i;
    for(i=0;i<100;i++)
    {
        system("clear"); //clear the console window
        printf("Generation: %d\n", i+1);
        print_grid(grid);
        update_grid(grid);
        usleep(100000); //wait for 100 milliseconds
    }
    return 0;
}