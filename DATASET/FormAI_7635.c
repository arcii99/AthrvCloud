//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 21
#define COL 41

void create_maze(char maze[ROW][COL]);
void print_maze(char maze[ROW][COL]);

int main()
{
    srand(time(NULL));
    char maze[ROW][COL];

    create_maze(maze);
    print_maze(maze);

    return 0;
}

void create_maze(char maze[ROW][COL])
{
    int i, j;

    // Initialize maze with all walls
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (i % 2 == 0 || j % 2 == 0)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
        }
    }

    // Create paths through the maze
    for (i = 1; i < ROW; i += 2)
    {
        for (j = 1; j < COL; j += 2)
        {
            int direction = rand() % 4;

            switch (direction)
            {
            // Move up
            case 0:
                if (i - 2 > 0)
                {
                    maze[i - 1][j] = ' ';
                    maze[i - 2][j] = ' ';
                }
                break;
            // Move right
            case 1:
                if (j + 2 < COL - 1)
                {
                    maze[i][j + 1] = ' ';
                    maze[i][j + 2] = ' ';
                }
                break;
            // Move down
            case 2:
                if (i + 2 < ROW - 1)
                {
                    maze[i + 1][j] = ' ';
                    maze[i + 2][j] = ' ';
                }
                break;
            // Move left
            case 3:
                if (j - 2 > 0)
                {
                    maze[i][j - 1] = ' ';
                    maze[i][j - 2] = ' ';
                }
                break;
            }
        }
    }
}

void print_maze(char maze[ROW][COL])
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}