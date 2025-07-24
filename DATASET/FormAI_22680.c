//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 15
#define COL_SIZE 15

//function prototypes
void initializeMaze(int maze[][COL_SIZE]);
void generateMaze(int maze[][COL_SIZE], int row, int col);
void printMaze(int maze[][COL_SIZE]);

int main()
{
    int maze[ROW_SIZE][COL_SIZE];
    initializeMaze(maze);
    printf("Initialized maze:\n");
    printMaze(maze);
    printf("\nGenerating maze:\n");
    generateMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}

//function definitions

//function to initialize maze to all 1's
void initializeMaze(int maze[][COL_SIZE])
{
    int i, j;
    for(i = 0; i < ROW_SIZE; i++)
    {
        for(j = 0; j < COL_SIZE; j++)
        {
            maze[i][j] = 1;
        }
    }
}

//function to generate maze recursively
void generateMaze(int maze[][COL_SIZE], int row, int col)
{
    //initialize random seed
    srand(time(NULL));
    
    //mark current block as 0 to indicate visited
    maze[row][col] = 0;
    
    //array to keep track of unvisited neighbors
    int unvisited[4] = {0, 1, 2, 3};
    int unvisited_size = 4;
    
    //randomize the order in which we visit neighbors
    for(int i = 0; i < 4; i++)
    {
        int j = rand() % (4-i) + i;
        int tmp = unvisited[i];
        unvisited[i] = unvisited[j];
        unvisited[j] = tmp;
    }
    
    //visit each unvisited neighbor
    for(int i = 0; i < unvisited_size; i++)
    {
        int direction = unvisited[i];
        switch(direction)
        {
            case 0: //north
                if(row > 0 && maze[row-1][col])
                {
                    //mark wall as 0 and recurse
                    maze[row-1][col+1] = 0;
                    generateMaze(maze, row-1, col);
                }
                break;
            case 1: //south
                if(row < ROW_SIZE-1 && maze[row+1][col])
                {
                    //mark wall as 0 and recurse
                    maze[row+1][col] = 0;
                    generateMaze(maze, row+1, col);
                }
                break;
            case 2: //east
                if(col < COL_SIZE-1 && maze[row][col+1])
                {
                    //mark wall as 0 and recurse
                    maze[row+1][col+1] = 0;
                    generateMaze(maze, row, col+1);
                }
                break;
            case 3: //west
                if(col > 0 && maze[row][col-1])
                {
                    //mark wall as 0 and recurse
                    maze[row+1][col-1] = 0;
                    generateMaze(maze, row, col-1);
                }
                break;
        }
    }
}

//function to print maze
void printMaze(int maze[][COL_SIZE])
{
    int i, j;
    for(i = 0; i < ROW_SIZE; i++)
    {
        for(j = 0; j < COL_SIZE; j++)
        {
            if(maze[i][j])
            {
                printf("# ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}