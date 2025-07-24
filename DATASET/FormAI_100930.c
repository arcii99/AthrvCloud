//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 20

int dungeon[HEIGHT][WIDTH];

void generateLevel()
{
    int i, j;
    srand(time(0));

    // Using nested for loops to randomly place floor and wall tiles
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            // Using the rand function to randomly generate either 0 or 1
            dungeon[i][j] = rand() % 2;
        }
    }
}

int main()
{
    int i, j;

    generateLevel();

    // Using another nested for loop to display the dungeon
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (dungeon[i][j] == 0)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}