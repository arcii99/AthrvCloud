//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void print_maze(int maze[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%c ", maze[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

void generate_maze(int maze[HEIGHT][WIDTH], int x, int y)
{
    maze[y][x] = 1;
    int directions[4] = { 0, 1, 2, 3 };
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
    for (int i = 0; i < 4; i++)
    {
        int dx = 0, dy = 0;
        switch (directions[i])
        {
            case 0: dx = -1; break;
            case 1: dx = 1; break;
            case 2: dy = -1; break;
            case 3: dy = 1; break;
        }
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || ny < 0 || nx >= WIDTH || ny >= HEIGHT || maze[ny][nx])
        {
            continue;
        }
        if (dx == -1)
        {
            maze[y][x-1] = 1;
        }
        else if (dx == 1)
        {
            maze[y][x+1] = 1;
        }
        else if (dy == -1)
        {
            maze[y-1][x] = 1;
        }
        else
        {
            maze[y+1][x] = 1;
        }
        generate_maze(maze, nx, ny);
    }
}

int main() 
{
    int maze[HEIGHT][WIDTH] = { {0} };
    generate_maze(maze, 0, 0);
    print_maze(maze);
    return 0;
}