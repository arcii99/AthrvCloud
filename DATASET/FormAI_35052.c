//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 21
#define MAZE_HEIGHT 21

#define WALL 0
#define PATH 1
#define VISITED 2

int maze[MAZE_HEIGHT][MAZE_WIDTH];

void generateMaze(int row, int col);
void printMaze();
int isWall(int row, int col);
int isValid(int row, int col);
void shuffle(int *array, int n);

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator

    // Set all cells to be walls
    for(int r=0; r<MAZE_HEIGHT; r++)
    {
        for(int c=0; c<MAZE_WIDTH; c++)
        {
            maze[r][c] = WALL;
        }
    }

    // Generate the maze starting from the top left corner
    generateMaze(0, 0);

    // Print the maze
    printMaze();

    return 0;
}

void generateMaze(int row, int col)
{
    // Set the current cell to be a path
    maze[row][col] = PATH;

    // Create an array of shuffled directions
    int directions[4] = {0, 1, 2, 3};
    shuffle(directions, 4);

    // Iterate through each direction
    for(int i=0; i<4; i++)
    {
        int dir = directions[i];

        // Check if the adjacent cell in that direction is valid and a wall
        if(dir == 0 && isValid(row-1, col) && isWall(row-1, col))
        {
            // Set the wall to be a path
            maze[row-1][col] = PATH;

            // Recursive call to generate from the adjacent cell
            generateMaze(row-2, col);
        }
        else if(dir == 1 && isValid(row, col+1) && isWall(row, col+1))
        {
            maze[row][col+1] = PATH;
            generateMaze(row, col+2);
        }
        else if(dir == 2 && isValid(row+1, col) && isWall(row+1, col))
        {
            maze[row+1][col] = PATH;
            generateMaze(row+2, col);
        }
        else if(dir == 3 && isValid(row, col-1) && isWall(row, col-1))
        {
            maze[row][col-1] = PATH;
            generateMaze(row, col-2);
        }
    }
}

void printMaze()
{
    for(int r=0; r<MAZE_HEIGHT; r++)
    {
        for(int c=0; c<MAZE_WIDTH; c++)
        {
            // Print a wall if the cell is a wall, a space if the cell is open, and an X if the cell has been visited but is not part of the solution
            if(maze[r][c] == WALL)
            {
                printf("#");
            }
            else if(maze[r][c] == PATH)
            {
                printf(" ");
            }
            else if(maze[r][c] == VISITED)
            {
                printf("X");
            }
        }
        printf("\n");
    }
}

int isWall(int row, int col)
{
    return (maze[row][col] == WALL);
}

int isValid(int row, int col)
{
    // Check if the cell is within the bounds of the maze
    return (row >= 0 && col >= 0 && row < MAZE_HEIGHT && col < MAZE_WIDTH);
}

void shuffle(int *array, int n)
{
    if(n > 1)
    {
        int i;
        for(i=0; i<n-1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}