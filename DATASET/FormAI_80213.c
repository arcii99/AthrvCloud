//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define SIZE 10
#define PERCOLATION_THRESHOLD 0.6

// Prototype functions
int percolate(int array[][SIZE]);
void printGrid(int array[][SIZE]);

int main()
{
    // Define and initialize variables
    int grid[SIZE][SIZE] = {0};
    int numIterations = 100;
    int percolationCount = 0;
    
    // Set random seed
    srand(time(NULL));
    
    // Run multiple iterations of the simulation
    for(int i = 0; i < numIterations; i++)
    {
        // Randomly fill grid with open or closed sites
        for(int row = 0; row < SIZE; row++)
        {
            for(int col = 0; col < SIZE; col++)
            {
                double randomNum = (double)rand() / (double)RAND_MAX;
                if(randomNum > PERCOLATION_THRESHOLD)
                {
                    grid[row][col] = 1; // Open
                }
                else
                {
                    grid[row][col] = 0; // Closed
                }
            }
        }
        
        // Check if percolation occurs
        if(percolate(grid))
        {
            percolationCount++;
        }
    }
    
    // Print results
    printf("Number of iterations: %d\n", numIterations);
    printf("Percolation threshold: %f\n", PERCOLATION_THRESHOLD);
    printf("Number of times percolation occurred: %d\n", percolationCount);
    
    return 0;
}

/* 
 * Checks if the grid percolates (i.e., if the top row is connected
 * to the bottom row through open sites).
 */
int percolate(int array[][SIZE])
{
    // Define and initialize variables
    int topRow[SIZE] = {0};
    int bottomRow[SIZE] = {0};
    
    // Identify open sites on top and bottom rows
    for(int col = 0; col < SIZE; col++)
    {
        if(array[0][col] == 1)
        {
            topRow[col] = 1;
        }
        
        if(array[SIZE-1][col] == 1)
        {
            bottomRow[col] = 1;
        }
    }
    
    // Perform DFS starting from each open site on top row
    for(int col = 0; col < SIZE; col++)
    {
        if(topRow[col] == 1)
        {
            int visited[SIZE] = {0};
            visited[col] = 1;
            int stack[SIZE] = {col};
            int stackSize = 1;
            
            // Keep traversing until stack is empty or bottom row is reached
            while(stackSize > 0)
            {
                int currentCol = stack[stackSize-1];
                stackSize--;
                
                // Check adjacent open sites
                if(currentCol > 0 && array[0][currentCol-1] == 1 && visited[currentCol-1] == 0)
                {
                    stack[stackSize] = currentCol-1;
                    stackSize++;
                    visited[currentCol-1] = 1;
                }
                
                if(currentCol < SIZE-1 && array[0][currentCol+1] == 1 && visited[currentCol+1] == 0)
                {
                    stack[stackSize] = currentCol+1;
                    stackSize++;
                    visited[currentCol+1] = 1;
                }
                
                if(array[1][currentCol] == 1 && visited[currentCol] == 0)
                {
                    stack[stackSize] = currentCol;
                    stackSize++;
                    visited[currentCol] = 1;
                }
            }
            
            // Check if a path was found to the bottom row
            for(int i = 0; i < SIZE; i++)
            {
                if(bottomRow[i] == 1 && visited[i] == 1)
                {
                    return 1;
                }
            }
        }
    }
    
    // If no percolation path is found, return 0
    return 0;
}

/* 
 * Prints the grid.
 */
void printGrid(int array[][SIZE])
{
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }
}