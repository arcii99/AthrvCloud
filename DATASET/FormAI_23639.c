//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

char dungeon[HEIGHT][WIDTH];

void generateDungeon()
{
    srand(time(NULL));
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            dungeon[y][x] = rand() % 2 ? '#' : '.';
        }
    }
}

void printDungeon()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", dungeon[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    generateDungeon();
    printDungeon();
    return 0;
}