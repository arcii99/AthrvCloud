//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 10

int maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
};

int visited[MAZE_HEIGHT][MAZE_WIDTH];
int path[MAZE_HEIGHT][MAZE_WIDTH];
int start_x = 1;
int start_y = 1;
int end_x = MAZE_WIDTH-2;
int end_y = MAZE_HEIGHT-2;
int path_length = 0;

void print_path()
{
    printf("Path:\n");
    for(int i=0;i<MAZE_HEIGHT;i++)
    {
        for(int j=0;j<MAZE_WIDTH;j++)
        {
            if(path[i][j]==1)
                printf("X");
            else if(maze[i][j]==1)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

void find_path(int x, int y)
{
    if(x<0 || x>=MAZE_WIDTH || y<0 || y>=MAZE_HEIGHT)
        return;
    if(visited[y][x]==1)
        return;
    if(maze[y][x]==1)
        return;
    visited[y][x] = 1;
    path[y][x] = 1;
    path_length++;
    if(x==end_x && y==end_y)
    {
        printf("Found path! Length = %d\n",path_length);
        print_path();
        return;
    }
    find_path(x+1,y);
    find_path(x-1,y);
    find_path(x,y+1);
    find_path(x,y-1);
    path_length--;
    path[y][x] = 0;
}

int main()
{
    printf("Starting path finding!\n");
    find_path(start_x,start_y);
    printf("Finished path finding!\n");
    return 0;
}