//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

void generate_maze(int x, int y)
{
    if ((x < 0) || (x >= ROWS) || (y < 0) || (y >= COLS))
        return;

    if (maze[x][y] == 1)
        return;

    maze[x][y] = 1;

    int directions[4] = {0, 1, 2, 3};
    int temp, swap;

    for (int i = 0; i < 4; i++)
    {
        temp = directions[i];
        swap = rand() % 4;
        directions[i] = directions[swap];
        directions[swap] = temp;
    }

    for (int i = 0; i < 4; i++)
    {
        switch (directions[i])
        {
            case 0: // Up
                generate_maze(x - 1, y);
                break;

            case 1: // Right
                generate_maze(x, y + 1);
                break;

            case 2: // Down
                generate_maze(x + 1, y);
                break;

            case 3: // Left
                generate_maze(x, y - 1);
                break;
        }
    }
}

void print_maze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (maze[i][j] == 1)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Generate maze starting from (0, 0)
    generate_maze(0, 0);

    // Print the maze
    print_maze();

    return 0;
}