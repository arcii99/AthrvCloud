//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int visited[ROWS][COLS];
int grid[ROWS][COLS];
int count = 0;

// function to initialize the grid with random values
void initialize_grid(int probability) 
{
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++) 
        {
            if((rand() % 100) < probability) 
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


// function to print the grid
void print_grid() 
{
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++) 
        {
            if(grid[i][j] == 0) 
            {
                printf(". ");
            } 
            else 
            {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// dfs function to solve the percolation problem
void dfs(int row, int col) 
{
    // mark this cell as visited
    visited[row][col] = 1;
    count++;

    // check if this cell is at the bottom row
    if(row == ROWS-1) 
    {
        return;
    }

    // check the top cell
    if(row-1 >= 0 && grid[row-1][col] == 1 && visited[row-1][col] == 0) 
    {
        dfs(row-1, col);
    }

    // check the left cell 
    if(col-1 >= 0 && grid[row][col-1] == 1 && visited[row][col-1] == 0) 
    {
        dfs(row, col-1);
    }

    // check the right cell 
    if(col+1 < COLS && grid[row][col+1] == 1 && visited[row][col+1] == 0) 
    {
        dfs(row, col+1);
    }

    // check the bottom cell
    if(row+1 < ROWS && grid[row+1][col] == 1 && visited[row+1][col] == 0) 
    {
        dfs(row+1, col);
    }
}

// function to check if the grid percolates
int is_percolating() 
{
    // reset the visited array
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++) 
        {
            visited[i][j] = 0;
        }
    }

    // loop through the top row and check if there exists a path to the bottom row
    for(int col = 0; col < COLS; col++) 
    {
        if(grid[0][col] == 1 && visited[0][col] == 0) 
        {
            dfs(0, col);
        }

        if(count >= ROWS) 
        {
            return 1;
        }
    }

    return 0;
}

int main() 
{
    initialize_grid(50);
    print_grid();

    if(is_percolating()) 
    {
        printf("The grid percolates!\n");
    } 
    else 
    {
        printf("The grid does not percolate.\n");
    }

    return 0;
}