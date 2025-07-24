//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 15
#define COLS 20

//Function prototypes
void generateMaze(int maze[][COLS], int row, int col);
void printMaze(int maze[][COLS]);

int main(void)
{
    int maze[ROWS][COLS];
    srand(time(NULL)); //Random seed
    generateMaze(maze, 0, 0); //Start generating maze from top-left cell
    printMaze(maze); //Print the generated maze
    return 0;
}

void generateMaze(int maze[][COLS], int row, int col)
{
    //Mark the current cell
    maze[row][col] = 1;
    
    //Make an array of directions
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int temp, newRow, newCol;
    
    //Randomly shuffle the directions array
    for(int i = 0; i < 4; i++)
    {
        int r = rand() % 4;
        temp = directions[i][0];
        directions[i][0] = directions[r][0];
        directions[r][0] = temp;
        
        temp = directions[i][1];
        directions[i][1] = directions[r][1];
        directions[r][1] = temp;
    }
    
    //Recursive calls for each direction
    for(int i = 0; i < 4; i++)
    {
        newRow = row + directions[i][0];
        newCol = col + directions[i][1];
        
        if((newRow >= 0 && newRow < ROWS) && (newCol >= 0 && newCol < COLS) && maze[newRow][newCol] == 0)
        {
            if(directions[i][0] == 1) //Down
            {
                maze[row+1][col] = 1;
            }
            else if(directions[i][0] == -1) //Up
            {
                maze[row-1][col] = 1;
            }
            else if(directions[i][1] == 1) //Right
            {
                maze[row][col+1] = 1;
            }
            else if(directions[i][1] == -1) //Left
            {
                maze[row][col-1] = 1;
            }
            generateMaze(maze, newRow, newCol);
        }
    }
}

void printMaze(int maze[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(maze[i][j] == 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}