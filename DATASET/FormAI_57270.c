//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 10

void generateMaze(int maze[WIDTH][HEIGHT], int startX, int startY);
void printMaze(int maze[WIDTH][HEIGHT]);

int main()
{
    int maze[WIDTH][HEIGHT];
    srand(time(NULL));
    generateMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[WIDTH][HEIGHT], int startX, int startY)
{
    // Initialize maze to all walls
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            maze[i][j] = 1;
        }
    }

    // Recursive depth-first search to carve out maze
    maze[startX][startY] = 0;
    int directions[] = {-1, 0, 1, 0, -1}; // cyclic order of directions
    for (int i = 0; i < 4; i++)
    {
        int direction = rand() % 4;
        int newX = startX + directions[direction];
        int newY = startY + directions[direction + 1];
        if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newX][newY])
        {
            maze[startX + directions[direction] / 2][startY + directions[direction + 1] / 2] = 0;
            generateMaze(maze, newX, newY);
        }
    }
}

void printMaze(int maze[WIDTH][HEIGHT])
{
    for (int i = 0; i < WIDTH * 2 + 1; i++)
    {
        printf("#");
    }
    printf("\n");
    for (int j = 0; j < HEIGHT; j++)
    {
        printf("#");
        for (int i = 0; i < WIDTH; i++)
        {
            printf("%s", maze[i][j] ? "###" : "   ");
            printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH * 2 + 1; i++)
    {
        printf("#");
    }
    printf("\n");
}