//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 11

typedef enum { NORTH, EAST, SOUTH, WEST } direction_t;
typedef enum { false, true } bool;
typedef struct { bool walls[4]; } cell_t;
typedef cell_t maze_t[MAZE_SIZE][MAZE_SIZE];

void generate_maze(maze_t);
void print_maze(maze_t);

int main(void)
{
    maze_t maze;
    srand(time(NULL));

    generate_maze(maze);
    print_maze(maze);

    return 0;
}

void generate_maze(maze_t maze)
{
    int i, j, k;
    int rn, cn;

    for (i = 0; i < MAZE_SIZE; i++)
    {
        for (j = 0; j < MAZE_SIZE; j++)
        {
            for (k = 0; k < 4; k++)
                maze[i][j].walls[k] = true;
        }
    }

    rn = rand() % MAZE_SIZE;
    cn = rand() % MAZE_SIZE;

    maze[rn][cn].walls[NORTH] = false;

    do
    {
        direction_t dir;

        do
        {
            dir = rand() % 4;
        } while (
            (dir == NORTH && rn == 0) ||
            (dir == EAST  && cn == MAZE_SIZE - 1) ||
            (dir == SOUTH && rn == MAZE_SIZE - 1) ||
            (dir == WEST  && cn == 0)
        );

        switch (dir)
        {
            case NORTH:
                if (maze[rn - 1][cn].walls[NORTH] == true)
                {
                    maze[rn][cn].walls[NORTH] = false;
                    maze[rn - 1][cn].walls[SOUTH] = false;
                    rn--;
                }
                break;

            case EAST:
                if (maze[rn][cn + 1].walls[WEST] == true)
                {
                    maze[rn][cn].walls[EAST] = false;
                    maze[rn][cn + 1].walls[WEST] = false;
                    cn++;
                }
                break;

            case SOUTH:
                if (maze[rn + 1][cn].walls[SOUTH] == true)
                {
                    maze[rn][cn].walls[SOUTH] = false;
                    maze[rn + 1][cn].walls[NORTH] = false;
                    rn++;
                }
                break;

            case WEST:
                if (maze[rn][cn - 1].walls[WEST] == true)
                {
                    maze[rn][cn].walls[WEST] = false;
                    maze[rn][cn - 1].walls[EAST] = false;
                    cn--;
                }
                break;
        }
    } while (rn != 0 || cn != 0);
}

void print_maze(maze_t maze)
{
    int i, j;

    printf("+");
    for (j = 0; j < MAZE_SIZE; j++)
        printf("--+");
    printf("\n");

    for (i = 0; i < MAZE_SIZE; i++)
    {
        printf("|");
        for (j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j].walls[SOUTH] == true)
                printf("  |");
            else
                printf("   ");
        }
        printf("\n");

        printf("+");
        for (j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j].walls[EAST] == true)
                printf("--+");
            else
                printf("  +");
        }
        printf("\n");
    }
}