//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of grid
#define PROB 0.6 // Probability of a site being open

int grid[SIZE][SIZE]; // Initializing the grid

void showGrid() // Function to display the grid
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(grid[i][j])
                printf("X "); // If site open, display X
            else
                printf("O "); // Else display O
        }
        printf("\n");
    }
}

int isOpen(int x, int y) // Function to check if site is open
{
    if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) // Out of bounds sites are assumed to be closed
        return 0;
    return grid[x][y];
}

int isFull(int x, int y) // Function to check if site is full
{
    if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        return 0;
    if(!grid[x][y]) // If site is not open, it is not full
        return 0;
    if(x == 0) // If site is in top row, it is full
        return 1;
    if(isFull(x-1,y) || isFull(x,y-1) || isFull(x,y+1)) // If site is connected to top, it is full
        return 1;
    return 0;
}

void percolate() // Function to simulate percolation
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if((double)rand()/RAND_MAX < PROB)
                grid[i][j] = 1; // Site is open
        }
    }
}

int main()
{
    srand(time(NULL)); // Seeding random number generator
    percolate(); // Simulating percolation
    showGrid(); // Displaying grid
    int i, j;
    int flag = 0;
    for(i = 0; i < SIZE; i++)
    {
        if(isFull(SIZE-1, i))
        {
            printf("Percolation has occurred!\n");
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("Percolation has not occurred.\n");
    return 0;
}