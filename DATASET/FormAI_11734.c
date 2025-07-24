//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rows, cols, i, j;
    char location[20];
    printf("Enter your current location: ");
    scanf("%s", location);

    srand(time(NULL)); // Seed rand() function for pseudo-random number generation

    rows = rand() % 50; // Random number of rows between 0 and 49
    cols = rand() % 50; // Random number of columns between 0 and 49

    printf("\nYou are currently at %s.\n", location);
    printf("Generating a navigation simulation with %d rows and %d columns...\n\n", rows, cols);
    sleep(2); // Pause for 2 seconds for dramatic effect

    char grid[rows][cols]; // Create a 2D char array to represent the grid

    // Randomly assign 'O' or 'X' to each cell in the grid
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (rand() % 2 == 0)
                grid[i][j] = 'O';
            else
                grid[i][j] = 'X';
        }
    }

    // Print the grid
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\nYour GPS location is: (%d, %d).\n", rand() % rows, rand() % cols); // Display a random GPS location on the grid

    return 0;
}