//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 21
#define COLS 41

void generateMaze(int maze[ROWS][COLS], int startRow, int startCol);
void printMaze(int maze[ROWS][COLS]);

int main()
{
    int maze[ROWS][COLS];
    int startRow, startCol;

    srand(time(NULL)); // seed the random number generator

    startRow = rand() % (ROWS - 2) + 1; // generate a random start row for the maze
    startCol = rand() % (COLS - 2) + 1; // generate a random start column for the maze

    generateMaze(maze, startRow, startCol);

    printMaze(maze);

    return 0;
}

void generateMaze(int maze[ROWS][COLS], int startRow, int startCol)
{
    int i, j, direction;
    bool visited[ROWS][COLS] = { false };

    // initialize the maze with all walls
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(i % 2 == 1 && j % 2 == 1)
            {
                maze[i][j] = 0; // set the floor
            }
            else
            {
                maze[i][j] = 1; // set the wall
            }
        }
    }

    visited[startRow][startCol] = true; // mark the starting cell as visited

    // generate the maze using the depth-first search algorithm with randomization
    while(true)
    {
        // check if all cells have been visited
        bool allVisited = true;
        for(i = 0; i < ROWS; i++)
        {
            for(j = 0; j < COLS; j++)
            {
                if(!visited[i][j])
                {
                    allVisited = false;
                    break;
                }
            }
        }

        if(allVisited)
        {
            break;
        }

        // randomly select a direction to move in
        direction = rand() % 4;

        switch(direction)
        {
            case 0: // move up
                if(startRow > 1 && !visited[startRow - 2][startCol])
                {
                    maze[startRow - 1][startCol] = 0; // remove the wall
                    visited[startRow - 2][startCol] = true; // mark the new cell as visited
                    generateMaze(maze, startRow - 2, startCol); // recurse on the new cell
                }
                break;
            case 1: // move down
                if(startRow < ROWS - 2 && !visited[startRow + 2][startCol])
                {
                    maze[startRow + 1][startCol] = 0; // remove the wall
                    visited[startRow + 2][startCol] = true; // mark the new cell as visited
                    generateMaze(maze, startRow + 2, startCol); // recurse on the new cell
                }
                break;
            case 2: // move left
                if(startCol > 1 && !visited[startRow][startCol - 2])
                {
                    maze[startRow][startCol - 1] = 0; // remove the wall
                    visited[startRow][startCol - 2] = true; // mark the new cell as visited
                    generateMaze(maze, startRow, startCol - 2); // recurse on the new cell
                }
                break;
            case 3: // move right
                if(startCol < COLS - 2 && !visited[startRow][startCol + 2])
                {
                    maze[startRow][startCol + 1] = 0; // remove the wall
                    visited[startRow][startCol + 2] = true; // mark the new cell as visited
                    generateMaze(maze, startRow, startCol + 2); // recurse on the new cell
                }
                break;
        }
    }

    maze[startRow][startCol] = 2; // set the start cell
}

void printMaze(int maze[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            switch(maze[i][j])
            {
                case 0: // floor
                    printf(" ");
                    break;
                case 1: // wall
                    printf("#");
                    break;
                case 2: // start
                    printf("S");
                    break;
            }
        }
        printf("\n");
    }
}