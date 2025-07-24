//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int SIZE = 10;
    int GRID[SIZE][SIZE];
    int i, j, x, y;

    // Set all grid cells to 0
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            GRID[i][j] = 0;
        }
    }

    // Randomly add some 1's to the grid
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        x = rand() % SIZE;
        y = rand() % SIZE;
        GRID[x][y] = 1;
    }

    // Print the initial grid
    printf("Initial Grid:\n");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d ", GRID[i][j]);
        }
        printf("\n");
    }

    // Percolation process
    int finished = 0;
    while (!finished)
    {
        int changed = 0;

        // Check each grid cell
        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                // If the cell is 1 and adjacent to a 1 above or to the left, set it to 1
                if (GRID[i][j] == 1)
                {
                    if ((i > 0 && GRID[i-1][j] == 1) || (j > 0 && GRID[i][j-1] == 1))
                    {
                        if (GRID[i][j] != 2)
                        {
                            GRID[i][j] = 2;
                            changed = 1;
                        }
                    }
                }
            }
        }

        // If no cells were changed, finish the process
        if (!changed)
        {
            finished = 1;
        }
    }

    // Print the final grid
    printf("\nFinal Grid:\n");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d ", GRID[i][j]);
        }
        printf("\n");
    }

    return 0;
}