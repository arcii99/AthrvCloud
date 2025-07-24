//FormAI DATASET v1.0 Category: Game of Life ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#define MAX_ROW 20
#define MAX_COL 20

// Function to print the grid
void printGrid(int grid[MAX_ROW][MAX_COL])
{
    int i, j;
    printf("\n");
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// Function to generate the initial grid
void initGrid(int grid[MAX_ROW][MAX_COL])
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++)
        for (j = 0; j < MAX_COL; j++)
            grid[i][j] = rand() % 2;
}

// Function to count the number of live neighbors
int countNeighbors(int grid[MAX_ROW][MAX_COL], int row, int col)
{
    int i, j, count = 0;
    for (i = -1; i <= 1; i++)
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            if (row + i < 0 || row + i >= MAX_ROW)
                continue;
            if (col + j < 0 || col + j >= MAX_COL)
                continue;
            if (grid[row + i][col + j] == 1)
                count++;
        }
    return count;
}

// Function to update the grid
void updateGrid(int grid[MAX_ROW][MAX_COL])
{
    int i, j, neighbors;

    // Create a copy of the grid
    int newGrid[MAX_ROW][MAX_COL];
    for (i = 0; i < MAX_ROW; i++)
        for (j = 0; j < MAX_COL; j++)
            newGrid[i][j] = grid[i][j];

    // Loop through every cell
    for (i = 0; i < MAX_ROW; i++)
        for (j = 0; j < MAX_COL; j++) {
            
            // Count the number of live neighbors
            neighbors = countNeighbors(grid, i, j);

            // Apply the rules of the Game of Life
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3))
                newGrid[i][j] = 0;
            else if (grid[i][j] == 0 && neighbors == 3)
                newGrid[i][j] = 1;
        }

    // Update the grid
    for (i = 0; i < MAX_ROW; i++)
        for (j = 0; j < MAX_COL; j++)
            grid[i][j] = newGrid[i][j];
}

// Main function
int main()
{
    int grid[MAX_ROW][MAX_COL];
    
    // Generate the initial grid
    initGrid(grid);
    printf("Initial Grid\n");
    printGrid(grid);

    // Update the grid and print it
    int i;
    for(i=0; i<20; i++){
        printf("Generation #%d\n", i);
        updateGrid(grid);
        printGrid(grid);
        usleep(500000); // sleep for 0.5 seconds
    }
    
    return 0;
}