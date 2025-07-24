//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

int map[ROWS][COLS];

void generate_map()
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            map[i][j] = rand() % 2;
        }
    }
}

void print_map()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c", map[i][j] == 1 ? '#' : '.');
        }

        printf("\n");
    }
}

int main()
{
    generate_map();

    print_map();

    return 0;
}