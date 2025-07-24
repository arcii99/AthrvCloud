//FormAI DATASET v1.0 Category: Game of Life ; Style: immersive
// Welcome to the Game of Life!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// Define the size of the grid
#define ROWS 30
#define COLS 80

// Function to print out the grid
void print_grid(bool grid[ROWS][COLS])
{
    // Clear the screen
    system("clear");

    // Loop through the rows and columns of the grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // Print out an asterisk if the cell is alive, or a space if it's dead
            if (grid[i][j])
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to update the grid
void update_grid(bool grid[ROWS][COLS])
{
    // Create a temporary grid to hold the new state of the cells
    bool temp_grid[ROWS][COLS];
    
    // Loop through the rows and columns of the grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // Count the number of live neighbors
            int live_neighbors = 0;
            
            // Check the cell to the left
            if (j > 0 && grid[i][j-1])
            {
                live_neighbors++;
            }
            
            // Check the cell to the right
            if (j < COLS-1 && grid[i][j+1])
            {
                live_neighbors++;
            }
            
            // Check the cell above
            if (i > 0 && grid[i-1][j])
            {
                live_neighbors++;
            }
            
            // Check the cell below
            if (i < ROWS-1 && grid[i+1][j])
            {
                live_neighbors++;
            }
            
            // Check the cell to the top left
            if (i > 0 && j > 0 && grid[i-1][j-1])
            {
                live_neighbors++;
            }
            
            // Check the cell to the top right
            if (i > 0 && j < COLS-1 && grid[i-1][j+1])
            {
                live_neighbors++;
            }
            
            // Check the cell to the bottom left
            if (i < ROWS-1 && j > 0 && grid[i+1][j-1])
            {
                live_neighbors++;
            }
            
            // Check the cell to the bottom right
            if (i < ROWS-1 && j < COLS-1 && grid[i+1][j+1])
            {
                live_neighbors++;
            }
            
            // Apply the rules to update the cell's state
            if (grid[i][j])
            {
                if (live_neighbors == 2 || live_neighbors == 3)
                {
                    temp_grid[i][j] = true;
                }
                else
                {
                    temp_grid[i][j] = false;
                }
            }
            else
            {
                if (live_neighbors == 3)
                {
                    temp_grid[i][j] = true;
                }
                else
                {
                    temp_grid[i][j] = false;
                }
            }
        }
    }
    
    // Copy the new state of the cells back to the original grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = temp_grid[i][j];
        }
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the grid and randomly populate it with cells
    bool grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (rand() % 100 < 20)
            {
                grid[i][j] = true;
            }
            else
            {
                grid[i][j] = false;
            }
        }
    }
    
    // Loop through the generations of the Game of Life
    for (int generation = 0; generation < 100; generation++)
    {
        // Print out the current state of the grid
        print_grid(grid);
        
        // Update the grid
        update_grid(grid);
        
        // Pause for a short period of time
        usleep(100000);
    }
    
    return 0;
}