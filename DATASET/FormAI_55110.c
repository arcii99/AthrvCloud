//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

#define WALL '#'
#define FLOOR '.'

char map[HEIGHT][WIDTH];

void init_map();
void print_map();
void generate_map();
int count_neighbors(int x, int y);

int main()
{
    srand(time(0));

    init_map();
    generate_map();
    print_map();

    return 0;
}

void init_map()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x] = WALL;
        }
    }
}

void print_map()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void generate_map()
{
    for (int y = 1; y < HEIGHT - 1; y++)
    {
        for (int x = 1; x < WIDTH - 1; x++)
        {
            if (rand() % 100 < 40)
            {
                map[y][x] = FLOOR;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int y = 1; y < HEIGHT - 1; y++)
        {
            for (int x = 1; x < WIDTH - 1; x++)
            {
                int count = count_neighbors(x, y);

                if (count > 4)
                {
                    map[y][x] = FLOOR;
                }
                else if (count < 4)
                {
                    map[y][x] = WALL;
                }
            }
        }
    }
}

int count_neighbors(int x, int y)
{
    int count = 0;

    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (map[y + j][x + i] == FLOOR)
            {
                count++;
            }
        }
    }

    return count;
}