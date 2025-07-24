//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int map[WIDTH][HEIGHT];

int main()
{
    srand(time(NULL)); // initialize random seed

    // fill the map with random tiles
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            map[x][y] = rand() % 2;
        }
    }

    // print out the map
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            printf("%d", map[x][y]);
        }
        printf("\n");
    }

    return 0;
}