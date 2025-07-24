//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10

void init_grid(int grid[ROWS][COLS])
{
    int i, j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[ROWS][COLS])
{
    int i, j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c ", grid[i][j] ? '#' : '-');
        }
        printf("\n");
    }
}

int count_neighbors(int grid[ROWS][COLS], int x, int y)
{
    int count = 0;
    int i, j;
    for(i=x-1;i<=x+1;i++)
    {
        for(j=y-1;j<=y+1;j++)
        {
            if(i<0 || j<0 || i>=ROWS || j>=COLS)
            {
                continue;
            }
            if(grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

void next_generation(int grid[ROWS][COLS], int next_grid[ROWS][COLS])
{
    int i, j;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            int count = count_neighbors(grid, i, j);
            if(grid[i][j] == 1)
            {
                if(count < 2 || count > 3)
                {
                    next_grid[i][j] = 0;
                }
                else
                {
                    next_grid[i][j] = 1;
                }
            }
            else
            {
                if(count == 3)
                {
                    next_grid[i][j] = 1;
                }
                else
                {
                    next_grid[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    int grid[ROWS][COLS];
    int next_grid[ROWS][COLS];
    int i;

    init_grid(grid);

    while(1)
    {
        print_grid(grid);
        usleep(100000);
        system("clear");
        next_generation(grid, next_grid);
        for(i=0;i<ROWS;i++)
        {
            memcpy(&grid[i], &next_grid[i], COLS * sizeof(int));
        }
    }

    return 0;
}