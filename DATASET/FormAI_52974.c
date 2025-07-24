//FormAI DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20 //Number of rows
#define COLS 50 //Number of columns

//Function to print the grid
void printGrid(int grid[ROWS][COLS]) 
{
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++) 
        {
            if (grid[i][j] == 0) {
                printf(".");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

//Function to check the number of live neighbors
int checkNeighbors(int i, int j, int grid[ROWS][COLS])
{
    int count = 0;
    //Checking the left, right, top and bottom cells
    if (i > 0 && grid[i-1][j] == 1)
        count++;
    if (i < ROWS-1 && grid[i+1][j] == 1)
        count++;
    if (j > 0 && grid[i][j-1] == 1)
        count++;
    if (j < COLS-1 && grid[i][j+1] == 1)
        count++;
    //Checking the four diagonal cells
    if (i > 0 && j > 0 && grid[i-1][j-1] == 1)
        count++;
    if (i > 0 && j < COLS-1 && grid[i-1][j+1] == 1)
        count++;
    if (i < ROWS-1 && j > 0 && grid[i+1][j-1] == 1)
        count++;
    if (i < ROWS-1 && j < COLS-1 && grid[i+1][j+1] == 1)
        count++;
    return count;
}

int main()
{
    int grid[ROWS][COLS];
    srand(time(NULL)); //Seeding random number generator
    //Initialize the grid with random live and dead cells
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++) 
        {
            int rn = rand() % 10;
            if (rn < 3) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
    //Print the initial grid
    printf("Initial grid:\n");
    printGrid(grid);
    //Main loop to run the Game of Life
    for(int i = 0; i < 100; i++) 
    {
        int newGrid[ROWS][COLS];
        for(int j = 0; j < ROWS; j++) 
        {
            for(int k = 0; k < COLS; k++) 
            {
                int neighbors = checkNeighbors(j, k, grid);
                //If cell is dead and has exactly 3 live neighbors, resurrect it
                if (grid[j][k] == 0 && neighbors == 3) {
                    newGrid[j][k] = 1;
                }
                //If cell is alive and has less than 2 or more than 3 neighbors, it dies
                else if (grid[j][k] == 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[j][k] = 0;
                }
                //Otherwise cell remains unchanged
                else {
                    newGrid[j][k] = grid[j][k];
                }
            }
        }
        //Update the grid
        for(int j = 0; j < ROWS; j++) 
        {
            for(int k = 0; k < COLS; k++) 
            {
                grid[j][k] = newGrid[j][k];
            }
        }
        //Print the updated grid
        printf("\nIteration %d:\n", i+1);
        printGrid(grid);
    }
    return 0;
}