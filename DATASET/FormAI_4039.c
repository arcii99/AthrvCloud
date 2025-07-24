//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function to initialize the grid randomly
void init_grid(bool grid[ROWS][COLS])
{
    srand(time(NULL)); // seed random number generator with current time
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            // randomly set cells to either alive or dead
            grid[i][j] = rand() % 2;
        }
    }
}

// function to print the current state of the grid
void print_grid(bool grid[ROWS][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(grid[i][j])
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// function to update the grid according to the game of life rules
void update_grid(bool grid[ROWS][COLS])
{
    // temporary grid to hold the updated state
    bool temp_grid[ROWS][COLS];
    
    // iterate over all cells in the grid
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            // count the number of alive neighboring cells
            int alive_neighbors = 0;
            for(int a=-1; a<=1; a++)
            {
                for(int b=-1; b<=1; b++)
                {
                    // check that the neighboring cell is within the grid bounds
                    int row = i+a;
                    int col = j+b;
                    if(row >= 0 && row < ROWS && col >= 0 && col < COLS)
                    {
                        // skip the current cell
                        if(a == 0 && b == 0) continue;
                        
                        // increment the count if the neighboring cell is alive
                        if(grid[row][col]) alive_neighbors++;
                    }
                }
            }
            
            // apply the game of life rules to determine the new state of the cell
            if(grid[i][j])
            {
                if(alive_neighbors == 2 || alive_neighbors == 3)
                    temp_grid[i][j] = true;
                else
                    temp_grid[i][j] = false;
            }
            else
            {
                if(alive_neighbors == 3)
                    temp_grid[i][j] = true;
                else
                    temp_grid[i][j] = false;
            }
        }
    }
    
    // copy the updated state from the temporary grid back to the original grid
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            grid[i][j] = temp_grid[i][j];
        }
    }
}

int main()
{
    bool grid[ROWS][COLS];
    
    // initialize the grid randomly
    init_grid(grid);
    
    // print the initial state of the grid
    printf("Initial grid state:\n");
    print_grid(grid);
    
    // simulate the game of life for 10 iterations
    for(int i=1; i<=10; i++)
    {
        printf("Iteration %d:\n", i);
        update_grid(grid);
        print_grid(grid);
    }
    
    return 0;
}