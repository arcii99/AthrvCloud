//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#define ROWS 5
#define COLS 7

int maze[ROWS][COLS] = {
	{1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
	{1, 1, 1, 0, 1, 1, 1}    
};

int solve_maze(int x, int y)
{
    if(x<0 || x>=ROWS || y<0 || y>=COLS)
        return 0;
    else if(maze[x][y] == 0)
        return 0;
    else if(maze[x][y] == 2)
        return 0;
    else if(x == ROWS-1 && y == COLS-1)
    {
        maze[x][y] = 2;
        return 1;
    }
    else
    {
        maze[x][y] = 2;
        if(solve_maze(x-1, y) == 1)
            return 1;
        else if(solve_maze(x+1, y) == 1)
            return 1;
        else if(solve_maze(x, y-1) == 1)
            return 1;
        else if(solve_maze(x, y+1) == 1)
            return 1;
        else
        {
            maze[x][y] = 0;
            return 0;
        }
    }
}

void print_maze()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Maze before solving:\n");
    print_maze();
    printf("\n");

    int start_x = 0;
    int start_y = 0;

    if(solve_maze(start_x, start_y) == 1)
    {
        printf("Maze solution path:\n");
        print_maze();
    }
    else
    {
        printf("No path found.");
    }

    return 0;
}