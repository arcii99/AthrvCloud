//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Generate a random map
    int map[10][10];
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = rand() % 2; // Generate either a 0 (floor) or 1 (wall)
        }
    }

    // Print out the map
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 0)
            {
                printf("."); // Print a period for a floor tile
            }
            else
            {
                printf("#"); // Print a pound sign for a wall tile
            }
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}