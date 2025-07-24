//FormAI DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 80
#define GENERATIONS 1000

void initialize_world(int world[ROWS][COLS])
{
    srand(time(NULL));
    int i, j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            world[i][j] = rand() % 2;
        }
    }
}

int count_neighbors(int world[ROWS][COLS], int row, int col)
{
    int i, j;
    int count = 0;
    
    for(i=row-1; i<=row+1; i++)
    {
        for(j=col-1; j<=col+1; j++)
        {
            if(i>=0 && i<ROWS && j>=0 && j<COLS)
            {
                if(i!=row || j!=col)
                {
                    if(world[i][j] == 1)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

void update_world(int world[ROWS][COLS])
{
    int i, j, count;
    int next_gen[ROWS][COLS];
    
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            count = count_neighbors(world, i, j);
            if(world[i][j] == 1)
            {
                if(count < 2 || count > 3)
                {
                    next_gen[i][j] = 0;
                }
                else
                {
                    next_gen[i][j] = 1;
                }
            }
            else
            {
                if(count == 3)
                {
                    next_gen[i][j] = 1;
                }
                else
                {
                    next_gen[i][j] = 0;
                }
            }
        }
    }
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            world[i][j] = next_gen[i][j];
        }
    }
}

void print_world(int world[ROWS][COLS])
{
    int i, j;
    
    system("clear");
    printf("+");
    for(j=0; j<COLS; j++)
    {
        printf("-");
    }
    printf("+\n");
    
    for(i=0; i<ROWS; i++)
    {
        printf("|");
        for(j=0; j<COLS; j++)
        {
            if(world[i][j] == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("|\n");
    }
    
    printf("+");
    for(j=0; j<COLS; j++)
    {
        printf("-");
    }
    printf("+\n");
}

int main()
{
    int world[ROWS][COLS];
    int i, generation;
    
    initialize_world(world);
    
    for(generation=0; generation<GENERATIONS; generation++)
    {
        print_world(world);
        update_world(world);
        usleep(100000);
    }
    
    return 0;
}