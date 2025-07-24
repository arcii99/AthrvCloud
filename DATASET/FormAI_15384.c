//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

void initialize(char map[][COLS]);
void print_map(char map[][COLS]);
void generate_map(char map[][COLS]);

int main()
{
    char map[ROWS][COLS];

    initialize(map);

    generate_map(map);

    print_map(map);

    return 0;
}

void initialize(char map[][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            map[i][j] = '#';
        }
    }
}

void generate_map(char map[][COLS])
{
    int i, j;
    int r, c;
    int room_rows, room_cols;
    int rows_offset, cols_offset;

    srand(time(NULL));

    for(i = 0; i < 10; i++)
    {
        room_rows = rand() % 10 + 3;
        room_cols = rand() % 10 + 3;

        rows_offset = rand() % (ROWS - room_rows - 2) + 1;
        cols_offset = rand() % (COLS - room_cols - 2) + 1;

        for(r = rows_offset; r < rows_offset + room_rows; r++)
        {
            for(c = cols_offset; c < cols_offset + room_cols; c++)
            {
                map[r][c] = '.';
            }
        }
    }
}

void print_map(char map[][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            putchar(map[i][j]);
        }

        putchar('\n');
    }
}