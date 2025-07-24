//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generate_maze(int maze[][COLS])
{
    srand(time(NULL));
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1)
            {
                maze[i][j] = 1; // Set border walls as 1
            }
            else
            {
                maze[i][j] = rand() % 2; // Set random walls as 1 or 0
            }
        }
    }
    maze[1][0] = 0; // Entrance
    maze[ROWS-2][COLS-1] = 0; // Exit
}

void print_maze(int maze[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("█"); // Wall
            }
            else
            {
                printf(" "); // Path
            }
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROWS][COLS];

    // Generate maze
    generate_maze(maze);

    // Print maze
    print_maze(maze);

    return 0;
}