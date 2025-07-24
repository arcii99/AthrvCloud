//FormAI DATASET v1.0 Category: Game of Life ; Style: excited
// Woohoo! Get ready for a fun ride with my exciting C Game of Life example program!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

// My favorite function! Displays the current life grid with some fancy colors
void displayLifeGrid(bool lifeGrid[HEIGHT][WIDTH])
{
    printf("\033[2J\033[1;1H"); // Clearing screen for fun!
    printf("\033[1;36m"); // Fancy cyan color for the grid header

    printf("╔"); // Top left corner
    for (int j = 0; j < WIDTH; j++)
    {
        printf("═"); // Top border
    }
    printf("╗\n"); // Top right corner

    printf("║\033[1;33mLife Grid\033[1;36m║\n"); // Fancy yellow color for "Life Grid" label

    printf("╠"); // Left border
    for (int j = 0; j < WIDTH; j++)
    {
        printf("═"); // Middle border
    }
    printf("╣\n"); // Right border

    for (int i = 0; i < HEIGHT; i++)
    {
        printf("║"); // Left border

        for (int j = 0; j < WIDTH; j++)
        {
            if (lifeGrid[i][j])
            {
                printf("\033[1;32m"); // Alive cells are in fancy green color
                printf("■");
            }
            else
            {
                printf("\033[1;31m"); // Dead cells are in fancy red color
                printf("□");
            }
        }

        printf("\033[1;36m║\n"); // Right border with some fancy cyan again
    }

    printf("╚"); // Bottom left corner
    for (int j = 0; j < WIDTH; j++)
    {
        printf("═"); // Bottom border
    }
    printf("╝\n"); // Bottom right corner

    printf("\033[0m"); // Resetting to normal color
}

int main()
{
    srand(time(NULL)); // Seed for the random number generator

    bool lifeGrid[HEIGHT][WIDTH] = {false}; // Initializing the 2D grid to all dead cells

    // Randomly place some live cells in the grid
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (rand() % 2 == 1)
            {
                lifeGrid[i][j] = true;
            }
        }
    }

    displayLifeGrid(lifeGrid); // Display the initial life grid

    while (true) // The exciting infinite loop!
    {
        usleep(100000); // Sleep for 100ms for some smooth transitions

        bool newLifeGrid[HEIGHT][WIDTH] = {false}; // New grid to store the next generation of cells

        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                int numNeighbors = 0; // Count the number of live neighbors

                // Check the eight neighbors of the current cell
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (k == 0 && l == 0) // Skip the current cell itself
                        {
                            continue;
                        }

                        int ni = i + k;
                        int nj = j + l;

                        if (ni < 0)
                        {
                            ni = HEIGHT - 1; // Wrap around to the other end if necessary
                        }
                        else if (ni >= HEIGHT)
                        {
                            ni = 0; // Wrap around to the other end if necessary
                        }

                        if (nj < 0)
                        {
                            nj = WIDTH - 1; // Wrap around to the other end if necessary
                        }
                        else if (nj >= WIDTH)
                        {
                            nj = 0; // Wrap around to the other end if necessary
                        }

                        if (lifeGrid[ni][nj])
                        {
                            numNeighbors++;
                        }
                    }
                }

                if (lifeGrid[i][j]) // The current cell is alive
                {
                    if (numNeighbors == 2 || numNeighbors == 3) // It survives!
                    {
                        newLifeGrid[i][j] = true;
                    }
                }
                else // The current cell is dead
                {
                    if (numNeighbors == 3) // It comes alive!
                    {
                        newLifeGrid[i][j] = true;
                    }
                }
            }
        }

        // Copy the new grid back to the original grid
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                lifeGrid[i][j] = newLifeGrid[i][j];
            }
        }

        displayLifeGrid(lifeGrid); // Display the updated life grid

        // Try commenting out the below line for some more excitement!
        printf("\033[1;36mPress Ctrl+C to exit...\033[0m\n"); // Fancy cyan color for the exit message
    }

    return 0; // We will never get here, but let's do it properly anyway!
}