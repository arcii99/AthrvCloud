//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10

char dungeon[WIDTH][HEIGHT];

struct Room
{
    int x, y, width, height;
};

void carvePath(int x1, int y1, int x2, int y2)
{
    while(x1 != x2 || y1 != y2)
    {
        if(x1 < x2)
        {
            x1++;
        }
        else if(x1 > x2)
        {
            x1--;
        }

        if(y1 < y2)
        {
            y1++;
        }
        else if(y1 > y2)
        {
            y1--;
        }

        dungeon[x1][y1] = '.';
    }
}

int main()
{
    srand(time(NULL));

    // Set all cells to a wall
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            dungeon[x][y] = '#';
        }
    }

    struct Room rooms[MAX_ROOMS];

    // Generate rooms
    for (int i = 0; i < MAX_ROOMS; ++i)
    {
        rooms[i].x = rand() % 13 + 1;
        rooms[i].y = rand() % 7 + 1;
        rooms[i].width = rand() % 8 + 4;
        rooms[i].height = rand() % 6 + 3;

        for (int x = rooms[i].x - 1; x <= rooms[i].x + rooms[i].width; ++x)
        {
            for (int y = rooms[i].y - 1; y <= rooms[i].y + rooms[i].height; ++y)
            {
                dungeon[x][y] = '.';
            }
        }
    }

    // Create paths between rooms
    for (int i = 0; i < MAX_ROOMS - 1; ++i)
    {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].height / 2;

        carvePath(x1, y1, x2, y2);
    }

    // Print the dungeon
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            printf("%c", dungeon[x][y]);
        }

        printf("\n");
    }

    return 0;
}