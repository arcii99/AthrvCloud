//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid

int grid[SIZE][SIZE]; // The grid
int visited[SIZE][SIZE]; // Visited cells to track whether a cell is already processed
int percolated = 0; // Variable to track whether the system has percolated or not

// Function to check whether a cell is open or not
int is_open(int row, int column)
{
    if(grid[row][column] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to check whether a cell is filled or not
int is_full(int row, int column)
{
    if(visited[row][column] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Recursive function to percolate the system
void percolate(int row, int column)
{
    if(row < 0 || row >= SIZE || column < 0 || column >= SIZE)
    {
        // Cell is out of bounds
        return;
    }
    if(visited[row][column] == 1)
    {
        // Cell is already visited
        return;
    }
    visited[row][column] = 1; // Marking the cell as visited
    if(is_open(row, column) == 0)
    {
        // Cell is not open
        return;
    }
    if(row == SIZE - 1)
    {
        // Cell is in the bottom row
        percolated = 1; // The system has percolated
    }
    percolate(row-1, column); // Processing the top cell
    percolate(row+1, column); // Processing the bottom cell
    percolate(row, column-1); // Processing the left cell
    percolate(row, column+1); // Processing the right cell
}

int main()
{
    srand(time(NULL)); // Initializing the random seed
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            int random_number = rand() % 5; // Generating a random number between 0 and 4
            if(random_number == 0)
            {
                grid[i][j] = 0; // The cell is blocked
            }
            else
            {
                grid[i][j] = 1; // The cell is open
            }
            visited[i][j] = 0; // Initializing the visited array to 0
        }
    }
    printf("Initial grid:\n");
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%d ", grid[i][j]); // Printing the initial grid
        }
        printf("\n");
    }
    for(int i=0; i<SIZE; i++)
    {
        percolate(0, i); // Percolating from the top row
    }
    if(percolated == 1)
    {
        printf("The system has percolated!\n"); // The system has percolated
    }
    else
    {
        printf("The system has not percolated.\n"); // The system has not percolated
    }
    return 0;
}