//FormAI DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 50
#define MAX_GENERATIONS 1000

bool grid[GRID_SIZE][GRID_SIZE];

void initialize_grid()
{
    srand(time(NULL));
    
    for(int i=0; i<GRID_SIZE; i++)
    {
        for(int j=0; j<GRID_SIZE; j++)
        {
            // randomly initialize grid cells
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid()
{
    for(int i=0; i<GRID_SIZE; i++)
    {
        for(int j=0; j<GRID_SIZE; j++)
        {
            printf("%s", grid[i][j] ? "O" : " ");
        }
        printf("\n");
    }
}

bool should_live(int x, int y)
{
    int count = 0;
    
    for(int i=x-1; i<=x+1; i++)
    {
        for(int j=y-1; j<=y+1; j++)
        {
            if(i==x && j==y) continue; // exclude current cell
            if(i<0 || i>=GRID_SIZE || j<0 || j>=GRID_SIZE) continue; // exclude out-of-bounds cells
            
            if(grid[i][j]) count++;
        }
    }
    
    if(grid[x][y]) // if cell is currently alive
    {
        if(count<2 || count>3) return false; // if it has less than 2 or more than 3 neighbors, it dies
        else return true; // if it has 2 or 3 neighbors, it survives
    }
    else // if cell is currently dead
    {
        if(count==3) return true; // if it has exactly 3 neighbors, it becomes alive
        else return false; // otherwise it remains dead
    }
}

void simulate_generation()
{
    bool new_grid[GRID_SIZE][GRID_SIZE];
    
    for(int i=0; i<GRID_SIZE; i++)
    {
        for(int j=0; j<GRID_SIZE; j++)
        {
            new_grid[i][j] = should_live(i, j); // determine if each cell should live or die in next generation
        }
    }
    
    for(int i=0; i<GRID_SIZE; i++)
    {
        for(int j=0; j<GRID_SIZE; j++)
        {
            grid[i][j] = new_grid[i][j]; // copy over new grid
        }
    }
}

int main()
{
    initialize_grid();
    
    for(int generation=1; generation<=MAX_GENERATIONS; generation++)
    {
        printf("Generation %d:\n", generation);
        print_grid();
        printf("\n");
        
        simulate_generation();
    }
    
    return 0;
}