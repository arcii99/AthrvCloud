//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 //Width of the maze
#define HEIGHT 10 //Height of the maze

int maze[HEIGHT][WIDTH]; //2D array to hold the maze

void createMaze(int x, int y); //Function to generate the maze

int main()
{
    srand(time(NULL)); //Seed the random number generator

    //Initialize the maze with walls (1) in every position
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            maze[i][j] = 1;
        }
    }

    //Generate the maze starting at position (1,1)
    createMaze(1,1);

    //Print the maze
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("#");
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

void createMaze(int x, int y)
{
    int directions[4][2] = {{0,-1},{0,1},{-1,0},{1,0}}; //Array of directions: left, right, up, down
    int randDir, nextX, nextY;

    //Mark the current position as visited (0)
    maze[y][x] = 0;

    //Randomly shuffle the array of directions
    for(int i = 0; i < 4; i++)
    {
        randDir = rand() % 4;
        int tempX = directions[i][0];
        int tempY = directions[i][1];
        directions[i][0] = directions[randDir][0];
        directions[i][1] = directions[randDir][1];
        directions[randDir][0] = tempX;
        directions[randDir][1] = tempY;
    }

    //For each direction, check if the neighboring cell is unvisited and add a path to it
    for(int i = 0; i < 4; i++)
    {
        nextX = x + directions[i][0] * 2;
        nextY = y + directions[i][1] * 2;

        if(nextX >= 0 && nextX < WIDTH && nextY >= 0 && nextY < HEIGHT && maze[nextY][nextX] == 1)
        {
            maze[y + directions[i][1]][x + directions[i][0]] = 0;
            createMaze(nextX, nextY);
        }
    }
}