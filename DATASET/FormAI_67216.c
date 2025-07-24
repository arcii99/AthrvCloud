//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 21 // Height of the maze
#define WIDTH 51 // Width of the maze

char maze[HEIGHT][WIDTH];

int randomInt(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

void generateMaze()
{
    // Initialize the maze with walls
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
            {
                maze[i][j] = '#'; // Wall
            }
            else
            {
                maze[i][j] = ' '; // Space
            }
        }
    }

    // Randomly generate the maze
    srand(time(NULL));
    int startX = randomInt(1, WIDTH - 2);
    int startY = randomInt(1, HEIGHT - 2);
    maze[startY][startX] = ' '; // Start point

    int movesX[] = {1, 0, -1, 0};
    int movesY[] = {0, 1, 0, -1};
    int moveIndex[] = {0, 1, 2, 3};
    int numMoves = 4;

    while (numMoves > 0)
    {
        // Shuffle the move indices
        for (int i = 0; i < numMoves; i++)
        {
            int j = randomInt(i, numMoves - 1);
            int temp = moveIndex[i];
            moveIndex[i] = moveIndex[j];
            moveIndex[j] = temp;
        }

        // Try each move
        int madeMove = 0;
        for (int i = 0; i < numMoves; i++)
        {
            int newX = startX + movesX[moveIndex[i]];
            int newY = startY + movesY[moveIndex[i]];
            int wallX = startX + (movesX[moveIndex[i]] / 2);
            int wallY = startY + (movesY[moveIndex[i]] / 2);

            if (maze[newY][newX] == '#')
            {
                maze[wallY][wallX] = ' '; // Remove the wall
                maze[newY][newX] = ' '; // Move to the new cell
                startX = newX;
                startY = newY;
                madeMove = 1;
                break;
            }
        }

        if (!madeMove)
        {
            numMoves--;
        }
        else
        {
            numMoves = 4;
        }
    }
}

void printMaze()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    generateMaze();
    printMaze();
    return 0;
}