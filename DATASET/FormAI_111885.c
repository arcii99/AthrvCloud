//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 12
#define COLS 18

//Function prototypes
void printMaze(int maze[ROWS][COLS]);
void generateMaze(int maze[ROWS][COLS], int row, int col);

//Main function
int main()
{
    int maze[ROWS][COLS];
    int i, j;

    //Seed the random number generator
    srand(time(NULL));

    //Generate the maze
    generateMaze(maze, 1, 1);

    //Print the maze
    printMaze(maze);

    return 0;
}

//Function to print the maze
void printMaze(int maze[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(maze[i][j] == 0)
                printf("█");
            else
                printf(" ");
        }
        printf("\n");
    }
}

//Function to generate the maze
void generateMaze(int maze[ROWS][COLS], int row, int col)
{
    //Directions: 1 = up, 2 = right, 3 = down, 4 = left
    int directions[4] = {1, 2, 3, 4};
    int temp, index;
    int i;

    //Shuffle the directions
    for(i = 0; i < 4; i++)
    {
        index = rand() % 4;
        temp = directions[i];
        directions[i] = directions[index];
        directions[index] = temp;
    }

    //Check each direction
    for(i = 0; i < 4; i++)
    {
        switch(directions[i])
        {
            case 1: //Up
                if(row - 2 <= 0)
                    continue;
                if(maze[row - 2][col] != 0)
                {
                    maze[row - 2][col] = 0;
                    maze[row - 1][col] = 0;
                    generateMaze(maze, row - 2, col);
                }
                break;

            case 2: //Right
                if(col + 2 >= COLS - 1)
                    continue;
                if(maze[row][col + 2] != 0)
                {
                    maze[row][col + 2] = 0;
                    maze[row][col + 1] = 0;
                    generateMaze(maze, row, col + 2);
                }
                break;

            case 3: //Down
                if(row + 2 >= ROWS - 1)
                    continue;
                if(maze[row + 2][col] != 0)
                {
                    maze[row + 2][col] = 0;
                    maze[row + 1][col] = 0;
                    generateMaze(maze, row + 2, col);
                }
                break;

            case 4: //Left
                if(col - 2 <= 0)
                    continue;
                if(maze[row][col - 2] != 0)
                {
                    maze[row][col - 2] = 0;
                    maze[row][col - 1] = 0;
                    generateMaze(maze, row, col - 2);
                }
                break;
        }
    }
}