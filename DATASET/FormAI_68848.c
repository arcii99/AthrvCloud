//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(char maze[ROWS][COLS]); // function to generate the maze
void printMaze(char maze[ROWS][COLS]); // function to print the maze

int main()
{
    srand(time(NULL)); // seed the random number generator

    char maze[ROWS][COLS]; // declare the maze

    generateMaze(maze); // call the function to generate the maze
    printMaze(maze); // call the function to print the maze

    return 0;
}

void generateMaze(char maze[ROWS][COLS])
{
    // set all the cells in the maze to walls (represented by '#')
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            maze[i][j] = '#';
        }
    }

    // select a random starting cell
    int startX = rand() % ROWS;
    int startY = rand() % COLS;

    // set the starting cell to a path (represented by ' ')
    maze[startX][startY] = ' ';

    // loop until every cell has been visited
    while(1)
    {
        int visitedCells = 1; // the starting cell has already been visited

        // loop through every cell in the maze
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(maze[i][j] == ' ')
                {
                    // check if the cell has any neighboring walls
                    if((i > 0 && maze[i-1][j] == '#') ||
                       (i < ROWS-1 && maze[i+1][j] == '#') ||
                       (j > 0 && maze[i][j-1] == '#') ||
                       (j < COLS-1 && maze[i][j+1] == '#'))
                    {
                        // select a random neighboring wall
                        int direction;
                        do
                        {
                            direction = rand() % 4;
                        } while((direction == 0 && i == 0) ||
                                (direction == 1 && i == ROWS-1) ||
                                (direction == 2 && j == 0) ||
                                (direction == 3 && j == COLS-1) ||
                                (direction == 0 && maze[i-1][j] != '#') ||
                                (direction == 1 && maze[i+1][j] != '#') ||
                                (direction == 2 && maze[i][j-1] != '#') ||
                                (direction == 3 && maze[i][j+1] != '#'));

                        // carve a path through the wall
                        switch(direction)
                        {
                            case 0: // up
                                maze[i-1][j] = ' ';
                                break;
                            case 1: // down
                                maze[i+1][j] = ' ';
                                break;
                            case 2: // left
                                maze[i][j-1] = ' ';
                                break;
                            case 3: // right
                                maze[i][j+1] = ' ';
                                break;
                        }

                        visitedCells = 0; // at least one new cell has been visited
                    }
                }
            }
        }

        if(visitedCells) // every cell has been visited
        {
            break;
        }
    }
}

void printMaze(char maze[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}