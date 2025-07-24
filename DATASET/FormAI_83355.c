//FormAI DATASET v1.0 Category: Game of Life ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 20
#define COLS 50

// Define the states of the cells
#define DEAD ' '
#define ALIVE '@'

// Function to initialize the grid
void initialize_grid(char grid[ROWS][COLS])
{
    // Loop through each cell in the grid and set its state to DEAD
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            grid[row][col] = DEAD;
        }
    }
}

// Function to print the grid
void print_grid(char grid[ROWS][COLS])
{
    system("clear"); // Clear the console
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            printf("%c", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to update the grid based on the rules of the Game of Life
void update_grid(char grid[ROWS][COLS])
{
    char new_grid[ROWS][COLS];

    // Loop through each cell in the grid and determine its new state based on the number of neighbors
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            int num_neighbors = 0;

            // Check the eight neighboring cells
            if(row > 0 && col > 0 && grid[row-1][col-1] == ALIVE) num_neighbors++;
            if(row > 0 && grid[row-1][col] == ALIVE) num_neighbors++;
            if(row > 0 && col < COLS-1 && grid[row-1][col+1] == ALIVE) num_neighbors++;
            if(col > 0 && grid[row][col-1] == ALIVE) num_neighbors++;
            if(col < COLS-1 && grid[row][col+1] == ALIVE) num_neighbors++;
            if(row < ROWS-1 && col > 0 && grid[row+1][col-1] == ALIVE) num_neighbors++;
            if(row < ROWS-1 && grid[row+1][col] == ALIVE) num_neighbors++;
            if(row < ROWS-1 && col < COLS-1 && grid[row+1][col+1] == ALIVE) num_neighbors++;

            if(grid[row][col] == ALIVE)
            {
                if(num_neighbors < 2 || num_neighbors > 3)
                {
                    new_grid[row][col] = DEAD; // Cell dies due to underpopulation or overpopulation
                }
                else
                {
                    new_grid[row][col] = ALIVE; // Cell survives
                }
            }
            else
            {
                if(num_neighbors == 3)
                {
                    new_grid[row][col] = ALIVE; // Cell comes alive due to reproduction
                }
                else
                {
                    new_grid[row][col] = DEAD; // Cell remains dead
                }
            }
        }
    }

    // Copy the new grid to the original grid
    memcpy(grid, new_grid, sizeof(char)*ROWS*COLS);
}

int main()
{
    char grid[ROWS][COLS];

    // Set up the initial configuration of the grid
    initialize_grid(grid);
    grid[5][10] = ALIVE;
    grid[6][11] = ALIVE;
    grid[6][12] = ALIVE;
    grid[5][12] = ALIVE;
    grid[4][12] = ALIVE;

    // Start the Game of Life loop
    printf("Welcome to the Game of Life, Mr. Holmes!\n\n");
    printf("Press any key to start...\n");
    getchar();

    for(int generation = 1; generation <= 1000; generation++)
    {
        print_grid(grid);
        printf("Generation %d\n", generation);
        update_grid(grid);
    }

    return 0;
}