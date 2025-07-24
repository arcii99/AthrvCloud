//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

void generate_maze(int maze[MAZE_SIZE][MAZE_SIZE], int x, int y);
void display_maze(int maze[MAZE_SIZE][MAZE_SIZE]);

int main()
{
    int maze[MAZE_SIZE][MAZE_SIZE];

    // Seed random number generator
    srand((unsigned int)time(NULL));

    // Generate maze
    generate_maze(maze, 0, 0);

    // Display maze
    display_maze(maze);

    return 0;
}

void generate_maze(int maze[MAZE_SIZE][MAZE_SIZE], int x, int y)
{
    // Base case: out of bounds
    if(x < 0 || y < 0 || x >= MAZE_SIZE || y >= MAZE_SIZE)
    {
        return;
    }

    // Base case: already visited
    if(maze[x][y] != 0)
    {
        return;
    }

    // Mark current cell visited
    maze[x][y] = 1;

    // Shuffle directions
    int directions[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++)
    {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Visit neighboring cells
    for(int i = 0; i < 4; i++)
    {
        int dx = 0, dy = 0;
        switch(directions[i])
        {
            case 0: // Up
                dy = -1;
                break;
            case 1: // Right
                dx = 1;
                break;
            case 2: // Down
                dy = 1;
                break;
            case 3: // Left
                dx = -1;
                break;
        }
        generate_maze(maze, x + dx, y + dy);
    }
}

void display_maze(int maze[MAZE_SIZE][MAZE_SIZE])
{
    printf(" ");
    for(int i = 0; i < MAZE_SIZE * 2 - 1; i++)
    {
        printf("_");
    }
    printf("\n");

    for(int y = 0; y < MAZE_SIZE; y++)
    {
        printf("|");
        for(int x = 0; x < MAZE_SIZE; x++)
        {
            printf("%c", maze[x][y] == 1 ? ' ' : '|');
        }
        printf("\n");
    }
}