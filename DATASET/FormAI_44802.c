//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define CHANCE_INITIAL_WALL 45
#define THRESHOLD 4
#define ITERATIONS 4

int generate_random_num(int max)
{
    return rand() % max;
}

void init_map(char map[HEIGHT][WIDTH])
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (generate_random_num(100) < CHANCE_INITIAL_WALL)
            {
                map[i][j] = '#';
            }
            else
            {
                map[i][j] = ' ';
            }
        }
    }
}

int count_neighbors(char map[HEIGHT][WIDTH], int x, int y)
{
    int i, j, count = 0;
    for (i = -1; i <= 1; i++)
    {
        for (j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) continue;
            if (x + i < 0 || x + i >= HEIGHT || y + j < 0 || y + j >= WIDTH) continue;
            if (map[x+i][y+j] == '#') count++;
        }
    }
    return count;
}

void do_simulation_step(char map[HEIGHT][WIDTH])
{
    int i, j, neighbor_count;
    char new_map[HEIGHT][WIDTH];
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            neighbor_count = count_neighbors(map, i, j);
            if (map[i][j] == '#')
            {
                if (neighbor_count < THRESHOLD)
                {
                    new_map[i][j] = ' ';
                }
                else
                {
                    new_map[i][j] = '#';
                }
            }
            else
            {
                if (neighbor_count > THRESHOLD)
                {
                    new_map[i][j] = '#';
                }
                else
                {
                    new_map[i][j] = ' ';
                }
            }
        }
    }
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            map[i][j] = new_map[i][j];
        }
    }
}

void generate_map(char map[HEIGHT][WIDTH])
{
    int i;
    for (i = 0; i < ITERATIONS; i++)
    {
        do_simulation_step(map);
    }
}

void print_map(char map[HEIGHT][WIDTH])
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char map[HEIGHT][WIDTH];
    srand(time(NULL));
    init_map(map);
    generate_map(map);
    print_map(map);
    return 0;
}