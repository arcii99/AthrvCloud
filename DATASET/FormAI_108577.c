//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

/* Function signatures */
int generateRandomNumber(int lower, int upper);
void generateMaze(int maze[][WIDTH], int startX, int startY);

int main()
{
    int maze[HEIGHT][WIDTH];
    int startX = generateRandomNumber(0, WIDTH - 1);
    int startY = generateRandomNumber(0, HEIGHT - 1);

    // Initialize maze with all walls
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            maze[i][j] = 1;
        }
    }

    // Generate maze
    generateMaze(maze, startX, startY);

    // Print maze
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("X");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

/*
 * Function to generate a random number between lower and upper bounds (inclusive).
 */
int generateRandomNumber(int lower, int upper)
{
    srand(time(NULL));
    return rand() % (upper - lower + 1) + lower;
}

/*
 * Function to recursively generate the maze.
 */
void generateMaze(int maze[][WIDTH], int x, int y)
{
    // Set current cell to visited
    maze[y][x] = 0;

    // Generate random directions
    int directions[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++)
    {
        int randomIndex = generateRandomNumber(0, 3);
        int temp = directions[i];
        directions[i] = directions[randomIndex];
        directions[randomIndex] = temp;
    }

    // Visit neighboring cells
    for(int i = 0; i < 4; i++)
    {
        int direction = directions[i];
        switch(direction)
        {
            case 0: // Move up
                if(y > 0 && maze[y - 1][x] == 1)
                {
                    maze[y - 1][x] = 0;
                    generateMaze(maze, x, y - 1);
                }
                break;
            case 1: // Move right
                if(x < WIDTH - 1 && maze[y][x + 1] == 1)
                {
                    maze[y][x + 1] = 0;
                    generateMaze(maze, x + 1, y);
                }
                break;
            case 2: // Move down
                if(y < HEIGHT - 1 && maze[y + 1][x] == 1)
                {
                    maze[y + 1][x] = 0;
                    generateMaze(maze, x, y + 1);
                }
                break;
            case 3: // Move left
                if(x > 0 && maze[y][x - 1] == 1)
                {
                    maze[y][x - 1] = 0;
                    generateMaze(maze, x - 1, y);
                }
                break;
            default:
                break;
        }
    }
}