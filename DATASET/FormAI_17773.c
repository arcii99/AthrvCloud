//FormAI DATASET v1.0 Category: Computer Biology ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Constants
#define NUM_ROWS 10
#define NUM_COLS 10

// Declare Global Variables
int grid[NUM_ROWS][NUM_COLS];
int total_alive = 0;

// Function Declarations
void initialize_grid();
void print_grid();
void update_grid();

int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the grid
    initialize_grid();

    // Keep updating the grid and printing it out
    while(1)
    {
        update_grid();
        print_grid();
    }

    return 0;
}

void initialize_grid()
{
    // Iterate over each cell in the grid
    for(int i=0; i<NUM_ROWS; i++)
    {
        for(int j=0; j<NUM_COLS; j++)
        {
            // Randomly set it to be alive or dead
            if(rand()%2 == 1)
            {
                grid[i][j] = 1; // alive
                total_alive++;
            }
            else
            {
                grid[i][j] = 0; // dead
            }
        }
    }
}

void print_grid()
{
    printf("\n\n");

    // Print out the grid
    for(int i=0; i<NUM_ROWS; i++)
    {
        for(int j=0; j<NUM_COLS; j++)
        {
            if(grid[i][j] == 1)
            {
                printf("*");
            }
            else
            {
                printf("-");
            }   
        }
        printf("\n");
    }

    printf("\nTotal alive: %d", total_alive);
}

void update_grid()
{
    int new_grid[NUM_ROWS][NUM_COLS];
    int new_total = 0;

    // Iterate over each cell in the grid
    for(int i=0; i<NUM_ROWS; i++)
    {
        for(int j=0; j<NUM_COLS; j++)
        {
            // Count the number of neighbors that are alive
            int count = 0;
            for(int k=-1; k<=1; k++)
            {
                for(int l=-1; l<=1; l++)
                {
                    // Skip the current cell
                    if(k == 0 && l == 0)
                    {
                        continue;
                    }

                    // Handle wraparound at the edges of the grid
                    int x = (i+k+NUM_ROWS) % NUM_ROWS;
                    int y = (j+l+NUM_COLS) % NUM_COLS;

                    if(grid[x][y] == 1)
                    {
                        count++;
                    }
                }
            }

            // Apply the rules of the game to update the cell state
            if(grid[i][j] == 1)
            {
                if(count < 2 || count > 3)
                {
                    new_grid[i][j] = 0; // dead
                    new_total--;
                }
                else
                {
                    new_grid[i][j] = 1; // alive
                    new_total++;
                }
            }
            else
            {
                if(count == 3)
                {
                    new_grid[i][j] = 1; // alive
                    new_total++;
                }
                else
                {
                    new_grid[i][j] = 0; // dead
                }
            }
        }
    }

    // Copy the new grid over to the old grid
    for(int i=0; i<NUM_ROWS; i++)
    {
        for(int j=0; j<NUM_COLS; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }

    total_alive = new_total;

    // Pause briefly to slow down the animation
    int delay = 1000000;
    for(int i=0; i<delay; i++);
}