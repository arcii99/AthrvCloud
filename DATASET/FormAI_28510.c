//FormAI DATASET v1.0 Category: Funny ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

void generate_maze(int maze[][COLS], int row, int col);
void display_maze(int maze[][COLS], int row, int col);
void navigate_maze(int maze[][COLS], int row, int col);

int main()
{
    int maze[ROWS][COLS];
    generate_maze(maze, ROWS, COLS);
    display_maze(maze, ROWS, COLS);
    navigate_maze(maze, ROWS, COLS);
    return 0;
}

void generate_maze(int maze[][COLS], int row, int col)
{
    srand(time(NULL));
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i == 0 || i == row-1 || j == 0 || j == col-1)
            {
                maze[i][j] = 1;
            }
            else if(rand()%2 == 0)
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = 0;
            }
        }
    }
}

void display_maze(int maze[][COLS], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("██");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void navigate_maze(int maze[][COLS], int row, int col)
{
    int x = 1, y = 1;
    maze[x][y] = 2;
    display_maze(maze, row, col);
    
    while(x != row-2 || y != col-2)
    {
        switch(getchar())
        {
            case 'w':
                if(maze[x-1][y] == 0)
                {
                    maze[x][y] = 0;
                    x--;
                    maze[x][y] = 2;
                }
                break;
            case 'a':
                if(maze[x][y-1] == 0)
                {
                    maze[x][y] = 0;
                    y--;
                    maze[x][y] = 2;
                }
                break;
            case 's':
                if(maze[x+1][y] == 0)
                {
                    maze[x][y] = 0;
                    x++;
                    maze[x][y] = 2;
                }
                break;
            case 'd':
                if(maze[x][y+1] == 0)
                {
                    maze[x][y] = 0;
                    y++;
                    maze[x][y] = 2;
                }
                break;
        }
        system("clear");
        display_maze(maze, row, col);
    }
    printf("\nCongratulations! You found the exit!\n");
}