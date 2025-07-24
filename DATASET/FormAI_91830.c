//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the grid
void printGrid(int grid[ROWS][COLS])
{
    printf("\n\n");
    printf("---------------------\n");

    for(int i=0;i<ROWS;i++)
    {
        printf("|");

        for(int j=0;j<COLS;j++)
        {
            if(grid[i][j] == -1)
            {
                printf(" |");
            }
            else if(grid[i][j] == 0)
            {
                printf("x|");
            }
            else
            {
                printf("o|");
            }
        }

        printf("\n");
        printf("---------------------\n");
    }
}

int main()
{
    int grid[ROWS][COLS];

    // Initializing all cells as blocked
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            grid[i][j] = -1; // Blocked cell
        }
    }

    // Creating random barrier cells
    srand(time(NULL));
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            int r = rand() % 10; // Generating random number between 0 to 9

            if(r < 4) // There is a 40% chance of a cell being a barrier cell
            {
                grid[i][j] = 0; // Barrier cell
            }
        }
    }

    printf("Percolation Simulator - C edition\n\n");
    printf("Starting grid:\n");
    printGrid(grid);

    int count = 0;

    // Loop to percolate the grid using a Depth First Search approach
    for(int i=0;i<ROWS;i++)
    {
        if(grid[i][0] == 0) // If the cell is a barrier cell
        {
            count++; // Increase the count of percolation

            grid[i][0] = count; // Mark the cell as part of the current percolation

            int stack[ROWS * COLS];
            int top = -1;

            stack[++top] = i * COLS; // Pushing the current cell on to the stack

            while(top >= 0) // Loop until all connected cells have been marked as part of the percolation
            {
                int curr = stack[top--];

                int row = curr / COLS;
                int col = curr % COLS;

                if(row - 1 >= 0 && grid[row-1][col] == 0) // Checking the top cell
                {
                    grid[row-1][col] = count;
                    stack[++top] = (row-1) * COLS + col;
                }

                if(row + 1 < ROWS && grid[row+1][col] == 0) // Checking the bottom cell
                {
                    grid[row+1][col] = count;
                    stack[++top] = (row+1) * COLS + col;
                }

                if(col - 1 >= 0 && grid[row][col-1] == 0) // Checking the left cell
                {
                    grid[row][col-1] = count;
                    stack[++top] = row * COLS + (col-1);
                }

                if(col + 1 < COLS && grid[row][col+1] == 0) // Checking the right cell
                {
                    grid[row][col+1] = count;
                    stack[++top] = row * COLS + (col+1);
                }

                printGrid(grid); // Printing the grid after each percolation

                int flag = 0;

                // Checking if the current percolation has reached the right wall
                for(int k=0;k<ROWS;k++)
                {
                    if(grid[k][COLS-1] == count)
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 1)
                {
                    printf("\n\nPercolation achieved!\n\n");
                    return 0;
                }
            }
        }
    }

    printf("\n\nPercolation not achieved.\n\n");
    return 0;
}