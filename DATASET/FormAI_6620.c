//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#define width 80
#define height 25

char map[height][width];

// Generates the level map randomly
void generateMap()
{
    int i,j;
    srand(time(NULL));

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            // The border of the map is always a wall
            if(i == 0 || j == 0 || i == height - 1 || j == width - 1)
                map[i][j] = '#';

            // Randomly generate a wall or space for the remaining cells
            else
            {
                if(rand() % 10 < 3)
                    map[i][j] = '#';
                else
                    map[i][j] = ' ';
            }
        }
    }
}

// Displays the current state of the game
void displayMap()
{
    int i,j;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    generateMap();
    displayMap();
    return 0;
}