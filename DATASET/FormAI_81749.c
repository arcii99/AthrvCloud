//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 40

// function to create the maze
void create_maze(int maze[][COL])
{
    int i, j;

    // initialize the maze with walls
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = 0;
            }
        }
    }

    // randomly select starting cell and set it to open
    int start_row = rand() % (ROW - 2) + 1;
    int start_col = rand() % (COL - 2) + 1;
    maze[start_row][start_col] = 2;

    // create the maze
    int row = start_row;
    int col = start_col;
    int prev_dir = -1;
    while (1)
    {
        // check if maze is complete
        if (maze[row - 1][col] == 1 && maze[row + 1][col] == 1 &&
            maze[row][col - 1] == 1 && maze[row][col + 1] == 1)
        {
            break;
        }

        // randomly select a direction
        int dir = rand() % 4;
        while (dir == (prev_dir + 2) % 4)
        {
            dir = rand() % 4;
        }

        // move in the direction
        switch (dir)
        {
        case 0: // up
            if (maze[row - 1][col] == 0)
            {
                maze[--row][col] = 2;
            }
            break;
        case 1: // right
            if (maze[row][col + 1] == 0)
            {
                maze[row][++col] = 2;
            }
            break;
        case 2: // down
            if (maze[row + 1][col] == 0)
            {
                maze[++row][col] = 2;
            }
            break;
        case 3: // left
            if (maze[row][col - 1] == 0)
            {
                maze[row][--col] = 2;
            }
            break;
        }

        prev_dir = dir;
    }
}

// function to print the maze
void print_maze(int maze[][COL])
{
    int i, j;

    printf("+");
    for (j = 0; j < COL - 2; j++)
    {
        printf("--");
    }
    printf("+\n");

    for (i = 1; i < ROW - 1; i++)
    {
        printf("|");
        for (j = 1; j < COL - 1; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("##");
            }
            else if (maze[i][j] == 2)
            {
                printf("  ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("|\n");
    }

    printf("+");
    for (j = 0; j < COL - 2; j++)
    {
        printf("--");
    }
    printf("+\n");
}

int main()
{
    srand(time(NULL));

    int maze[ROW][COL];

    create_maze(maze);
    print_maze(maze);

    return 0;
}